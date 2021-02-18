@echo off

set /p Param=Please input the start address of BT Mini Driver + BT F/W(e.g 0x800100):
::echo %Param%
echo Merge BT F/W and MCU F/W within one Merged File...

srec_cat.exe ..\submodule\cyw89820\Release_FW\BT_mdflash.bin -Binary -offset %Param% ..\Debug\LinkCard-RT1172.bin -Binary -o boot_image.bin -Binary

