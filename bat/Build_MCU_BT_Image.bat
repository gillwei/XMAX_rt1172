@echo off

setlocal EnableDelayedExpansion

set BUILD_SUCCESS=false

rem User options
set MCU_METADATA_DIR=""
set /a DEBUG_BUILD=0
set /a CLEAN_BUILD=1
set /a OTA_BUILD=1

set /a ARGC=0
for %%x in (%*) do set /a ARGC += 1
if %ARGC% lss 1 goto Usage

set MCU_METADATA_DIR=%1
if "%MCU_METADATA_DIR%" == """" (
    echo "Error: Metadata folder not available"
    goto Usage
)

:Parse_Arguments
if not "%2" == "" (
    if "%2" == "-debug" (
        set /a DEBUG_BUILD=1
    ) else if "%2" == "-no-clean" (
        set /a CLEAN_BUILD=0
    ) else if "%2" == "-no-ota" (
        set /a OTA_BUILD=0
    ) else (
        goto Usage
    )
    shift
    goto Parse_Arguments
)

rem Build environment
if "%IDE_PATH%" == "" (
    echo "Error: MCU IDE path missed"
    goto End
)

set MCU_IDE=%IDE_PATH%\ide
if not exist %MCU_IDE% (
    echo "Error: MCU IDE missed"
    goto End
)

set MCU_TOOLCHAIN=%IDE_PATH%\ide\tools\bin
if not exist %MCU_TOOLCHAIN%\ (
    echo "Error: MCU toolchain missed"
    goto End
)

rem This is an option. If the flashloader image folder is provided the build out image will be copied to there for burning purpose
set FLASHLOADER_IMAGE_DIR="D:\Project\Iwata\IXWW22\Tools\Flashloader_RT1170_1.0_EAR\Tools\mfgtools-rel\Profiles\MXRT117x\OS Firmware"

rem Source paths
set CURRENT_PATH=%cd%
set MCU_PATH=%CURRENT_PATH%\..
set BOOTLOADER_PATH=%MCU_PATH%\submodule\rt1172_bootloader
set BT_PATH=%MCU_PATH%\submodule\cyw89820
set BT_FLASH_ADDRESS_FILE=%MCU_PATH%\.cproject
set BT_VERSION_FILE=%BT_PATH%\RFCOMM-20820EVB02\rfcomm\spp\wiced_app.h

rem Pre-Build images
set MCU_PREBUILD_SYS_VALIDITY=%MCU_PATH%\bat\SYS_A_VALIDITY.srec
if not exist %MCU_PREBUILD_SYS_VALIDITY% (
    echo "Error: Pre-Build MCU system validity missed"
    goto End
)

set BT_PREBUILD_FIRMWARE=%BT_PATH%\Release_FW\BT_SPP_download.hex
if not exist %BT_PREBUILD_FIRMWARE% (
    echo "Error: Pre-Build BT firmware missed"
    goto End
)

set BT_PREBUILD_MINIDRIVER=%BT_PATH%\Release_FW\md_0.hex
if not exist %BT_PREBUILD_MINIDRIVER% (
    echo "Error: Pre-Build BT minidriver missed"
    goto End
)

rem Expected build out image
if %DEBUG_BUILD% equ 0 (
    set MCU_BUILD_IMAGE=%MCU_PATH%\Release\LinkCard-RT1172.axf
    set BOOTLOADER_BUILD_IMAGE=%BOOTLOADER_PATH%\Release\IXWW22_BLD.axf
) else (
    set MCU_BUILD_IMAGE=%MCU_PATH%\Debug\LinkCard-RT1172.axf
    set BOOTLOADER_BUILD_IMAGE=%BOOTLOADER_PATH%\Debug\IXWW22_BLD.axf
)
set BOOT_IMAGE=%CURRENT_PATH%\boot_image.bin
set OTA_IMAGE=%CURRENT_PATH%\BKA_UPDATE_FILE.bin

rem Image offsets
set /a BT_MINIDRIVER_OFFSET=0x100
set /a BT_FIRMWARE_OFFSET=-0x4f1500
set /a BOOT_IMAGE_OFFSET=-0x30000000

rem Get BT settings: Version
set /a BT_MAJOR_VERSION=-1
set /a BT_MINOR_VERSION=-1

for /f "tokens=3 delims= " %%x in ('findstr GARMIN_SW_MAJOR_VER %BT_VERSION_FILE%') do (
    if %%x lss 10 set /a BT_MAJOR_VERSION=%%x
)
if %BT_MAJOR_VERSION% lss 0 (
    echo "Error: BT major version not available"
    goto End
)

for /f "tokens=3 delims= " %%x in ('findstr GARMIN_SW_MINOR_VER %BT_VERSION_FILE%') do (
    if %%x lss 100 set /a BT_MINOR_VERSION=%%x
)
if %BT_MINOR_VERSION% lss 0 (
    echo "Error: BT minor version not available"
    goto End
)

set /a BT_VERSION="%BT_MAJOR_VERSION% << 8 | %BT_MINOR_VERSION% & 0xF"

rem Get BT settings: Minidriver size
set /a BT_MINIDRIVER_SIZE=0

for /f "skip=1 delims=*" %%x in (%BT_PREBUILD_MINIDRIVER%) do (
    set LINE=%%x
    set /a DATA_TYPE=0x!LINE:~7,2!
    if !DATA_TYPE! equ 0 (
        set /a DATA_LEN=0x!LINE:~1,2!
        set /a BT_MINIDRIVER_SIZE += !DATA_LEN!
    )
)
if %BT_MINIDRIVER_SIZE% leq 0 (
    echo "Error: BT minidriver size not available"
    goto End
)

rem Get BT settings: Firmware static section size
set /a BT_FIRMWARE_SS_SIZE=0

for /f "skip=1 delims=*" %%x in (%BT_PREBUILD_FIRMWARE%) do (
    set LINE=%%x
    set /a DATA_TYPE=0x!LINE:~7,2!
    if !DATA_TYPE! equ 0 (
        set /a DATA_LEN=0x!LINE:~1,2!
        set /a BT_FIRMWARE_SS_SIZE += !DATA_LEN!
        goto BT_Firmware_SS_Size_Acquired
    )
)
:BT_Firmware_SS_Size_Acquired
if %BT_FIRMWARE_SS_SIZE% leq 0 (
    echo "Error: BT firmware static section size not available"
    goto End
)

rem Get BT settings: Firmware data section size
set /a BT_FIRMWARE_DS_SIZE=0

for /f "skip=2 delims=*" %%x in (%BT_PREBUILD_FIRMWARE%) do (
    set LINE=%%x
    set /a DATA_TYPE=0x!LINE:~7,2!
    if !DATA_TYPE! equ 0 (
        set /a DATA_LEN=0x!LINE:~1,2!
        set /a BT_FIRMWARE_DS_SIZE += !DATA_LEN!
    )
)
if %BT_FIRMWARE_DS_SIZE% leq 0 (
    echo "Error: BT firmware data section size not available"
    goto End
)

rem Get BT settings: Flash address
set /a BT_FLASH_ADDRESS=-1

for /f "tokens=5 delims= " %%x in ('findstr BOARD_FLASH_BTFW %BT_FLASH_ADDRESS_FILE%') do (
    for /f "tokens=2 delims==" %%y in ("%%x") do (
        set /a BT_FLASH_ADDRESS=%%y
    )
)
if %BT_FLASH_ADDRESS% lss 0 (
    echo "Error: BT flash address not available"
    goto End
)

set /a BT_FLASH_VERSION_ADDRESS=%BT_FLASH_ADDRESS%
set /a BT_FLASH_VERSION_END_ADDRESS=%BT_FLASH_VERSION_ADDRESS% + 2

set /a BT_FLASH_MINIDRIVER_SIZE_ADDRESS=%BT_FLASH_VERSION_END_ADDRESS%
set /a BT_FLASH_MINIDRIVER_SIZE_END_ADDRESS=%BT_FLASH_MINIDRIVER_SIZE_ADDRESS% + 2

set /a BT_FLASH_FIRMWARE_SS_SIZE_ADDRESS=%BT_FLASH_MINIDRIVER_SIZE_END_ADDRESS%
set /a BT_FLASH_FIRMWARE_SS_SIZE_END_ADDRESS=%BT_FLASH_FIRMWARE_SS_SIZE_ADDRESS% + 2

set /a BT_FLASH_FIRMWARE_DS_SIZE_ADDRESS=%BT_FLASH_FIRMWARE_SS_SIZE_END_ADDRESS%
set /a BT_FLASH_FIRMWARE_DS_SIZE_END_ADDRESS=%BT_FLASH_FIRMWARE_DS_SIZE_ADDRESS% + 4

set /a BT_FLASH_FIRMWARE_SS_ADDRESS=-1
set /a BT_FLASH_FIRMWARE_DS_ADDRESS=-1
set /a LINE_NUM=0
set /a BT_FIRMWARE_UPPER_ADDRESS=-1
set /a BT_FIRMWARE_SS_LOWER_ADDRESS=-1
set /a BT_FIRMWARE_DS_LOWER_ADDRESS=-1
for /f "delims=*" %%x in (%BT_PREBUILD_FIRMWARE%) do (
    set LINE=%%x

    set /a LINE_NUM = !LINE_NUM! + 1
    if !LINE_NUM! equ 1 (
        set /a BT_FIRMWARE_UPPER_ADDRESS=0x!LINE:~9,4!
    )
    if !LINE_NUM! equ 2 (
        set /a BT_FIRMWARE_SS_LOWER_ADDRESS=0x!LINE:~3,4!
    )
    if !LINE_NUM! equ 3 (
        set /a BT_FIRMWARE_DS_LOWER_ADDRESS=0x!LINE:~3,4!
    )
    if !LINE_NUM! geq 4 (
        goto BT_Firmware_Address_Acquired
    )
)
:BT_Firmware_Address_Acquired
if %BT_FIRMWARE_UPPER_ADDRESS% lss 0 (
    echo "Error: BT firmware upper address not available"
    goto End
)
if %BT_FIRMWARE_SS_LOWER_ADDRESS% lss 0 (
    echo "Error: BT firmware static section lower address not available"
    goto End
)
if %BT_FIRMWARE_DS_LOWER_ADDRESS% lss 0 (
    echo "Error: BT firmware data section lower address not available"
    goto End
)

set /a BT_FLASH_MINIDRIVER_ADDRESS=%BT_FLASH_ADDRESS% + %BT_MINIDRIVER_OFFSET%
set /a BT_FLASH_FIRMWARE_SS_ADDRESS="( %BT_FIRMWARE_UPPER_ADDRESS% << 16 | %BT_FIRMWARE_SS_LOWER_ADDRESS% ) + %BT_FIRMWARE_OFFSET% + %BT_FLASH_MINIDRIVER_ADDRESS%"
set /a BT_FLASH_FIRMWARE_DS_ADDRESS="( %BT_FIRMWARE_UPPER_ADDRESS% << 16 | %BT_FIRMWARE_DS_LOWER_ADDRESS% ) + %BT_FIRMWARE_OFFSET% + %BT_FLASH_MINIDRIVER_ADDRESS%"

rem Display build info
echo --------------------------------- User Options ---------------------------------
echo Debug Build: %DEBUG_BUILD%
echo Clean Build: %CLEAN_BUILD%
echo OTA Build: %OTA_BUILD%
echo Metadata Folder: %MCU_METADATA_DIR%
echo ------------------------------ Build Environment -------------------------------
echo MCU IDE: %MCU_IDE%
echo MCU Toolchain: %MCU_TOOLCHAIN%
echo Flashloader Image Folder: %FLASHLOADER_IMAGE_DIR%
echo --------------------------------- BT Settings ----------------------------------
echo BT Major Version: %BT_MAJOR_VERSION%
echo BT Minor Version: %BT_MINOR_VERSION%
echo BT Flash Address: %BT_FLASH_ADDRESS%
echo BT Flash Minidriver Address: %BT_FLASH_MINIDRIVER_ADDRESS%
echo BT Flash Firmware Static Section Address: %BT_FLASH_FIRMWARE_SS_ADDRESS%
echo BT Flash Firmware Data Section Address: %BT_FLASH_FIRMWARE_DS_ADDRESS%
echo BT Minidriver Size: %BT_MINIDRIVER_SIZE% bytes
echo BT Firmware Static Section Size: %BT_FIRMWARE_SS_SIZE% bytes
echo BT Firmware Data Section Size: %BT_FIRMWARE_DS_SIZE% bytes
echo ------------------------------- Pre-Build Images -------------------------------
echo MCU System Validity: %MCU_PREBUILD_SYS_VALIDITY%
echo BT Firmware: %BT_PREBUILD_FIRMWARE%
echo BT Minidriver: %BT_PREBUILD_MINIDRIVER%
echo --------------------------- Expected Build Out Images --------------------------
echo MCU Image: %MCU_BUILD_IMAGE%
echo Bootloader Image: %BOOTLOADER_BUILD_IMAGE%
echo Boot Image: %BOOT_IMAGE%
echo OTA Image: %OTA_IMAGE%
echo --------------------------------------------------------------------------------

echo %PATH%|findstr /i /c:"%MCU_TOOLCHAIN:"=%">nul || set PATH=%PATH%;%MCU_TOOLCHAIN%
echo %PATH%|findstr /i /c:"%BT_TOOLCHAIN:"=%">nul || set PATH=%PATH%;%BT_TOOLCHAIN%

if exist %MCU_BUILD_IMAGE% del %MCU_BUILD_IMAGE%
if exist %BOOTLOADER_BUILD_IMAGE% del %BOOTLOADER_BUILD_IMAGE%
if exist %BOOT_IMAGE% del %BOOT_IMAGE%
if exist %OTA_IMAGE% del %OTA_IMAGE%

if %DEBUG_BUILD% equ 0 (
    set MCU_DEBUG_BUILD_MODE=Release
) else (
    set MCU_DEBUG_BUILD_MODE=Debug
)

if %CLEAN_BUILD% equ 0 (
    if not exist %MCU_METADATA_DIR%\ mkdir %MCU_METADATA_DIR%
    set MCU_CLEAN_BUILD_MODE=build
) else (
    if exist %MCU_METADATA_DIR%\ rmdir /s /q %MCU_METADATA_DIR%
    mkdir %MCU_METADATA_DIR%
    set MCU_CLEAN_BUILD_MODE=cleanBuild
)

echo --------------------------------------------------------------------------------
echo Start building MCU...
echo --------------------------------------------------------------------------------
%MCU_IDE%\mcuxpressoidec.exe -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import %MCU_PATH% -%MCU_CLEAN_BUILD_MODE% LinkCard-RT1172/%MCU_DEBUG_BUILD_MODE% -data %MCU_METADATA_DIR%
if not exist %MCU_BUILD_IMAGE% goto End

echo --------------------------------------------------------------------------------
echo Start building bootloader...
echo --------------------------------------------------------------------------------
%MCU_IDE%\mcuxpressoidec.exe -nosplash --launcher.suppressErrors -application org.eclipse.cdt.managedbuilder.core.headlessbuild -printErrorMarkers -import %BOOTLOADER_PATH% -%MCU_CLEAN_BUILD_MODE% IXWW22_BLD/%MCU_DEBUG_BUILD_MODE% -data %MCU_METADATA_DIR%
if not exist %BOOTLOADER_BUILD_IMAGE% goto End

echo --------------------------------------------------------------------------------
echo Merge MCU, bootloader and BT to one single boot image: %BOOT_IMAGE%...
echo --------------------------------------------------------------------------------
if exist temp\ rmdir /s /q temp
mkdir temp

arm-none-eabi-objcopy -v -O srec %MCU_BUILD_IMAGE% temp\LinkCard-RT1172.srec
arm-none-eabi-objcopy -v -O srec %BOOTLOADER_BUILD_IMAGE% temp\IXWW22_BLD.srec

srec_cat.exe %BT_PREBUILD_FIRMWARE% -Intel -offset %BT_FIRMWARE_OFFSET% -o temp\BT_flash.hex -Intel
srec_cat.exe temp\BT_flash.hex -Intel %BT_PREBUILD_MINIDRIVER% -Intel -o temp\BT_mdflash.bin -Binary

rem Merge Bootloader+APP+BT firmware+VALIDITY for development ECU that no signature and encryption are used
srec_cat.exe temp\IXWW22_BLD.srec -M temp\LinkCard-RT1172.srec -M ^
    -GEN %BT_FLASH_VERSION_ADDRESS% %BT_FLASH_VERSION_END_ADDRESS% -CONSTant_Big_Endian %BT_VERSION% 2 ^
    -GEN %BT_FLASH_MINIDRIVER_SIZE_ADDRESS% %BT_FLASH_MINIDRIVER_SIZE_END_ADDRESS% -CONSTant_Big_Endian %BT_MINIDRIVER_SIZE% 2 ^
    -GEN %BT_FLASH_FIRMWARE_SS_SIZE_ADDRESS% %BT_FLASH_FIRMWARE_SS_SIZE_END_ADDRESS% -CONSTant_Big_Endian %BT_FIRMWARE_SS_SIZE% 2 ^
    -GEN %BT_FLASH_FIRMWARE_DS_SIZE_ADDRESS% %BT_FLASH_FIRMWARE_DS_SIZE_END_ADDRESS% -CONSTant_Big_Endian %BT_FIRMWARE_DS_SIZE% 4 ^
    temp\BT_mdflash.bin -Binary -offset %BT_FLASH_MINIDRIVER_ADDRESS% %MCU_PREBUILD_SYS_VALIDITY% -M -O temp\boot_image.srec -M -header=boot_image -line_length=46 -disable=data-count
srec_cat.exe temp\boot_image.srec -M -offset %BOOT_IMAGE_OFFSET% -O %BOOT_IMAGE% -Binary

if %OTA_BUILD% equ 1 (
    rem Merge the APP and BT firmware firstly and fill the data gap, the merged file will be used for OTA file generation(For development ECU that no signature and encryption are used)
    srec_cat.exe temp\LinkCard-RT1172.srec -M ^
        -GEN %BT_FLASH_VERSION_ADDRESS% %BT_FLASH_VERSION_END_ADDRESS% -CONSTant_Big_Endian %BT_VERSION% 2 ^
        -GEN %BT_FLASH_MINIDRIVER_SIZE_ADDRESS% %BT_FLASH_MINIDRIVER_SIZE_END_ADDRESS% -CONSTant_Big_Endian %BT_MINIDRIVER_SIZE% 2 ^
        -GEN %BT_FLASH_FIRMWARE_SS_SIZE_ADDRESS% %BT_FLASH_FIRMWARE_SS_SIZE_END_ADDRESS% -CONSTant_Big_Endian %BT_FIRMWARE_SS_SIZE% 2 ^
        -GEN %BT_FLASH_FIRMWARE_DS_SIZE_ADDRESS% %BT_FLASH_FIRMWARE_DS_SIZE_END_ADDRESS% -CONSTant_Big_Endian %BT_FIRMWARE_DS_SIZE% 4 ^
        temp\BT_mdflash.bin -Binary -offset %BT_FLASH_MINIDRIVER_ADDRESS% -O temp\LinkCard-RT1172_BT.srec -M -header=LinkCard-RT1172_BT -line_length=46 -disable=data-count
    srec_cat.exe temp\LinkCard-RT1172_BT.srec -fill 0x00 0x30202000 %BT_FIRMWARE_ADDRESS% -O temp\LinkCard-RT1172_BT.srec -M -header=LinkCard-RT1172_BT -line_length=46 -disable=data-count
    python3 IXWW22_OTA_FILE_GEN.py temp\LinkCard-RT1172_BT.srec %OTA_IMAGE%
)

set BUILD_SUCCESS=true
if not ""%FLASHLOADER_IMAGE_DIR%""=="" if exist %FLASHLOADER_IMAGE_DIR%\ (
    echo Copy image to Flashloader...
    copy %BOOT_IMAGE% %FLASHLOADER_IMAGE_DIR%
)

:End
if exist temp\ rmdir /s /q temp

if "%BUILD_SUCCESS%"=="true" (
    echo --------------------------------------------------------------------------------
    echo Build Success
    echo --------------------------------------------------------------------------------
    exit /b 0
) else (
    echo --------------------------------------------------------------------------------
    echo Build Failure
    echo --------------------------------------------------------------------------------
    exit /b -1
)

:Usage
echo "Usage: %0 <metadata_folder> [-debug] [-no-clean] [-no-ota]"
echo     - metadata_folder: The build process requires a folder to store the metadata generated during building.
echo     - debug: Default is release build. This is an option for debug build.
echo     - no-clean: Default is clean build. This is an option for non-clean build. To do this it requires the
echo                 metadata folder that contains the metadata generated in previous build. And unlikely clean
echo                 build it will not remove the metadata folder at the end of building.
echo     - no-ota: OTA image will be build out by default. This is an option to build without OTA image.
exit /b -1
