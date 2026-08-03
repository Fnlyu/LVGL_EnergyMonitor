/**
 * @file screen_circuits_gen.h
 */

#ifndef SCREEN_CIRCUITS_H
#define SCREEN_CIRCUITS_H

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
    SCREEN_CIRCUITS_TIMELINE_SCREEN_OPEN = 0,
    _SCREEN_CIRCUITS_TIMELINE_CNT = 1
}screen_circuits_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * screen_circuits_create(void);

/**
 * Get a timeline of a screen_circuits
 * @param obj          pointer to a screen_circuits component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * screen_circuits_get_timeline(lv_obj_t * obj, screen_circuits_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SCREEN_CIRCUITS_H*/