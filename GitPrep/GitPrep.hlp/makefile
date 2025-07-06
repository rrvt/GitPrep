

GitPrep.chm : *.htm GitPrep.hhp GitPrep.hhc App.css
  -1 "C:\Program Files (x86)\HTML Help Workshop\hhc" GitPrep


Clean.cln    :
  @echo "Cleaning"
  cd $(MAKEDIR)
  if exist GitPrep.chm del /F GitPrep.chm


Release/GitPrep.chm : GitPrep.chm
  copy $(MAKEDIR)\GitPrep.chm  $(MAKEDIR)\..\Release\GitPrep.chm


Release/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\Release
  if exist GitPrep.chm del /F GitPrep.chm
  cd $(MAKEDIR)


Debug/GitPrep.chm : GitPrep.chm
  copy $(MAKEDIR)\GitPrep.chm  $(MAKEDIR)\..\Debug\GitPrep.chm


Debug/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\Debug
  if exist GitPrep.chm del /F GitPrep.chm
  cd $(MAKEDIR)


Release/Rebuild.rbd : Release/Clean.cln Release/GitPrep.chm


Debug/Rebuild.rbd   : Debug/Clean.cln Debug/GitPrep.chm


