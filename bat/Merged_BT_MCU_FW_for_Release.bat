@echo off

cd..

SET CURRENT_PATH=%CD%

echo %CURRENT_PATH%

REM path to GNU tools and compiler: arm-none-eabi-gcc.exe, ....
SET TOOLCHAIN_PATH=%IDE_PATH%\ide\tools\bin

REM variable to the command line Eclipse IDE executable
SET IDE=%IDE_PATH%\ide\mcuxpressoidec.exe

echo Extending PATH if not already present
echo %PATH%|findstr /i /c:"%TOOLCHAIN_PATH:"=%">nul || set PATH=%PATH%;%TOOLCHAIN_PATH%

echo Copy MultiLanguage Fonts
xcopy .\EmbeddedWizard\MultiLanguage .\EmbeddedWizard\GeneratedCode /y

echo Clean and Build Project...

REM -cleanbuild on a build target: this does a 'clean' only on the build target, no build
"%IDE%" -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import %CURRENT_PATH% -cleanBuild LinkCard-RT1176/Release

cd /d %TOOLCHAIN_PATH%

echo Transform to Binary File...
arm-none-eabi-objcopy -v -O binary %CURRENT_PATH%\Release\LinkCard-RT1176.axf %CURRENT_PATH%\Release\LinkCard-RT1176.bin

cd /d %CURRENT_PATH%\bat

set one=%1
set two=%2

echo Merge BT F/W and MCU F/W within one Merged File...
if "%one%" NEQ "" (
    srec_cat.exe ..\submodule\cyw89820\Release_FW\BT_mdflash.bin -Binary -offset %1 ..\Release\LinkCard-RT1176.bin -Binary -o boot_image.bin -Binary
    if "%two%" NEQ "" (
        srec_cat.exe boot_image.bin -Binary -E 0x800000 0x800002 -GEN 0x800000 0x800002 -CONSTant_Big_Endian %2 2 -O boot_image.bin -Binary
	)
)

