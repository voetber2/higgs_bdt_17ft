hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt50.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt50_sb.pdf\
  -e 's/^(Background|Signal)$//'\
     'nl/(Signal|Background).*/\1/'\
     'n/^Signal$/scale 0.00000298728 width'\
     'n/^Background$/scale 0.00001489713 width'\
     't///'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt50.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt50_sbs.pdf\
  -e 's/^(Signal|Background|Res_Signal)$//'\
     'nl/(Signal|Background|Res_Signal).*/\1/'\
     't//Response from Signal/'\
     'n/^Signal$/scale 0.00000298728 width'\
     'n/^Background$/scale 0.00001489713 width'\
     'n/^Res_Signal$/scale 0.00000149151 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt50.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt50_sbb.pdf\
  -e 's/^(Signal|Background|Res_Background)$//'\
     'nl/(Signal|Background|Res_Background).*/\1/'\
     't//Response from MC Background/' \
     'n/^Signal$/scale 0.00000298728 width'\
     'n/^Background$/scale 0.00001489713 width'\
     'n/^Res_Background$/scale 0.00000755566 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt50.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt50_sbd.pdf\
  -e 's/^(Signal|Background|Res_Data)$//'\
     'nl/(Signal|Background|Res_Data).*/\1/'\
     't//Response from Data/' \
     'n/^Signal$/scale 0.00000298728 width'\
     'n/^Background$/scale 0.00001489713 width'\
     'n/^Res_Data$/scale 0.0000245068 width'\
  -g 'leg tr'\
  --colors=600 632 800
     




     # 'n/Signal/scale 0.00000298728 width'\
     # 'n/Background/scale 0.00001489713 width'\
     # 'n/Res_Signal/scale 0.00000149151 width'\
     # 'n/Res_Background/scale 0.00000755566 width'\
     # 'n/Res_Data/scale 0.0000245068 width'\


