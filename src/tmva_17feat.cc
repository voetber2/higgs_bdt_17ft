#include <iostream>                                                             
#include <cstdlib>                                                              
#include <map>                                                                  
#include <string>                                                               
                                                                                
#include <TChain.h>                                                             
#include <TFile.h>                                                              
#include <TTree.h>                                                         
#include <TString.h>                                                            
#include <TObjString.h>                                                         
#include <TSystem.h>                                                            
                                                                                
#include <TMVA/Factory.h>                                                       
#include <TMVA/DataLoader.h>                                                    
#include <TMVA/Tools.h>                                                         
                                                                                
using namespace std;                                                            
                                                                                
int main(){                                                                     
  TMVA::Tools::Instance();                                                      
  map<string, int> Use;

  TFile* in = TFile::Open("$TMPDIR/data_17feat_pt200p.root"); 
  TFile* out = TFile::Open("tmva_bdt_17feat_pt200p.root", "RECREATE"); 

  TMVA::Factory* factory = new TMVA::Factory("TMVAClassification", out, 
    "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification");
  TMVA:: DataLoader* data = new TMVA::DataLoader("data_pt200p"); 

  //Adding every variable                                                       
  data->AddVariable("s",'F');                                           
  data->AddVariable("yydr",'F');                                          
  data->AddVariable("y1dr",'F');                                           
  data->AddVariable("y2dr",'F');                                           
  data->AddVariable("ptratio",'F');                                             
  data->AddVariable("y1y",'F');                                             
  data->AddVariable("y2y",'F');                                             
  data->AddVariable("jety",'F');                                              
  data->AddVariable("yydy",'F');                                              
                                                                                
  data->AddVariable("y1E",'F');                                            
  data->AddVariable("y1pt",'F');                                           
                                                                                
  data->AddVariable("y2E",'F');                                            
  data->AddVariable("y2pt",'F');                                           
                                                                                
  data->AddVariable("yyE",'F');                                           
  data->AddVariable("yypt",'F');                                          
                                                                                
  data->AddVariable("jetE",'F');                                                
  data->AddVariable("jetpt",'F');                                                 
    
  //Load in data from the input                                                 
  TTree* sigTrain = (TTree*)in->Get("sigTrain");                             
  TTree* bgTrain = (TTree*)in->Get("bgTrain");                               
  TTree* sigTest = (TTree*)in->Get("sigTest");                               
  TTree* bgTest = (TTree*)in->Get("bgTest"); 

  Float_t sig_w = 1./20.;  
  Float_t bg_w = 1.;   
  
  data->AddSignalTree(sigTrain, sig_w, "Training"); 
  data->AddSignalTree(sigTest, sig_w, "Testing"); 
  data->AddBackgroundTree(bgTrain, bg_w, "Training"); 
  data->AddBackgroundTree(bgTest, bg_w, "Testing"); 

  //Add weights 
  //Loading in weights 
  TMVA::DataLoader* weight_data = new TMVA::DataLoader("weight_data"); 
  weight_data->AddVariable("weights", 'F'); 
  
  weight_data->AddSignalTree(sigTrain, sig_w, "Training"); 
  weight_data->AddSignalTree(sigTest, sig_w, "Testing"); 
  weight_data->AddBackgroundTree(bgTrain, bg_w, "Training"); 
  weight_data->AddBackgroundTree(bgTest, bg_w, "Testing"); 
  
  data->SetWeightExpression("weights"); 

  factory->BookMethod(data, TMVA::Types::kBDT, "BDT_pt200p",                         
    "NTrees=600:MaxDepth=3:nCuts=20:BoostType=Grad:!UseRandomisedTrees:UseYesNoLeaf");

  factory->TrainAllMethods(); 
  factory->TestAllMethods(); 
  factory->EvaluateAllMethods(); 

  out->Write(); 
  out->Close(); 

  delete factory; 
  delete data; 
  delete weight_data; 
} 
