/**
 * @file screen_alarms_gen.h
 */

#ifndef SCREEN_ALARMS_H
#define SCREEN_ALARMS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    SCREEN_ALARMS_TIMELINE_SCREEN_OPEN = 0,
    _SCREEN_ALARMS_TIMELINE_CNT = 1
}screen_alarms_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * screen_alarms_create(void);

/**
 * Get a timeline of a screen_alarms
 * @param obj          pointer to a screen_alarms component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * screen_alarms_get_timeline(lv_obj_t * obj, screen_alarms_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SCREEN_ALARMS_H*/