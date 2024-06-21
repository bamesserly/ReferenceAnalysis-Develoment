// ========================================================================
// Base class for an un-systematically shifted (i.e. CV) universe.  Implement
// your own base class with the functions you need. I've implemented GetEnu(),
// GetMuonE() and GetHadronE() as examples: you'll have other variables you
// want.
//
// To add a systematic, inherit from this class and override whichever
// functions you need to. For a "vertical" error, this will mean overriding the
// GetWeight() function to modify the event weight. For a "lateral" error, this
// will mean overriding the function that calculates the quantity that is being
// shifted (muon energy, or hadronic energy or whatever).
//
// For examples of each of those two cases, see ./LateralSystematics.h and
// PlotUtils/GenieSystematics.h. For an example of how to put the whole thing
// together and actually *use* the classes, see the runEventLoop.C macro in
// this directory. `root -l -b load.C+ runEventLoop.C+`
// ========================================================================
#ifndef CVUNIVERSE_H
#define CVUNIVERSE_H

#include <iostream>

#include "PlotUtils/ChainWrapper.h"
#include "PlotUtils/BaseUniverse.h"

class CVUniverse : public PlotUtils::BaseUniverse {
 public:
  // Constructor
  CVUniverse(PlotUtils::ChainWrapper* chw, double nsigma = 0)
      : PlotUtils::BaseUniverse(chw, nsigma) {}

  // Destructor
  virtual ~CVUniverse() {}

  // All functions we write here should be 'virtual', so that the universes
  // that inherit from CVUniverse can override them.

  // ========================================================================
  // Get Weight
  //
  // We override the various weight getting functions herein in different
  // vertical systematic universe classes.
  // ========================================================================
  virtual double GetWeight() const {
    return 1;
  }

  // ========================================================================
  // Get Variable Functions
  // Write a virtual "Get" function for _any_ variable (coming directly from a
  // branch, or composed of several branches) that will be laterally shifted
  // or affected by the lateral shift of a systematic universe.
  //
  // We override some or all of these function in different systematic
  // universe classes located in LateralSystematics.h.
  // ========================================================================
  virtual int get_n_track_hits() const { return GetInt("demmc.nhits"); }
  virtual double get_det0() const { return GetDouble("de.t0"); } // OLD
  virtual double get_deenttd() const { return GetDouble("deent.td"); }
  virtual double get_deentd0() const { return GetDouble("deent.d0"); }
  virtual double get_detrkqual() const { return GetDouble("dequal.TrkQual"); }

  // New TrkAna cut vars
  virtual double get_dem_mom() const { return GetDouble("demfit_mom0"); }
  virtual double get_signal_window_time() const { return GetDouble("demfit_t0"); }
  virtual double get_max_radius() const { return GetDouble("demlh_maxr0"); }
  virtual double get_track_qual() const { return GetDouble("demtrkqual_result"); }
  virtual double get_n_hits() const { return GetInt("dem.nactive"); }

    //branches['ntrk'] = [len(p) for p in branches['demfit']['sid']]
    //branches = apply_cuts(branches, {'ntrk' : 1})
    //branches = branches[branches['ntrk_cut']]



  /*
    # only looking at events with one reconstructed track
    
    # reconstructed track momentum (start, middle, end of tracker)
    branches['demfit_mom'] = np.sqrt((branches['demfit']['mom']['fCoordinates']['fX'])**2 +
                                 (branches['demfit']['mom']['fCoordinates']['fY'])**2 + 
                                 (branches['demfit']['mom']['fCoordinates']['fZ'])**2)
    # reconstructed momentum at start of tracker
    branches['demfit_mom0'] = branches['demfit_mom'][branches['demfit','sid']==0]
    # time from demfit at start of tracker
    branches['demfit_t0'] = branches['demfit','time'][branches['demfit','sid']==0]
    # maximum radius from demlh at start of tracker
    branches['demlh_maxr0'] = branches['demlh','maxr'][branches['demfit','sid']==0]
    # track quality # find a way to rename in place
    branches['demtrkqual_result'] = branches['result'] 

    # first process for each event is CE or DIO in this data sample
    branches['mcproc1'] = branches['demmcsim','startCode'][:,0,0]
  */




};

#endif
