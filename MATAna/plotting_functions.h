#ifndef plotting_functions_H
#define plotting_functions_H
#include <iostream>

#include "PlotUtils/HistogramUtils.h"
#include "PlotUtils/MnvH1D.h"
#include "PlotUtils/MnvPlotter.h"
#include "PlotUtils/MnvVertErrorBand.h"
#include "TCanvas.h"

const double xmin = 0.;
const double xmax = 200;
const int nbins = 100;

const bool do_fractional_uncertainty = true;
const bool do_cov_area_norm = false;
const bool include_stat_error = true;

const std::string do_fractional_uncertainty_str =
    do_fractional_uncertainty ? std::string("Frac") : std::string("Abs");
const std::string do_cov_area_norm_str =
    do_cov_area_norm ? std::string("CovAreaNorm") : std::string("");

void PlotErrorSummary(PlotUtils::MnvH1D* hist, std::string label);
void PlotVertBand(std::string band, std::string method_str,
                  PlotUtils::MnvH1D* hist);
void PlotLatBand(std::string band, std::string method_str,
                 PlotUtils::MnvH1D* hist);
void PlotVertUniverse(std::string band, unsigned int universe,
                      std::string method_str, PlotUtils::MnvH1D* hist);
void PlotLatUniverse(std::string band, unsigned int universe,
                     std::string method_str, PlotUtils::MnvH1D* hist);
void PlotCVAndError(PlotUtils::MnvH1D* hist, std::string label);
void PlotTotalError(PlotUtils::MnvH1D* hist, std::string method_str);

void PlotTotalError(PlotUtils::MnvH1D* hist, std::string method_str) {
  TH1D* hTotalErr =
      (TH1D*)hist
          ->GetTotalError(include_stat_error, do_fractional_uncertainty,
                          do_cov_area_norm)
          .Clone(Form("h_total_err_errSum_%d", __LINE__));
  TCanvas cF("c4", "c4");
  hTotalErr->SetTitle(
      Form("Total Uncertainty (%s); n track hits", method_str.c_str()));
  hTotalErr->Draw();
  cF.Print(Form("ntrackhits_TotalUncertainty_%s_%s_%s.png",
                do_fractional_uncertainty_str.c_str(),
                do_cov_area_norm_str.c_str(), method_str.c_str()));
}

void PlotErrorSummary(PlotUtils::MnvH1D* hist, std::string label) {
  PlotUtils::MnvPlotter mnvPlotter(PlotUtils::kCCNuPionIncStyle);
  TCanvas cE("c1", "c1");
  hist->GetXaxis()->SetTitle(label.c_str());

  mnvPlotter.error_summary_group_map.clear();
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrAbs_N");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrAbs_pi");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrCEx_N");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrCEx_pi");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrElas_N");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrElas_pi");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrInel_N");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrInel_pi");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_FrPiProd_N");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back(
      "genie_FrPiProd_pi");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_MFP_N");
  mnvPlotter.error_summary_group_map["Genie_FSI"].push_back("genie_MFP_pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_AGKYxF1pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_AhtBY");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_BhtBY");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_CCQEPauliSupViaKF");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_CV1uBY");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_CV2uBY");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_EtaNCEL");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_MaCCQE");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_MaCCQEshape");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_MaNCEL");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_MaRES");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_MvRES");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_NormCCQE");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_NormCCRES");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_NormDISCC");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_NormNCRES");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_RDecBR1gamma");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_Rvn1pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_Rvn2pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_Rvn3pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_Rvp1pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_Rvp2pi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_Theta_Delta2Npi");
  mnvPlotter.error_summary_group_map["Genie_InteractionModel"].push_back(
      "genie_VecFFCCQEshape");

  mnvPlotter.DrawErrorSummary(hist, "TR", include_stat_error, true, 0.0,
                              do_cov_area_norm, "", do_fractional_uncertainty);
  std::string plotname =
      Form("ntrackhits_ErrorSummary_%s_%s_%s", do_fractional_uncertainty_str.c_str(),
           do_cov_area_norm_str.c_str(), label.c_str());
  mnvPlotter.MultiPrint(&cE, plotname, "png");
}

