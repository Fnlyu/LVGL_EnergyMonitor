/**
 * @file bottom_key_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bottom_key_bar_gen.h"
#include "../../ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * bottom_key_bar_create(lv_obj_t * parent, const char * left_text, const char * center_text, const char * right_text)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bottom_bar;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_ok;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_bottom_bar);
        lv_style_set_bg_color(&style_bottom_bar, lv_color_hex(0x111827));
        lv_style_set_border_width(&style_bottom_bar, 0);
        lv_style_set_radius(&style_bottom_bar, 0);
        lv_style_set_pad_all(&style_bottom_bar, 0);

        lv_style_init(&style_text_muted);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x8fa3bf));
        lv_style_set_text_font(&style_text_muted, font_cn_12);

        lv_style_init(&style_text_ok);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_12);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "bottom_key_bar_#");
    lv_obj_set_width(lv_obj_0, 240);
    lv_obj_set_height(lv_obj_0, 22);

    lv_obj_add_style(lv_obj_0, &style_bottom_bar, 0);
    lv_obj_t * label_key_left = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_key_left, "label_key_left");
    lv_obj_set_x(label_key_left, 8);
    lv_obj_set_y(label_key_left, 5);
    lv_label_set_text(label_key_left, left_text);
    lv_obj_add_style(label_key_left, &style_text_muted, 0);
    
    lv_obj_t * label_key_center = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_key_center, "label_key_center");
    lv_obj_set_x(label_key_center, 92);
    lv_obj_set_y(label_key_center, 5);
    lv_label_set_text(label_key_center, center_text);
    lv_obj_add_style(label_key_center, &style_text_muted, 0);
    
    lv_obj_t * label_page_index = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_page_index, "label_page_index");
    lv_obj_set_x(label_page_index, 196);
    lv_obj_set_y(label_page_index, 5);
    lv_label_set_text(label_page_index, right_text);
    lv_obj_add_style(label_page_index, &style_text_ok, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

