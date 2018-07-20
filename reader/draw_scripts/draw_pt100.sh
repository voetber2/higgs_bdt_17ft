hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt100.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt100_sb.pdf\
  -e 's/^(Background|Signal)$//'\
     'nl/^(Signal|Background)$.*/\1/'\
     't///'\
     'n/^Signal$/scale 0.00000255237 width'\
     'n/^Background$/scale 0.00001522927 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt100.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt100_sbs.pdf\
  -e 's/^(Signal|Background|Res_Signal)$//'\
     'nl/^(Signal|Background|Res_Signal)$.*/\1/'\
     't//Response from Signal/'\
     'n/^Background$/scale 0.00001522927 width'\
     'n/^Signal$/scale 0.00000255237 width'\
     'n/^Res_Signal$/scale 0.00000127733 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt100.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt100_sbb.pdf\
  -e 's/^(Signal|Background|Res_Background)$//'\
     'nl/^(Signal|Background|Res_Background)$.*/\1/'\
     't//Response from MC Background/' \
     'n/^Background$/scale 0.00001522927 width'\
     'n/^Signal$/scale 0.00000255237 width'\
     'n/^Res_Background$/scale 0.00000771855 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt100.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt100_sbd.pdf\
  -e 's/^(Signal|Background|Res_Data)$//'\
     'nl/^(Signal|Background|Res_Data)$.*/\1/'\
     't//Response from Data/' \
     'n/^Signal$/scale 0.00000255237 width'\
     'n/^Background$/scale 0.00001522927 width'\
     'n/^Res_Data$/scale 0.00011022927 width'\
  -g 'leg tr'\
  --colors=600 632 800
     




     # 'n/^Signal$/scale 0.00000255237 width'\
     # 'n/^Background$/scale 0.00001522927 width'\
     # 'n/^Res_Signal$/scale 0.00000127733 width'\
     # 'n/^Res_Background$/scale 0.00000771855 width'\
     # 'n/^Res_Data$/scale 0.00011022927 width'\


