/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   This template is responsible to configurate the entire system (CPU clock,
*   memory, qspi, etc).
*
*******************************************************************************/

#include "board.h"
#include "pin_mux.h"

#include "ewconfig.h"
#include "ew_bsp_system.h"
#include "ew_bsp_clock.h"
#include "fsl_cache.h"
#include "fsl_debug_console.h"
extern void boot_sdram_config(void);


/*******************************************************************************
* FUNCTION:
*   EwBspSystemInit
*
* DESCRIPTION:
*   The function EwBspSystemInit initializes the system components.
*   (CPU clock, memory, qspi, ...)
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemInit( void )
{
  /* Init board hardware. */
  BOARD_ConfigMPU();
  BOARD_BootClockRUN();
  BOARD_InitLpuartPins();
  BOARD_InitMipiPanelPins();
  BOARD_MIPIPanelTouch_I2C_Init();
  BOARD_InitDebugConsole();


  boot_sdram_config();
}


/*******************************************************************************
* FUNCTION:
*   EwBspSystemDone
*
* DESCRIPTION:
*   The function EwBspSystemDone terminates the system components.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemDone( void )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspSystemDataCacheCleanByRange
*
* DESCRIPTION:
*   The function EwBspSystemDataCacheCleanByRange cleans the data cache in the
*   given range.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspSystemDataCacheCleanByRange( void * aAddr, unsigned int aSize )
{
  L1CACHE_CleanDCacheByRange(( uint32_t ) aAddr, aSize );
}



/* msy, mli */
