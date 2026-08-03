/**
 * @file screen_bill_gen.h
 */

#ifndef SCREEN_BILL_H
#define SCREEN_BILL_H

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
    SCREEN_BILL_TIMELINE_SCREEN_OPEN = 0,
    _SCREEN_BILL_TIMELINE_CNT = 1
}screen_bill_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * screen_bill_create(void);

/**
 * Get a timeline of a screen_bill
 * @param obj          pointer to a screen_bill component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * screen_bill_get_timeline(lv_obj_t * obj, screen_bill_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SCREEN_BILL_H*/