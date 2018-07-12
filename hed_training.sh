hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/TrainingResults_Grad_res126_129.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/Training_Grad_res126_129.pdf\
  -e 's/(Signal|Background|Res)//'\
     'nl/(Signal|Background|Res).*/\1/'\
     'gt' 'tx'\
     'n/Signal/scale 0.00000154334 width'\
     'n/Background/scale 0.00001139847 width'\
     'n/Res/scale 0.00003913128 width'\
  -g 'leg tr'\
  --colors=600 632 800


