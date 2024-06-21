#include <iostream>

#include "CVUniverse.h"

// Lateral universe
class TrackHitCalibrationUniverse : public CVUniverse {
 public:
  TrackHitCalibrationUniverse(PlotUtils::ChainWrapper* chw, double nsigma)
      : CVUniverse(chw, nsigma) {}

  virtual int get_n_track_hits() const override {
    return CVUniverse::get_n_track_hits() + m_nsigma*1; 
  }

  virtual std::string ShortName() const override { return "TrackHitCalibration"; }
  virtual std::string LatexName() const override {
    return "Track N Hits Calibration";
  }
};

// Vertical universe
class ModelXUniverse : public CVUniverse {
 public:
  ModelXUniverse(PlotUtils::ChainWrapper* chw, double nsigma)
      : CVUniverse(chw, nsigma) {}

  virtual double GetWeight() const override {
    double parameter_tolerance = 0.08;
    return CVUniverse::GetWeight() * (1 + m_nsigma*parameter_tolerance);
  }

  virtual std::string ShortName() const override { return "ModelXUniverse"; }
  virtual std::string LatexName() const override {
    return "Model X";
  }
};
