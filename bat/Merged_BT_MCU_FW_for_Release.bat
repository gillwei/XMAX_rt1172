@echo off

cd..

SET CURRENT_PATH=%CD%
SET /a BT_ADDRESS=%1
SET /a BT_VERSION=%2
SET MCU_DATA_FOLDER=%3

if %BT_ADDRESS%==0 (
    echo "Invalid BT address"
    exit -1
)

if %BT_VERSION%==0 (
    echo "Invalid BT version"
    exit -1
)

SET /a BT_VERSION_END=%BT_ADDRESS% + 2
SET /a BT_FIRMWARE_ADDRESS=%BT_ADDRESS% + 0x100

echo %CURRENT_PATH%

REM path to GNU tools and compiler: arm-none-eabi-gcc.exe, ....
SET TOOLCHAIN_PATH=%IDE_PATH%\ide\tools\bin

REM variable to the command line Eclipse IDE executable
SET IDE=%IDE_PATH%\ide\mcuxpressoidec.exe

echo Extending PATH if not already present
echo %PATH%|findstr /i /c:"%TOOLCHAIN_PATH:"=%">nul || set PATH=%PATH%;%TOOLCHAIN_PATH%

echo Clean and Build Project...

REM -cleanbuild on a build target: this does a 'clean' only on the build target, no build
if "%MCU_DATA_FOLDER%" NEQ "" (
    "%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import "%CURRENT_PATH%/submodule/rt1172_bootloader" -cleanBuild IXWW22_BLD/Release -data "%MCU_DATA_FOLDER%"
    "%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import "%CURRENT_PATH%" -cleanBuild LinkCard-RT1172/Release -data "%MCU_DATA_FOLDER%"
) else (
    "%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import "%CURRENT_PATH%/submodule/rt1172_bootloader" -cleanBuild IXWW22_BLD/Release
    "%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import "%CURRENT_PATH%" -cleanBuild LinkCard-RT1172/Release
)

cd /d %TOOLCHAIN_PATH%

echo Transform to srec File...
arm-none-eabi-objcopy -v -O srec %CURRENT_PATH%\Release\LinkCard-RT1172.axf %CURRENT_PATH%\Release\LinkCard-RT1172.srec
arm-none-eabi-objcopy -v -O srec %CURRENT_PATH%\submodule\rt1172_bootloader\Release\IXWW22_BLD.axf %CURRENT_PATH%\submodule\rt1172_bootloader\Release\IXWW22_BLD.srec

cd /d %CURRENT_PATH%\bat

echo Merge BT F/W and MCU F/W within one Merged File...
if "%BT_ADDRESS%" NEQ "" (
    if "%BT_VERSION%" NEQ "" (
        srec_cat.exe ..\submodule\rt1172_bootloader\Release\IXWW22_BLD.srec -M ..\Release\LinkCard-RT1172.srec -M -GEN %BT_ADDRESS% %BT_VERSION_END% -CONSTant_Big_Endian %BT_VERSION% 2 ..\submodule\cyw89820\Release_FW\BT_mdflash.bin -Binary -offset %BT_FIRMWARE_ADDRESS% SYS_A_VALIDITY.srec -M -O boot_image.srec -M -header=boot_image
        srec_cat.exe boot_image.srec -M -offset - 0x30000000 -O boot_image.bin -Binary
    )
)
