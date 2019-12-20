#include <iostream>
#include "Riostream.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include "TTree.h"
#include "TBranch.h"
#include "TFrame.h"
#include "TCanvas.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH1.h"
#include "TF1.h"
#include "TLorentzVector.h"
#include "math.h"
#include "time.h"
#include "TRandom.h"
#include "TSpectrum.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include <algorithm>

using namespace std;

TString IntToStr(int n){

    stringstream result;
    result << n;
    return result.str();
}

void pause(int sec){

TTimer t(sec*1000, kFALSE);

while (!t.CheckTimer(gSystem->Now()))
gSystem->Sleep(100); // 100 ms sleep

}

void plotScurve_utils(){

  TString GEBinfo = "GE21-M5-P1";
  TString armDAC = "ARM_DAC_THR_";
  TString armDACval = "30";
  TString function;

  const Int_t thrMin = 30;
  const Int_t thrMax = 150;
  const Int_t step = 10;
  const Int_t binThr = ((thrMax - thrMin)/10) + 1;

  cout << "********************************************************" << endl;
  cout << "**                    OPENING FILE                    **" << endl;
  cout << "********************************************************" << endl;

  TFile *file_30 = new TFile("SCurveFitData_30.root", "read");
  if (file_30->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TH2F *distHist_30 = new TH2F();
  TDirectory* dir_30 = gFile->GetDirectory("Summary;1");
  dir_30->GetObject("ScurveSigma_All;1",distHist_30);

  TFile *file_40 = new TFile("SCurveFitData_40.root", "read");
  if (file_40->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  file_40->cd();
  TH2F *distHist_40 = new TH2F();
  TDirectory* dir_40 = gFile->GetDirectory("Summary;1");
  dir_40->GetObject("ScurveSigma_All;1",distHist_40);

  TFile *file_50 = new TFile("SCurveFitData_50.root", "read");
  if (file_50->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_60 = new TFile("SCurveFitData_60.root", "read");
  if (file_60->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_70 = new TFile("SCurveFitData_70.root", "read");
  if (file_70->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_80 = new TFile("SCurveFitData_80.root", "read");
  if (file_80->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_90 = new TFile("SCurveFitData_90.root", "read");
  if (file_90->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_100 = new TFile("SCurveFitData_100.root", "read");
  if (file_100->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_110 = new TFile("SCurveFitData_110.root", "read");
  if (file_110->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_120 = new TFile("SCurveFitData_120.root", "read");
  if (file_120->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_130 = new TFile("SCurveFitData_130.root", "read");
  if (file_130->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_140 = new TFile("SCurveFitData_140.root", "read");
  if (file_140->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }
  TFile *file_150 = new TFile("SCurveFitData_150.root", "read");
  if (file_150->IsOpen()){
    cout << "File opened successfully..." << endl;
    cout << "                           " << endl;
  }

  cout << "All files opened successfully" << endl;

  
  //Swith to second file
  file_50->cd();
  TH2F *distHist_50 = new TH2F();
  TDirectory* dir_50 = gFile->GetDirectory("Summary;1");
  dir_50->GetObject("ScurveSigma_All;1",distHist_50);

  file_60->cd();
  TH2F *distHist_60 = new TH2F();
  TDirectory* dir_60 = gFile->GetDirectory("Summary;1");
  dir_60->GetObject("ScurveSigma_All;1",distHist_60);

  file_70->cd();
  TH2F *distHist_70 = new TH2F();
  TDirectory* dir_70 = gFile->GetDirectory("Summary;1");
  dir_70->GetObject("ScurveSigma_All;1",distHist_70);

  file_80->cd();
  TH2F *distHist_80 = new TH2F();
  TDirectory* dir_80 = gFile->GetDirectory("Summary;1");
  dir_80->GetObject("ScurveSigma_All;1",distHist_80);

  file_90->cd();
  TH2F *distHist_90 = new TH2F();
  TDirectory* dir_90 = gFile->GetDirectory("Summary;1");
  dir_90->GetObject("ScurveSigma_All;1",distHist_90);

  file_100->cd();
  TH2F *distHist_100 = new TH2F();
  TDirectory* dir_100 = gFile->GetDirectory("Summary;1");
  dir_100->GetObject("ScurveSigma_All;1",distHist_100);

  file_110->cd();
  TH2F *distHist_110 = new TH2F();
  TDirectory* dir_110 = gFile->GetDirectory("Summary;1");
  dir_110->GetObject("ScurveSigma_All;1",distHist_110);

  file_120->cd();
  TH2F *distHist_120 = new TH2F();
  TDirectory* dir_120 = gFile->GetDirectory("Summary;1");
  dir_120->GetObject("ScurveSigma_All;1",distHist_120);

  file_130->cd();
  TH2F *distHist_130 = new TH2F();
  TDirectory* dir_130 = gFile->GetDirectory("Summary;1");
  dir_130->GetObject("ScurveSigma_All;1",distHist_130);

  file_140->cd();
  TH2F *distHist_140 = new TH2F();
  TDirectory* dir_140 = gFile->GetDirectory("Summary;1");
  dir_140->GetObject("ScurveSigma_All;1",distHist_140);

  file_150->cd();
  TH2F *distHist_150 = new TH2F();
  TDirectory* dir_150 = gFile->GetDirectory("Summary;1");
  dir_150->GetObject("ScurveSigma_All;1",distHist_150);

  TCanvas *canv1 = new TCanvas();
  gStyle->SetOptStat("nemr");
  distHist_30->SetStats(1);
  gStyle->SetOptStat("nemr");
  distHist_30->Draw("CANDLE");
  canv1->Update();
  distHist_30->GetXaxis()->SetRangeUser(-0.5,11.5);
  distHist_30->GetYaxis()->SetRangeUser(0.0,5.05);
  distHist_30->Draw("CANDLE");
  const Double_t yMax = gPad->GetUymax();
  //cout << yMax << endl;
  Int_t nEntries = distHist_30->GetEntries();
  const Int_t bins = 12;
  const Int_t yBins = distHist_30->GetNbinsY();

  //Define arrays for storing dist in y bins, 128 for number of channels
  //const Int_t ch = 128;
  const Int_t ch = 128;//distHist->GetNbinsY();
  cout << "yBins " << ch << endl;

  //VFAT0
  Double_t vfat0_30[ch];
  Double_t vfat0_40[ch];
  Double_t vfat0_50[ch];
  Double_t vfat0_60[ch];
  Double_t vfat0_70[ch];
  Double_t vfat0_80[ch];
  Double_t vfat0_90[ch];
  Double_t vfat0_100[ch];
  Double_t vfat0_110[ch];
  Double_t vfat0_120[ch];
  Double_t vfat0_130[ch];
  Double_t vfat0_140[ch];
  Double_t vfat0_150[ch];

  //VFAT1
  Double_t vfat1_30[ch];
  Double_t vfat1_40[ch];
  Double_t vfat1_50[ch];
  Double_t vfat1_60[ch];
  Double_t vfat1_70[ch];
  Double_t vfat1_80[ch];
  Double_t vfat1_90[ch];
  Double_t vfat1_100[ch];
  Double_t vfat1_110[ch];
  Double_t vfat1_120[ch];
  Double_t vfat1_130[ch];
  Double_t vfat1_140[ch];
  Double_t vfat1_150[ch];

  //VFAT2
  Double_t vfat2_30[ch];
  Double_t vfat2_40[ch];
  Double_t vfat2_50[ch];
  Double_t vfat2_60[ch];
  Double_t vfat2_70[ch];
  Double_t vfat2_80[ch];
  Double_t vfat2_90[ch];
  Double_t vfat2_100[ch];
  Double_t vfat2_110[ch];
  Double_t vfat2_120[ch];
  Double_t vfat2_130[ch];
  Double_t vfat2_140[ch];
  Double_t vfat2_150[ch];

  //VFAT3
  Double_t vfat3_30[ch];
  Double_t vfat3_40[ch];
  Double_t vfat3_50[ch];
  Double_t vfat3_60[ch];
  Double_t vfat3_70[ch];
  Double_t vfat3_80[ch];
  Double_t vfat3_90[ch];
  Double_t vfat3_100[ch];
  Double_t vfat3_110[ch];
  Double_t vfat3_120[ch];
  Double_t vfat3_130[ch];
  Double_t vfat3_140[ch];
  Double_t vfat3_150[ch];

  //VFAT4
  Double_t vfat4_30[ch];
  Double_t vfat4_40[ch];
  Double_t vfat4_50[ch];
  Double_t vfat4_60[ch];
  Double_t vfat4_70[ch];
  Double_t vfat4_80[ch];
  Double_t vfat4_90[ch];
  Double_t vfat4_100[ch];
  Double_t vfat4_110[ch];
  Double_t vfat4_120[ch];
  Double_t vfat4_130[ch];
  Double_t vfat4_140[ch];
  Double_t vfat4_150[ch];

  //VFAT5
  Double_t vfat5_30[ch];
  Double_t vfat5_40[ch];
  Double_t vfat5_50[ch];
  Double_t vfat5_60[ch];
  Double_t vfat5_70[ch];
  Double_t vfat5_80[ch];
  Double_t vfat5_90[ch];
  Double_t vfat5_100[ch];
  Double_t vfat5_110[ch];
  Double_t vfat5_120[ch];
  Double_t vfat5_130[ch];
  Double_t vfat5_140[ch];
  Double_t vfat5_150[ch];

  //VFAT6
  Double_t vfat6_30[ch];
  Double_t vfat6_40[ch];
  Double_t vfat6_50[ch];
  Double_t vfat6_60[ch];
  Double_t vfat6_70[ch];
  Double_t vfat6_80[ch];
  Double_t vfat6_90[ch];
  Double_t vfat6_100[ch];
  Double_t vfat6_110[ch];
  Double_t vfat6_120[ch];
  Double_t vfat6_130[ch];
  Double_t vfat6_140[ch];
  Double_t vfat6_150[ch];

  //VFAT7
  Double_t vfat7_30[ch];
  Double_t vfat7_40[ch];
  Double_t vfat7_50[ch];
  Double_t vfat7_60[ch];
  Double_t vfat7_70[ch];
  Double_t vfat7_80[ch];
  Double_t vfat7_90[ch];
  Double_t vfat7_100[ch];
  Double_t vfat7_110[ch];
  Double_t vfat7_120[ch];
  Double_t vfat7_130[ch];
  Double_t vfat7_140[ch];
  Double_t vfat7_150[ch];

  //VFAT8
  Double_t vfat8_30[ch];
  Double_t vfat8_40[ch];
  Double_t vfat8_50[ch];
  Double_t vfat8_60[ch];
  Double_t vfat8_70[ch];
  Double_t vfat8_80[ch];
  Double_t vfat8_90[ch];
  Double_t vfat8_100[ch];
  Double_t vfat8_110[ch];
  Double_t vfat8_120[ch];
  Double_t vfat8_130[ch];
  Double_t vfat8_140[ch];
  Double_t vfat8_150[ch];

  //VFAT9
  Double_t vfat9_30[ch];
  Double_t vfat9_40[ch];
  Double_t vfat9_50[ch];
  Double_t vfat9_60[ch];
  Double_t vfat9_70[ch];
  Double_t vfat9_80[ch];
  Double_t vfat9_90[ch];
  Double_t vfat9_100[ch];
  Double_t vfat9_110[ch];
  Double_t vfat9_120[ch];
  Double_t vfat9_130[ch];
  Double_t vfat9_140[ch];
  Double_t vfat9_150[ch];

  //VFAT10
  Double_t vfat10_30[ch];
  Double_t vfat10_40[ch];
  Double_t vfat10_50[ch];
  Double_t vfat10_60[ch];
  Double_t vfat10_70[ch];
  Double_t vfat10_80[ch];
  Double_t vfat10_90[ch];
  Double_t vfat10_100[ch];
  Double_t vfat10_110[ch];
  Double_t vfat10_120[ch];
  Double_t vfat10_130[ch];
  Double_t vfat10_140[ch];
  Double_t vfat10_150[ch];

  //VFAT11
  Double_t vfat11_30[ch];
  Double_t vfat11_40[ch];
  Double_t vfat11_50[ch];
  Double_t vfat11_60[ch];
  Double_t vfat11_70[ch];
  Double_t vfat11_80[ch];
  Double_t vfat11_90[ch];
  Double_t vfat11_100[ch];
  Double_t vfat11_110[ch];
  Double_t vfat11_120[ch];
  Double_t vfat11_130[ch];
  Double_t vfat11_140[ch];
  Double_t vfat11_150[ch];

  cout << "Pausing for 2 seconds..." << endl;
  pause(2);



  //Outer loop over VFATs (x bins)
  for (int ii = 1; ii < bins+1; ii++){

    //Nested loop over fC range (y bins)
    for (int jj = 0; jj < ch; jj++){

     if (ii == 1){
        cout << "Bin " << ii << endl;
        vfat0_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat0_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat0_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat0_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat0_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat0_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat0_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat0_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat0_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat0_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat0_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat0_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat0_150[jj] = distHist_150->GetBinContent(ii,jj);
        cout << "Entry_30 " << jj << ": " << vfat0_30[jj] << endl;
        cout << "Entry_40 " << jj << ": " << vfat0_40[jj] << endl;
      }
      
      else if (ii == 2){
        vfat1_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat1_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat1_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat1_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat1_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat1_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat1_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat1_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat1_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat1_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat1_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat1_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat1_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 3){
        vfat2_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat2_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat2_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat2_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat2_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat2_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat2_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat2_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat2_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat2_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat2_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat2_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat2_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 4){
        vfat3_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat3_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat3_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat3_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat3_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat3_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat3_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat3_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat3_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat3_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat3_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat3_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat3_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 5){
        vfat4_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat4_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat4_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat4_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat4_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat4_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat4_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat4_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat4_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat4_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat4_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat4_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat4_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 6){
        vfat5_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat5_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat5_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat5_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat5_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat5_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat5_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat5_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat5_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat5_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat5_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat5_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat5_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 7){
        vfat6_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat6_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat6_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat6_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat6_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat6_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat6_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat6_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat6_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat6_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat6_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat6_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat6_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 8){
        vfat7_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat7_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat7_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat7_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat7_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat7_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat7_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat7_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat7_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat7_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat7_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat7_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat7_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 9){
        vfat8_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat8_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat8_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat8_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat8_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat8_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat8_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat8_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat8_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat8_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat8_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat8_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat8_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 10){
        vfat9_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat9_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat9_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat9_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat9_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat9_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat9_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat9_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat9_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat9_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat9_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat9_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat9_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 11){
        vfat10_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat10_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat10_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat10_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat10_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat10_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat10_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat10_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat10_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat10_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat10_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat10_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat10_150[jj] = distHist_150->GetBinContent(ii,jj);
      }
      else if (ii == 12){
        vfat11_30[jj] = distHist_30->GetBinContent(ii, jj);
        vfat11_40[jj] = distHist_40->GetBinContent(ii,jj);
        vfat11_50[jj] = distHist_50->GetBinContent(ii,jj);
        vfat11_60[jj] = distHist_60->GetBinContent(ii,jj);
        vfat11_70[jj] = distHist_70->GetBinContent(ii,jj);
        vfat11_80[jj] = distHist_80->GetBinContent(ii,jj);
        vfat11_90[jj] = distHist_90->GetBinContent(ii,jj);
        vfat11_100[jj] = distHist_100->GetBinContent(ii,jj);
        vfat11_110[jj] = distHist_110->GetBinContent(ii,jj);
        vfat11_120[jj] = distHist_120->GetBinContent(ii,jj);
        vfat11_130[jj] = distHist_130->GetBinContent(ii,jj);
        vfat11_140[jj] = distHist_140->GetBinContent(ii,jj);
        vfat11_150[jj] = distHist_150->GetBinContent(ii,jj);
      }

    }
    
  }

//Bin edges for THR_ARM_DAC values
Double_t binEdge[14] = {25,35,45,55,65,75,85,95,105,115,125,135,145,155};
//Set y-bins
cout << "Y range: " << "[0," << yMax << "]" << endl;
cout << "yBins " << ch << endl;
//TH2F *sigmaDist = new TH2F("sigmaDist","Sigma Distribution", 12, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_0 = new TH2F("sigmaDist","Sigma Distribution for VFAT0", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_1 = new TH2F("sigmaDist","Sigma Distribution for VFAT1", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_2 = new TH2F("sigmaDist","Sigma Distribution for VFAT2", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_3 = new TH2F("sigmaDist","Sigma Distribution for VFAT3", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_4 = new TH2F("sigmaDist","Sigma Distribution for VFAT4", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_5 = new TH2F("sigmaDist","Sigma Distribution for VFAT5", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_6 = new TH2F("sigmaDist","Sigma Distribution for VFAT6", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_7 = new TH2F("sigmaDist","Sigma Distribution for VFAT7", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_8 = new TH2F("sigmaDist","Sigma Distribution for VFAT8", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_9 = new TH2F("sigmaDist","Sigma Distribution for VFAT9", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_10 = new TH2F("sigmaDist","Sigma Distribution for VFAT10", binThr, binEdge, yBins, 0.0, yMax);
TH2F *sigmaDist_11 = new TH2F("sigmaDist","Sigma Distribution for VFAT11", binThr, binEdge, yBins, 0.0, yMax);
//Set tick marks
sigmaDist_0->SetNdivisions(binThr, "X");
sigmaDist_1->SetNdivisions(binThr, "X");
sigmaDist_2->SetNdivisions(binThr, "X");
sigmaDist_3->SetNdivisions(binThr, "X");
sigmaDist_4->SetNdivisions(binThr, "X");
sigmaDist_5->SetNdivisions(binThr, "X");
sigmaDist_6->SetNdivisions(binThr, "X");
sigmaDist_7->SetNdivisions(binThr, "X");
sigmaDist_8->SetNdivisions(binThr, "X");
sigmaDist_9->SetNdivisions(binThr, "X");
sigmaDist_10->SetNdivisions(binThr, "X");
sigmaDist_11->SetNdivisions(binThr, "X");
//Set x-axis titles
sigmaDist_0->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_1->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_2->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_3->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_4->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_5->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_6->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_7->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_8->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_9->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_10->GetXaxis()->SetTitle("THR_ARM_DAC");
sigmaDist_11->GetXaxis()->SetTitle("THR_ARM_DAC");
//Set y-axis titles
sigmaDist_0->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_1->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_2->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_3->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_4->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_5->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_6->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_7->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_8->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_9->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_10->GetYaxis()->SetTitle("Noise (fC)");
sigmaDist_11->GetYaxis()->SetTitle("Noise (fC)");

//TH1F *he = new TH1F("he", "he", distHist->GetNbinsX(), distHist->GetXaxis()->GetXmin(), distHist->GetXaxis()->GetXmax());
//TH1F *vfat0Dist = new TH1F("vfat0", "VFAT0 Sigma Distribution", ch, 0.0, 5.05);

//Int_t n = hp->GetNcells();
//for(Int_t i = 0; i < n; i++)
//  if (hp->GetBinError(i) != 0.) he->SetBinContent(i, hp->GetBinError(i));

for (int ii = 1; ii < 14; ii++){

  for (int jj = 0; jj < ch; jj++){

    if (ii == 1){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_30[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_30[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_30[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_30[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_30[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_30[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_30[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_30[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_30[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_30[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_30[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_30[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_30[jj]);
    }
    if (ii == 2){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_40[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_40[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_40[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_40[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_40[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_40[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_40[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_40[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_40[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_40[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_40[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_40[jj]);
    }
    if (ii == 3){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_50[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_50[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_50[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_50[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_50[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_50[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_50[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_50[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_50[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_50[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_50[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_50[jj]);
    }
    if (ii == 4){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_60[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_60[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_60[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_60[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_60[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_60[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_60[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_60[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_60[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_60[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_60[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_60[jj]);
    }
    if (ii == 5){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_70[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_70[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_70[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_70[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_70[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_70[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_70[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_70[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_70[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_70[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_70[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_70[jj]);
    }
    if (ii == 6){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_80[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_80[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_80[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_80[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_80[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_80[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_80[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_80[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_80[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_80[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_80[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_80[jj]);
    }
    if (ii == 7){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_90[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_90[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_90[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_90[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_90[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_90[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_90[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_90[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_90[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_90[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_90[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_90[jj]);
    }
    if (ii == 8){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_100[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_100[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_100[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_100[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_100[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_100[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_100[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_100[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_100[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_100[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_100[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_100[jj]);
    }
    if (ii == 9){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_110[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_110[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_110[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_110[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_110[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_110[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_110[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_110[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_110[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_110[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_110[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_110[jj]);
    }
    if (ii == 10){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_120[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_120[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_120[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_120[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_120[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_120[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_120[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_120[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_120[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_120[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_120[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_120[jj]);
    }
    if (ii == 11){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_130[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_130[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_130[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_130[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_130[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_130[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_130[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_130[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_130[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_130[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_130[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_130[jj]);
    }
    if (ii == 12){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_140[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_140[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_140[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_140[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_140[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_140[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_140[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_140[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_140[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_140[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_140[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_140[jj]);
    }
    if (ii == 13){
        cout << "xBin " << ii << " yBin " << jj << " Fill: " << vfat0_40[jj] << endl;
        sigmaDist_0->SetBinContent(ii, jj, vfat0_150[jj]);
        sigmaDist_1->SetBinContent(ii, jj, vfat1_150[jj]);
        sigmaDist_2->SetBinContent(ii, jj, vfat2_150[jj]);
        sigmaDist_3->SetBinContent(ii, jj, vfat3_150[jj]);
        sigmaDist_4->SetBinContent(ii, jj, vfat4_150[jj]);
        sigmaDist_5->SetBinContent(ii, jj, vfat5_150[jj]);
        sigmaDist_6->SetBinContent(ii, jj, vfat6_150[jj]);
        sigmaDist_7->SetBinContent(ii, jj, vfat7_150[jj]);
        sigmaDist_8->SetBinContent(ii, jj, vfat8_150[jj]);
        sigmaDist_9->SetBinContent(ii, jj, vfat9_150[jj]);
        sigmaDist_10->SetBinContent(ii, jj, vfat10_150[jj]);
        sigmaDist_11->SetBinContent(ii, jj, vfat11_150[jj]);
    }
  }

}

  cout << nEntries << endl;
  TCanvas *canv2 = new TCanvas();
  canv2->cd();
  //TCanvas *canv3 = new TCanvas();
  sigmaDist_0->Draw("CANDLE");
  canv2->SaveAs("VFAT0_sigmaDistribution.png");
  sigmaDist_1->Draw("CANDLE");
  canv2->SaveAs("VFAT1_sigmaDistribution.png");
  sigmaDist_2->Draw("CANDLE");
  canv2->SaveAs("VFAT2_sigmaDistribution.png");
  sigmaDist_3->Draw("CANDLE");
  canv2->SaveAs("VFAT3_sigmaDistribution.png");
  sigmaDist_4->Draw("CANDLE");
  canv2->SaveAs("VFAT4_sigmaDistribution.png");
  sigmaDist_5->Draw("CANDLE");
  canv2->SaveAs("VFAT5_sigmaDistribution.png");
  sigmaDist_6->Draw("CANDLE");
  canv2->SaveAs("VFAT6_sigmaDistribution.png");
  sigmaDist_7->Draw("CANDLE");
  canv2->SaveAs("VFAT7_sigmaDistribution.png");
  sigmaDist_8->Draw("CANDLE");
  canv2->SaveAs("VFAT8_sigmaDistribution.png");
  sigmaDist_9->Draw("CANDLE");
  canv2->SaveAs("VFAT9_sigmaDistribution.png");
  sigmaDist_10->Draw("CANDLE");
  canv2->SaveAs("VFAT10_sigmaDistribution.png");
  sigmaDist_11->Draw("CANDLE");
  canv2->SaveAs("VFAT11_sigmaDistribution.png");

}
