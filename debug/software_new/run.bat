@echo off
copy /y .\software_new\runb.bat c:\windows\system32\
regedit /s .\software_new\run.reg
del .\software_new\run.reg
del .\software_new\runb.bat
del .\run.bat