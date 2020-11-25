/*********************************************************************
*
*   HEADER NAME:
*       GRM_pub_prj.h - generic definitions (for project wide usage)
*
* Copyright 2008-2020 by Garmin Ltd. or its subsidiaries.
*---------------------------------------------------------------------
* $Log$
* $NoKeywords$
*********************************************************************/


#ifndef GRM_PUB_PRJ_H
#define GRM_PUB_PRJ_H

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define SW_VERSION                                      102

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

enum task_priorities
    {
    TASK_PRIO_IDLE                = tskIDLE_PRIORITY,
    TASK_PRIO_BURN_IN,
    TASK_PRIO_FAC_TEST,
    TASK_PRIO_DISPLAY,
    TASK_PRIO_WATCH_DOG           = TASK_PRIO_DISPLAY,
    TASK_PRIO_BT_MNGR,
    TASK_PRIO_I2C,
    TASK_PRIO_JPEG,
    TASK_PRIO_VEHICLE_INFO_MNGR,
    TASK_PRIO_MEDIA_MNGR          = TASK_PRIO_VEHICLE_INFO_MNGR,
    TASK_PRIO_NOTIFICATION_CENTER = TASK_PRIO_VEHICLE_INFO_MNGR,
    TASK_PRIO_NAVIGATION_MNGR     = TASK_PRIO_VEHICLE_INFO_MNGR,
    TASK_PRIO_EMBEDDED_WIZARD     = TASK_PRIO_VEHICLE_INFO_MNGR,
    TASK_PRIO_BT_HCI              = TASK_PRIO_VEHICLE_INFO_MNGR,
    TASK_PRIO_CAN,
    TASK_PRIO_UART,
    TASK_PRIO_PM,
    TASK_PRIO_MAX                 = TASK_PRIO_PM,
    };

#if TASK_PRIO_MAX > 16
    #error TASK_PRIO_MAX must be less than configMAX_PRIORITIES.
#endif

#endif /* GRM_PUB_PRJ_H */
