#include <iostream> 
#include <vector> 
#include <stdlib.h> 
#include <utility> 
#include <chrono> 

#include <boost/optional.hpp> 
#include <TFile.h> 
#include <TChain.h> 
#include <TH1.h> 
#include <TLorentzVector.h> 
#include <TTree.h> 
#include <TRandom3.h> 

#include "Higgs2diphoton.hh"

using namespace std; 

Higgs2diphoton Hdecay; 

int main(){ 
  TFile *sig = TFile::Open("$TMPDIR/H1.0j_GGFHT_B_6500_pt25.0_eta4.5_r100_100.root"); 
  TFile *bg = TFile::Open("$TMPDIR/born6.root"); 
  //===============================================
  TFile* out = TFile::Open("tmva_data_17feat.root", "RECREATE"); 
  //===============================================
  TChain* chain_b = (TChain*)bg->Get("t3"); 
  TChain* chain_s = (TChain*)sig->Get("t3"); 
   //===============================================
  constexpr size_t max = 10; 
  Float_t px_s[max], py_s[max], pz_s[max], E_s[max];
  Int_t nparticle_s, kf_s[max]; 
  Double_t weight_s; 

  Float_t px_b[max], py_b[max], pz_b[max], E_b[max];
  Int_t nparticle_b, kf_b[max]; 
  Double_t weight_b; 

  //===============================================
  chain_s->SetBranchAddress("nparticle",&nparticle_s);                        
  chain_s->SetBranchAddress("kf",kf_s);                                       
  chain_s->SetBranchAddress("px",px_s);                                       
  chain_s->SetBranchAddress("py",py_s);                                       
  chain_s->SetBranchAddress("pz",pz_s);                                       
  chain_s->SetBranchAddress("E",E_s); 
  chain_s->SetBranchAddress("weight2",&weight_s); 

  chain_b->SetBranchAddress("nparticle",&nparticle_b);                        
  chain_b->SetBranchAddress("kf",kf_b);                                       
  chain_b->SetBranchAddress("px",px_b);                                       
  chain_b->SetBranchAddress("py",py_b);                                       
  chain_b->SetBranchAddress("pz",pz_b);                                       
  chain_b->SetBranchAddress("E",E_b); 
  chain_b->SetBranchAddress("weight2",&weight_b); 
  //===============================================
  Float_t combomass, diphotonDR, photon1DR, photon2DR, ptratio, pho1rap, pho2rap,jetrap, phosep; 
  Float_t photon1E, photon1pt, photon2E, photon2pt, diphotonE, diphotonpt, jetE, jetpt; 
  Float_t weights; 
  //===============================================
  TTree* sig_train = new TTree("sigTrain", "signal");                           
  TTree* bg_train = new TTree("bgTrain", "background");                         
  sig_train->SetDirectory(out);                                              
  bg_train->SetDirectory(out);                                               
                                                                                
  TTree* sig_test = new TTree("sigTest", "signal");                             
  TTree* bg_test = new TTree("bgTest", "background");                           
  sig_test->SetDirectory(out);                                               
  bg_test->SetDirectory(out); 
  //===============================================
  //Ouputs
  //Signal
  sig_train->Branch("combomass", &combomass);                                   
  sig_train->Branch("diphotonDR", &diphotonDR);                                 
  sig_train->Branch("photon1DR", &photon1DR);                                   
  sig_train->Branch("photon2DR", &photon2DR);                                   
  sig_train->Branch("ptratio", &ptratio);                                       
  sig_train->Branch("pho1rap", &pho1rap);                                       
  sig_train->Branch("pho2rap", &pho2rap);                                       
  sig_train->Branch("jetrap", &jetrap);                                         
  sig_train->Branch("phosep", &phosep);                                         
  sig_train->Branch("photon1E", &photon1E);                                     
  sig_train->Branch("photon1pt", &photon1pt);                                   
  sig_train->Branch("photon2E", &photon2E);                                     
  sig_train->Branch("photon2pt", &photon2pt);                                   
  sig_train->Branch("diphotonE", &diphotonE);                                   
  sig_train->Branch("diphotonpt", &diphotonpt);                                 
  sig_train->Branch("jetE", &jetE);                                             
  sig_train->Branch("jetpt", &jetpt);            
  
  sig_train->Branch("weights", &weights);  
  //  
  sig_test->Branch("combomass", &combomass);                                    
  sig_test->Branch("diphotonDR", &diphotonDR);                                  
  sig_test->Branch("photon1DR", &photon1DR);                                    
  sig_test->Branch("photon2DR", &photon2DR);                                    
  sig_test->Branch("ptratio", &ptratio);                                        
  sig_test->Branch("pho1rap", &pho1rap);                                        
  sig_test->Branch("pho2rap", &pho2rap);                                        
  sig_test->Branch("jetrap", &jetrap);                                          
  sig_test->Branch("phosep", &phosep);                                          
  sig_test->Branch("photon1E", &photon1E);                                      
  sig_test->Branch("photon1pt", &photon1pt);                                    
  sig_test->Branch("photon2E", &photon2E);                                      
  sig_test->Branch("photon2pt", &photon2pt);                                    
  sig_test->Branch("diphotonE", &diphotonE);                                    
  sig_test->Branch("diphotonpt", &diphotonpt);                                  
  sig_test->Branch("jetE", &jetE);                                              
  sig_test->Branch("jetpt", &jetpt);  
   
  sig_test->Branch("weights", &weights);  
  
  //Background 
  bg_train->Branch("combomass", &combomass);                                    
  bg_train->Branch("diphotonDR", &diphotonDR);                                  
  bg_train->Branch("photon1DR", &photon1DR);                                    
  bg_train->Branch("photon2DR", &photon2DR);                                    
  bg_train->Branch("ptratio", &ptratio);                                        
  bg_train->Branch("pho1rap", &pho1rap);                                        
  bg_train->Branch("pho2rap", &pho2rap);                                        
  bg_train->Branch("jetrap", &jetrap);                                          
  bg_train->Branch("phosep", &phosep);                                                                          bg_train->Branch("photon1E", &photon1E);                                      
  bg_train->Branch("photon1pt", &photon1pt);                                
  bg_train->Branch("photon2E", &photon2E);                                      
  bg_train->Branch("photon2pt", &photon2pt);                                    
  bg_train->Branch("diphotonE", &diphotonE);                                    
  bg_train->Branch("diphotonpt", &diphotonpt);                                  
  bg_train->Branch("jetE", &jetE);                                              
  bg_train->Branch("jetpt", &jetpt);                                            
  
  bg_train->Branch("weights", &weights);  
  // 
  bg_test->Branch("diphotonDR", &diphotonDR);                                   
  bg_test->Branch("combomass", &combomass);                                    
  bg_test->Branch("photon1DR", &photon1DR);                                     
  bg_test->Branch("photon2DR", &photon2DR);                                     
  bg_test->Branch("ptratio", &ptratio);                                         
  bg_test->Branch("pho1rap", &pho1rap);                                         
  bg_test->Branch("pho2rap", &pho2rap);                                         
  bg_test->Branch("jetrap", &jetrap);                                           
  bg_test->Branch("phosep", &phosep);                                           
  bg_test->Branch("photon1E", &photon1E);                                       
  bg_test->Branch("photon1pt", &photon1pt);                                     
  bg_test->Branch("photon2E", &photon2E);                                       
  bg_test->Branch("photon2pt", &photon2pt);                                     
  bg_test->Branch("diphotonE", &diphotonE);                                     
  bg_test->Branch("diphotonpt", &diphotonpt);                                   
  bg_test->Branch("jetE", &jetE);                                               
  bg_test->Branch("jetpt", &jetpt);  
  
  bg_test->Branch("weights", &weights);  
  //===============================================
  const Long64_t entries_s = chain_s->GetEntries(); 
  const Long64_t entries_b = chain_b->GetEntries(); 
  //===============================================

  for (long k=0; k<entries_s; ++k){
    chain_s->GetEntry(k); 
    //Assign particles 
    TLorentzVector higgs, photon1, photon2, jet; 

    for (long i=0; i<nparticle_s; ++i){
      if (kf_s[i]==25){
        higgs.SetPxPyPzE(px_s[i], py_s[i], pz_s[i], E_s[i]); 
      }
      else{
        jet.SetPxPyPzE(px_s[i], py_s[i], pz_s[i], E_s[i]); 
      }
    }
    //Decay Higgs
    pair<TLorentzVector, TLorentzVector> diphoton = Hdecay(higgs); 
    //Sort 
    if (diphoton.first.Pt()>=diphoton.second.Pt()){
      photon1 = diphoton.first; 
      photon2 = diphoton.second; 
    }
    else{
      photon1 = diphoton.second; 
      photon2 = diphoton.first; 
    }
    //===============================================
    combomass = (higgs + jet).M(); 
    //Delta R's 
    diphotonDR = abs(higgs.DeltaR(jet)); 
    photon1DR = abs(photon1.DeltaR(jet)); 
    photon2DR = abs(photon2.DeltaR(jet)); 
    //Rapidities 
    pho1rap = abs(photon1.Rapidity()); 
    pho2rap = abs(photon2.Rapidity()); 
    jetrap = abs(jet.Rapidity()); 
    phosep = abs(pho1rap - pho2rap); 
    //Pt's 
    diphotonpt = abs(higgs.Pt()); 
    photon1pt = abs(photon1.Pt());
    photon2pt = abs(photon2.Pt());
    jetpt = abs(jet.Pt());
    ptratio = photon1pt/photon2pt; 
    //Energies 
    diphotonE = abs(higgs.E()); 
    photon1E = abs(photon1.E()); 
    photon2E = abs(photon2.E()); 
    jetE = abs(jet.E()); 
    //Weights 
    weights = weight_s;  
    //===============================================
    TRandom3 *r = new TRandom3(std::chrono::system_clock::now().time_since_epoch().count());
    double ran = r->Rndm();                                                     
    const bool tts = (ran<.75);                                                 
                                                                                
    if (tts){                                                                                                       sig_train->Fill();                                                       
    }                                                                           
    else{                                                                       
      sig_test->Fill();                                                         
    }                    
  }
  //===============================================
  for (long k=0; k<entries_b; ++k){
    chain_b->GetEntry(k); 
    //Assign particles 
    TLorentzVector photon1, photon2, jet, diphoton; 
    vector<TLorentzVector> photons; 

    for (long i=0; i<nparticle_b; ++i){
      if (kf_b[i]==22){
        photons.emplace_back(px_b[i], py_b[i], pz_b[i], E_b[i]); 
      }
      else{
        jet.SetPxPyPzE(px_b[i], py_b[i], pz_b[i], E_b[i]); 
      }
    }
    //Applying a mass cut 
    diphoton = (photons[0] + photons[1]); 
    if ((diphoton.M()>115.)&&(diphoton.M()<135.)){
      
      //Sort photons   
      if (photons[0].Pt()>=photons[1].Pt()){
        photon1 = photons[0]; 
        photon2 = photons[1]; 
      }
      else{
        photon1 = photons[1]; 
        photon2 = photons[0]; 
      }
      combomass = (diphoton + jet).M(); 
     //Delta R's 
      diphotonDR = abs(diphoton.DeltaR(jet)); 
      photon1DR = abs(photon1.DeltaR(jet)); 
      photon2DR = abs(photon2.DeltaR(jet)); 
      //Rapidities 
      pho1rap = abs(photon1.Rapidity()); 
      pho2rap = abs(photon2.Rapidity()); 
      jetrap = abs(jet.Rapidity()); 
      phosep = abs(pho1rap - pho2rap); 
      //Pt's 
      diphotonpt = abs(diphoton.Pt()); 
      photon1pt = abs(photon1.Pt());
      photon2pt = abs(photon2.Pt());
      jetpt = abs(jet.Pt());
      ptratio = photon1pt/photon2pt; 
      //Energies 
      diphotonE = abs(diphoton.E()); 
      photon1E = abs(photon1.E()); 
      photon2E = abs(photon2.E()); 
      jetE = abs(jet.E()); 
      //Weights 
      weights = weight_b;  
      //===============================================
      TRandom3 *r = new TRandom3(std::chrono::system_clock::now().time_since_epoch().count());
      double ran = r->Rndm();                                                     
      const bool tts = (ran<.75);                                                 
                                                                                  
      if (tts){
        bg_train->Fill(); 
      }      
      else{                                                                       
        bg_test->Fill();                                                         
      }                    
    }
  }
  out->Write(); 
  out->Close(); 

}
