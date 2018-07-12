#include <iostream>                                                             
#include <vector>                                                               
#include <cstdlib>                                                              
                                                                                
#include <TChain.h>                                                             
#include <TFile.h>                                                              
#include <TTree.h>                                                              
#include <TString.h>                                                            
#include <TSystem.h>                                                            
#include <TROOT.h>                                                              
#include <TCanvas.h>                                                            
#include <TLegend.h>                                                            
                                                                                
#include <TMVA/Tools.h>                                                         
#include <TMVA/Reader.h>                                                        
#include <TMVA/MethodCuts.h>                                                    
 
using namespace std; 

int main(){
  TMVA::Tools::Instance(); 
  map<string,int> Use; 

  TMVA::Reader* reader = new TMVA::Reader("Color:!Silent"); 
  TFile* out = new TFile("TrainingResults_Grad_res126_129.root", "RECREATE"); 

  //Putting variables into the reader
  Float_t yydr, y1dr, y2dr, ptratio, y1y, y2y, jety, s; 
  Float_t yydy, y1E, y2E, yyE, jetE; 
  Float_t y1pt, y2pt, yypt, jetpt; 

  reader->AddVariable("s", &s); 
  reader->AddVariable("yydr", &yydr); 
  reader->AddVariable("y1dr", &y1dr); 
  reader->AddVariable("y2dr", &y2dr); 
  reader->AddVariable("ptratio", &ptratio); 
  reader->AddVariable("y1y", &y1y); 
  reader->AddVariable("y2y", &y2y); 
  reader->AddVariable("jety", &jety); 
  reader->AddVariable("yydy", &yydy); 
  
  reader->AddVariable("y1E", &y1E); 
  reader->AddVariable("y1pt", &y1pt); 

  reader->AddVariable("y2E", &y2E); 
  reader->AddVariable("y2pt", &y2pt);

  reader->AddVariable("yyE", &yyE); 
  reader->AddVariable("yypt", &yypt); 
  
  reader->AddVariable("jetE", &jetE); 
  reader->AddVariable("jetpt", &jetpt); 
  
  cout<<"Reader Variables Added"<<endl;
  
  //Add method to the reader
  TString w = "/home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/TMVAClassification_BDT_Grad.weights.xml"; 
  reader->BookMVA("method", w); 

  cout<<"Method Added to the Reader"<<endl; 

  //Output Histograms 
  TH1D* h_sig = new TH1D("Signal", "Signal", 200.,-1.,1.); 
  TH1D* h_bg = new TH1D("Background", "Background", 200.,-1.,1.); 
  TH1D* h_res = new TH1D("Res", "Res", 200, -1., 1.); 

  //Read data 
  TFile* in = TFile::Open("/msu/data/t3work9/voetberg/tmva_input/data_17feat_cuts.root"); 
  TFile* in2 = TFile::Open("/msu/data/t3work9/voetberg/tmva_input/17feat_pt26_29.root"); 

  cout<<"Opened read data"<<endl; 

  TTree* sig = (TTree*)in->Get("sigTest"); 
  TTree* bg = (TTree*)in->Get("bgTest"); 
  TTree* res = (TTree*)in2->Get("tree"); 

  //Signal 
  sig->SetBranchAddress("yydr", &yydr); 
  sig->SetBranchAddress("y1dr", &y1dr); 
  sig->SetBranchAddress("y2dr", &y2dr); 
  sig->SetBranchAddress("yydy", &yydy); 
  sig->SetBranchAddress("y1y", &y1y); 
  sig->SetBranchAddress("y2y", &y2y); 
  sig->SetBranchAddress("jety", &jety); 
  sig->SetBranchAddress("ptratio", &ptratio); 
  sig->SetBranchAddress("s", &s); 
  
  sig->SetBranchAddress("yyE", &yyE); 
  sig->SetBranchAddress("y1E", &y1E); 
  sig->SetBranchAddress("y2E", &y2E); 
  sig->SetBranchAddress("jetE", &jetE); 

  sig->SetBranchAddress("yypt", &yypt); 
  sig->SetBranchAddress("y1pt", &y1pt); 
  sig->SetBranchAddress("y2pt", &y2pt); 
  sig->SetBranchAddress("jetpt", &jetpt); 

  //Background
  bg->SetBranchAddress("yydr", &yydr); 
  bg->SetBranchAddress("y1dr", &y1dr); 
  bg->SetBranchAddress("y2dr", &y2dr); 
  bg->SetBranchAddress("yydy", &yydy); 
  bg->SetBranchAddress("y1y", &y1y); 
  bg->SetBranchAddress("y2y", &y2y); 
  bg->SetBranchAddress("jety", &jety); 
  bg->SetBranchAddress("ptratio", &ptratio); 
  bg->SetBranchAddress("s", &s); 
  
  bg->SetBranchAddress("yyE", &yyE); 
  bg->SetBranchAddress("y1E", &y1E); 
  bg->SetBranchAddress("y2E", &y2E); 
  bg->SetBranchAddress("jetE", &jetE); 

  bg->SetBranchAddress("yypt", &yypt); 
  bg->SetBranchAddress("y1pt", &y1pt); 
  bg->SetBranchAddress("y2pt", &y2pt); 
  bg->SetBranchAddress("jetpt", &jetpt); 

  //Responses
  res->SetBranchAddress("yydr", &yydr); 
  res->SetBranchAddress("y1dr", &y1dr); 
  res->SetBranchAddress("y2dr", &y2dr); 
  res->SetBranchAddress("yydy", &yydy); 
  res->SetBranchAddress("y1y", &y1y); 
  res->SetBranchAddress("y2y", &y2y); 
  res->SetBranchAddress("jety", &jety); 
  res->SetBranchAddress("ptratio", &ptratio); 
  res->SetBranchAddress("s", &s); 
  
  res->SetBranchAddress("yyE", &yyE); 
  res->SetBranchAddress("y1E", &y1E); 
  res->SetBranchAddress("y2E", &y2E); 
  res->SetBranchAddress("jetE", &jetE); 

  res->SetBranchAddress("yypt", &yypt); 
  res->SetBranchAddress("y1pt", &y1pt); 
  res->SetBranchAddress("y2pt", &y2pt); 
  res->SetBranchAddress("jetpt", &jetpt); 
  
  cout<<"Read in Trees"<<endl; 

  const Long64_t sig_entries = sig->GetEntries(); 
  const Long64_t bg_entries = bg->GetEntries(); 
  const Long64_t res_entries = res->GetEntries(); 
  
  
  cout<<"Signal Events: "<<sig_entries<<endl; 
  cout<<"Background Events: "<<bg_entries<<endl; 
  cout<<"Classify Evnts: "<<res_entries<<endl; 

  for (long i=0; i<sig_entries; ++i){
    sig->GetEntry(i); 
    h_sig->Fill(reader->EvaluateMVA("method"));    
  }

  cout<<"Filled Signal Histogram"<<endl; 

  for (long i=0; i<bg_entries; ++i){
    bg->GetEntry(i); 
    h_bg->Fill(reader->EvaluateMVA("method")); 
  }

  cout<<"Filled Background Histogram"<<endl; 

  for (long i=0; i<res_entries; ++i){
    res->GetEntry(i); 
    h_res->Fill(reader->EvaluateMVA("method")); 
  }
    
  cout<<"Filled Response Histogram"<<endl;
   
  
  out->Write(); 
  out->Close(); 

  delete reader; 
}
