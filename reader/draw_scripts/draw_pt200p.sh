hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt200p.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt200p_sb.pdf\
  -e 's/^(Background|Signal)$//'\
     'nl/^(Signal|Background)$.*/\1/'\
     't///'\
     'n/^Signal$/scale 0.00000566809 width'\
     'n/^Background$/scale 0.00032310177 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt200p.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt200p_sbs.pdf\
  -e 's/^(Signal|Background|Res_Signal)$//'\
     'nl/^(Signal|Background|Res_Signal)$.*/\1/'\
     't//Response from Signal/'\
     'n/^Signal$/scale 0.00000566809 width'\
     'n/^Background$/scale 0.00032310177 width'\
     'n/^Res_Signal$/scale 0.00000282871 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt200p.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt200p_sbb.pdf\
  -e 's/^(Signal|Background|Res_Background)$//'\
     'nl/^(Signal|Background|Res_Background)$.*/\1/'\
     't//Response from MC Background/' \
     'n/^Signal$/scale 0.00000566809 width'\
     'n/^Background$/scale 0.00032310177 width'\
     'n/^Res_Background$/scale 0.00016393442 width'\
  -g 'leg tr'\
  --colors=600 632 800


hed /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/TrainingResults_Grad_pt200p.root\
  -o /home/voetberg/programs/TMVA/BDT_n_ANN/tmva_17feat/reader/ReaderResults/h_TrainingResults_pt200p_sbd.pdf\
  -e 's/^(Signal|Background|Res_Data)$//'\
     'nl/^(Signal|Background|Res_Data)$.*/\1/'\
     't//Response from Data/' \
     'n/^Signal$/scale 0.00000566809 width'\
     'n/^Background$/scale 0.00032310177 width'\
     'n/^Res_Data$/scale 0.00411522633 width'\
  -g 'leg tr'\
  --colors=600 632 800
     




     # 'n/^Signal$/scale 0.00000566809 width'\
     # 'n/^Background$/scale 0.00032310177 width'\
     # 'n/^Res_Signal$/scale 0.00000282871 width'\
     # 'n/^Res_Background$/scale 0.00016393442 width'\
     # 'n/^Res_Data$/scale 0.00411522633 width'\


