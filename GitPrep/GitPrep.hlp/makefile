

GitPrep.chm : *.htm GitPrep.hhp GitPrep.hhc App.css
  -1 "C:\Program Files (x86)\HTML Help Workshop\hhc" GitPrep


Clean.cln    :
  @echo "Cleaning"
  cd $(MAKEDIR)
  if exist GitPrep.chm del /F GitPrep.chm


$(TgtFolder)/GitPrep.chm : GitPrep.chm
  copy $(MAKEDIR)\GitPrep.chm  $(MAKEDIR)\..\$(TgtFolder)\GitPrep.chm


$(TgtFolder)/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\$(TgtFolder)
  if exist GitPrep.chm del /F GitPrep.chm
  cd $(MAKEDIR)


$(TgtFolder)/Rebuild.rbd : $(TgtFolder)/Clean.cln $(TgtFolder)/GitPrep.chm

