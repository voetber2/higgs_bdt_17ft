# higgs_bdt_17ft
bdt analysis of higgs to diphoton using tmva 

Using data generation in [tmva_read_data](https://github.com/voetber2/tmva_read_data)

tmva_17feat.cc is the tmva itself, produces weight files used by reader program.

Uses 17 variables relating to y1, y2, yy, and the first jet. 

Reader takes in testing data from tmva training files, to build seperation between signal and background responses. 
It then reads in seperate MC Data to view how it responds to pure signal and pure background, along with unseperated data. 
Draw_pt\* scripts then layer these repsonses onto the Signal and Background distibutions, as a no nonsense check. 

  



[TMVA Webpage](http://tmva.sourceforge.net/) 

[Higgs2Diphoton from Ivan](https://github.com/ivankp) 

[HED from Root Tools](https://github.com/ivankp/root_tools)
