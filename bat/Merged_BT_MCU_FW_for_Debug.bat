@echo off

cd..

SET CURRENT_PATH=%CD%
SET BT_ADDRESS=%1
SET BT_VERSION=%2
SET MCU_DATA_FOLDER=%3

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
    "%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import "%CURRENT_PATH%" -cleanBuild LinkCard-RT1172/Debug -data "%MCU_DATA_FOLDER%"
) else (
    "%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import "%CURRENT_PATH%" -cleanBuild LinkCard-RT1172/Debug
)

cd /d %TOOLCHAIN_PATH%

echo Transform to Binary File...
arm-none-eabi-objcopy -v -O binary %CURRENT_PATH%\Debug\LinkCard-RT1172.axf %CURRENT_PATH%\Debug\LinkCard-RT1172.bin

cd /d %CURRENT_PATH%\bat

echo Merge BT F/W and MCU F/W within one Merged File...
if "%BT_ADDRESS%" NEQ "" (
    srec_cat.exe ..\submodule\cyw89820\Release_FW\BT_mdflash.bin -Binary -offset %BT_ADDRESS% ..\Debug\LinkCard-RT1172.bin -Binary -o boot_image.bin -Binary
    if "%BT_VERSION%" NEQ "" (
        srec_cat.exe boot_image.bin -Binary -E 0xE00000 0xE00002 -GEN 0xE00000 0xE00002 -CONSTant_Big_Endian %BT_VERSION% 2 -O boot_image.bin -Binary
	)
)
