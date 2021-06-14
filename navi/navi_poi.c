/*********************************************************************
* @file
* navi_poi.c
*
* @brief
* Navi module - Handle Fav?gas list.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVI_pub.h"
#include "navi_priv.h"
#include "NAVILITE_pub.h"
#include "error_code.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

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
static SemaphoreHandle_t poi_semphr_hndl;
static int32_t ticks_to_wait = pdMS_TO_TICKS( 500 );
static uint16_t num_of_poi_list_item = 0;
static navi_poi_data_type navi_poi_buffer[MAX_POI_SIZE];
static int poi_buffer_idx = 0;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* navi_add_poi_item
*
* Add navi poi item to navi tbt buffer.
*
*********************************************************************/
void navi_add_poi_item
    (
    navilite_poi_list_type* poi_list_item
    )
{
if( pdTRUE == xSemaphoreTake( poi_semphr_hndl, ticks_to_wait ) )
    {

    if( poi_buffer_idx >= 0 &&
        poi_buffer_idx < MAX_POI_SIZE )
        {
        memcpy( navi_poi_buffer[poi_buffer_idx].description, poi_list_item->desc, MAX_POI_DESCRIPTION_SIZE );
        if( poi_list_item->desc_size < MAX_POI_DESCRIPTION_SIZE )
            {
            navi_poi_buffer[poi_buffer_idx].description[poi_list_item->desc_size] = '\0';
            }
        else
            {
            navi_poi_buffer[poi_buffer_idx].description[MAX_POI_DESCRIPTION_SIZE-1] = '\0';
            }

        memcpy( navi_poi_buffer[poi_buffer_idx].dist_unit, poi_list_item->distance_unit, MAX_POI_DIST_UNIT_SIZE );
        if( poi_list_item->dist_unit_size < MAX_POI_DIST_UNIT_SIZE )
            {
            navi_poi_buffer[poi_buffer_idx].dist_unit[poi_list_item->dist_unit_size] = '\0';
            }
        else
            {
            navi_poi_buffer[poi_buffer_idx].dist_unit[MAX_POI_DIST_UNIT_SIZE-1] = '\0';
            }

        navi_poi_buffer[poi_buffer_idx].distance = NAVILITE_bytes_to_float( poi_list_item->distance );
        navi_poi_buffer[poi_buffer_idx].list_idx = poi_list_item->list_item_index;

        if( poi_buffer_idx < num_of_poi_list_item )
            {
            poi_buffer_idx++;
            }
        EW_notify_poi_list_update();
        }
    xSemaphoreGive( poi_semphr_hndl );
    }
else
    {
    PRINTF( "%s: Semaphore is hold by another task\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* NAVI_reset_poi_buffer
*
* Reset Poi buffer.
*
*********************************************************************/
void NAVI_reset_poi_buffer
    (
    void
    )
{
if( pdTRUE == xSemaphoreTake( poi_semphr_hndl, ticks_to_wait ) )
    {
    PRINTF( "%s\r\n", __FUNCTION__ );
    for( int i = 0; i < MAX_POI_SIZE; i++ )
        {
        navi_poi_buffer[i].list_idx = 0;
        navi_poi_buffer[i].distance = 0.0;
        memset( navi_poi_buffer[i].dist_unit, 0, MAX_POI_DIST_UNIT_SIZE );
        memset( navi_poi_buffer[i].description, 0, MAX_POI_DESCRIPTION_SIZE );
        }
    num_of_poi_list_item = 0;
    poi_buffer_idx = 0;
    xSemaphoreGive( poi_semphr_hndl );
    }
}

/*********************************************************************
*
* @public
* NAVI_get_poi_item
*
* Get navi fav/gas item from navi poi buffer.
*
*********************************************************************/
bool NAVI_get_poi_item
    (
    const int poi_index,
    float* distance,
    char** dist_unit,
    char** description
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
if( pdTRUE == xSemaphoreTake( poi_semphr_hndl, ticks_to_wait ) )
    {
    if( poi_index < MAX_POI_SIZE )
        {
        *distance = navi_poi_buffer[poi_index].distance;
        *dist_unit = navi_poi_buffer[poi_index].dist_unit;
        *description = navi_poi_buffer[poi_index].description;
        }
    xSemaphoreGive( poi_semphr_hndl );
    }
return res;
}

/*********************************************************************
*
* @private
* navi_notify_more_poi_item
*
* Notify if there are more fav/gas items after the request this time.
*
* @param poi_list_size        Poi list size.
*
*********************************************************************/
void navi_notify_more_poi_item
    (
    const uint16_t poi_list_size
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );

// Reset the whole poi buffer, this is because the whole data currently stored in poi buffer should be replaced with the new data.
NAVI_reset_poi_buffer();
num_of_poi_list_item = poi_list_size;
}

/*********************************************************************
*
* @private
* navi_get_poi_list_index
*
*********************************************************************/
uint32_t navi_get_poi_list_index
    (
    uint32_t item_idx
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return navi_poi_buffer[item_idx].list_idx;
}

/*********************************************************************
*
* @public
* NAVI_get_poi_list_size
*
* Return fav/gas list size
*
*********************************************************************/
uint16_t NAVI_get_poi_list_size
    (
    void
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, num_of_poi_list_item );
return num_of_poi_list_item;
}

/*********************************************************************
*
* @public
* NAVI_poi_list_request
*
* Send Poi list request to navi app via navilite API
*
* @param poi_list_type        Poi list type.
* @param is_enabled           Start/Stop update the requested content.
*
*********************************************************************/
void NAVI_poi_list_request
    (
    EnumNaviPoiListType poi_list_type,
    bool is_enabled
    )
{
PRINTF( "%s: List Type: %d, Status:%d\r\n", __FUNCTION__, poi_list_type, is_enabled );
bool result = false;
switch( poi_list_type )
    {
    case EnumNaviPoiListTypeFAVORITE:
        result = NAVILITE_request_app_enable_content_update( NAVILITE_CONTENT_TYPE_FAVORITE_LIST, is_enabled );
        break;
    case EnumNaviPoiListTypeGAS_STATION:
        result = NAVILITE_request_app_enable_content_update( NAVILITE_CONTENT_TYPE_GASSTATION_LIST, is_enabled );
        break;
    default:
        break;
    }

if( !is_enabled )
    {
    NAVI_reset_poi_buffer();
    }

if( !result )
    {
    PRINTF( "%s : navilite API request error\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @private
* navi_poi_init
*
* Initialize navi poi list
*
*********************************************************************/
void navi_poi_init
    (
    void
    )
{
poi_semphr_hndl = xSemaphoreCreateBinary();
configASSERT( NULL != poi_semphr_hndl );
xSemaphoreGive( poi_semphr_hndl );
NAVI_reset_poi_buffer();
}