void PlotVertBand(std::string band, std::string method_str,
                  PlotUtils::MnvH1D* hist) {
  TH1* h1 = (TH1*)hist->GetVertErrorBand(band.c_str())
                ->GetErrorBand(do_fractional_uncertainty, do_cov_area_norm)
                .Clone(Form("Enu_%s_%s", band.c_str(), method_str.c_str()));
  // TH1* h1 = (TH1*)hist->GetVertErrorBand(band.c_str());
  TCanvas cF("c4", "c4");
  h1->SetTitle(Form("%s Uncertainty (%s); E_{#nu} (MeV)", band.c_str(),
                    method_str.c_str()));
  h1->Draw("h");
  cF.Print(Form("Enu_%s_band_%s.png", band.c_str(), method_str.c_str()));
}

void PlotLatBand(std::string band, std::string method_str,
                 PlotUtils::MnvH1D* hist) {
  TH1* h1 = (TH1*)hist->GetLatErrorBand(band.c_str())
                ->GetErrorBand(do_fractional_uncertainty, do_cov_area_norm)
                .Clone(Form("Enu_%s_%s", band.c_str(), method_str.c_str()));
  // TH1* h1 = (TH1*)hist->GetLatErrorBand(band.c_str());
  TCanvas cF("c1", "c1");
  h1->SetTitle(Form("%s Uncertainty (%s); E_{#nu} (MeV)", band.c_str(),
                    method_str.c_str()));
  h1->Draw("h");
  cF.Print(Form("Enu_%s_band_%s.png", band.c_str(), method_str.c_str()));
}

void PlotVertUniverse(std::string band, unsigned int universe,
                      std::string method_str, PlotUtils::MnvH1D* hist) {
  TH1D* h1 = hist->GetVertErrorBand(band.c_str())->GetHist(universe);

  TCanvas cF("c1", "c1");
  h1->SetLineColor(kBlack);
  h1->SetLineStyle(1);
  h1->Draw("hist");
  cF.Print(Form("Enu_%s_band_universe%i_%s.png", band.c_str(), universe + 1,
                method_str.c_str()));
}

void PlotLatUniverse(std::string band, unsigned int universe,
                     std::string method_str, PlotUtils::MnvH1D* hist) {
  TH1D* h1 = hist->GetLatErrorBand(band.c_str())->GetHist(universe);
  TCanvas cF("c1", "c1");
  h1->SetLineColor(kBlack);
  h1->SetLineStyle(1);
  h1->Draw("hist");
  cF.Print(Form("Enu_%s_band_universe%i_%s.png", band.c_str(), universe + 1,
                method_str.c_str()));
}

void PlotCVAndError(PlotUtils::MnvH1D* hist, std::string label) {
  PlotUtils::MnvPlotter mnvPlotter(PlotUtils::kCCNuPionIncStyle);
  TCanvas cE("c1", "c1");
  hist->GetXaxis()->SetTitle(Form("%s; n track hits", label.c_str()));
  PlotUtils::MnvH1D* datahist =
      new PlotUtils::MnvH1D("adsf", "n track hits", nbins, xmin, xmax);
  bool statPlusSys = true;
  int mcScale = 1.;
  bool useHistTitles = false;
  const PlotUtils::MnvH1D* bkgdHist = NULL;
  const PlotUtils::MnvH1D* dataBkgdHist = NULL;
  mnvPlotter.DrawDataMCWithErrorBand(datahist, hist, mcScale, "TL",
                                     useHistTitles, NULL, NULL, false,
                                     statPlusSys);
  // mnvPlotter.DrawMCWithErrorBand(hist); //I think that this call only shows
  // stat errors.
  std::string plotname = Form("ntrackhits_CV_w_err_%s", label.c_str());
  mnvPlotter.MultiPrint(&cE, plotname, "png");
}

#endif
