/**
 * @file ui_gen.h
 */

#ifndef UI_GEN_H
#define UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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



/* Prototypes for target functions, needed by responsive const definitions */

void ui_set_target(uint32_t target);
uint32_t ui_get_target(void);
bool ui_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define UI_TARGET_UNDEFINED  (0 << 1)
#define UI_TARGET_TARGET1    (1 << 1)
#define UI_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef UI_COMPILE_TARGET
#define UI_COMPILE_TARGET UI_TARGET_ALL
#endif

#define UI_CHECK_COMPILE_TARGET(target) (UI_COMPILE_TARGET & (target) ? 1 : 0)

#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_cn_12;
extern lv_font_t * font_cn_14;
extern lv_font_t * font_cn_16;
extern lv_font_t * font_cn_18;
extern lv_font_t * font_cn_20;
extern lv_font_t * font_cn_24;
extern lv_font_t * font_cn_34;


/*----------------
 * Images
 *----------------*/



/*----------------
 * Subjects
 *----------------*/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/bottom_key_bar/bottom_key_bar_gen.h"
#include "components/top_status_bar/top_status_bar_gen.h"
#include "screens/screen_alarms_gen.h"
#include "screens/screen_bill_gen.h"
#include "screens/screen_chart_gen.h"
#include "screens/screen_circuits_gen.h"
#include "screens/screen_energy_gen.h"
#include "screens/screen_home_gen.h"
#include "screens/screen_voltage_gen.h"
#include "screens/screen_wifi_gen.h"
#include "screens/screen_wt3213_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_GEN_H*/