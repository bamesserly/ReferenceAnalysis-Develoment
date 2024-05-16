/* taken from A. Edmonds */
#ifndef ROODSCB
#define ROODSCB

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

#include "TMath.h" 

namespace rootfitter{
class RooDSCB : public RooAbsPdf {
  public:
    RooDSCB() {} ; 
    RooDSCB(const char *name, const char *title,
	         RooAbsReal& _x,
	         RooAbsReal& _mean,
	         RooAbsReal& _sigma,
	         RooAbsReal& _ANeg,
	         RooAbsReal& _PNeg,
	         RooAbsReal& _APos,
	    RooAbsReal& _PPos) :

     RooAbsPdf(name,title), 
     x("x","x",this,_x),
     mean("mean","mean",this,_mean),
     sigma("sigma","sigma",this,_sigma),
     ANeg("ANeg","ANeg",this,_ANeg),
     PNeg("PNeg","PNeg",this,_PNeg),
     APos("APos","APos",this,_APos),
     PPos("PPos","PPos",this,_PPos)
    { }

    RooDSCB(const RooDSCB& other, const char* name=0) :
     RooAbsPdf(other,name), 
     x("x",this,other.x),
     mean("mean",this,other.mean),
     sigma("sigma",this,other.sigma),
     ANeg("ANeg",this,other.ANeg),
     PNeg("PNeg",this,other.PNeg),
     APos("APos",this,other.APos),
     PPos("PPos",this,other.PPos)
    { }

    virtual TObject* clone(const char* newname) const { return new RooDSCB(*this,newname); }
    inline virtual ~RooDSCB() { }

    //  Double_t expectedEvents(const RooArgSet* nset) const;

  protected:

    RooRealProxy x ;
    RooRealProxy mean ;
    RooRealProxy sigma ;
    RooRealProxy ANeg ;
    RooRealProxy PNeg ;
    RooRealProxy APos ;
    RooRealProxy PPos ;
    
    Double_t evaluate() const {
      double u   = (x-mean)/sigma;
      double A1  = TMath::Power(PNeg/TMath::Abs(ANeg),PNeg)*TMath::Exp(-ANeg*ANeg/2);
      double A2  = TMath::Power(PPos/TMath::Abs(APos),PPos)*TMath::Exp(-APos*APos/2);
      double B1  = PNeg/TMath::Abs(ANeg) - TMath::Abs(ANeg);
      double B2  = PPos/TMath::Abs(APos) - TMath::Abs(APos);

      double result = 0;
      if      (u<-ANeg) result = A1*TMath::Power(B1-u,-PNeg);
      else if (u<APos)  result = TMath::Exp(-u*u/2);
      else            result = A2*TMath::Power(B2+u,-PPos);
      return result;
    }

  private:

    ClassDef(RooDSCB,1) // Your description goes here...
  };
}
#endif
