/**
 * @file top_status_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "top_status_bar_gen.h"
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

lv_obj_t * top_status_bar_create(lv_obj_t * parent, const char * title_text, const char * time_text, const char * comm_text, const char * comm_ok)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_top_bar;
    static lv_style_t style_text_title;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_ok;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_top_bar);
        lv_style_set_bg_color(&style_top_bar, lv_color_hex(0x0b1118));
        lv_style_set_border_color(&style_top_bar, lv_color_hex(0x172331));
        lv_style_set_border_width(&style_top_bar, 0);
        lv_style_set_radius(&style_top_bar, 0);
        lv_style_set_pad_all(&style_top_bar, 0);

        lv_style_init(&style_text_title);
        lv_style_set_text_color(&style_text_title, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_text_title, font_cn_18);

        lv_style_init(&style_text_muted);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x8fa3bf));
        lv_style_set_text_font(&style_text_muted, font_cn_14);

        lv_style_init(&style_text_ok);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_14);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "top_status_bar_#");
    lv_obj_set_width(lv_obj_0, 240);
    lv_obj_set_height(lv_obj_0, 32);

    lv_obj_add_style(lv_obj_0, &style_top_bar, 0);
    lv_obj_t * label_title = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_title, "label_title");
    lv_obj_set_x(label_title, 8);
    lv_obj_set_y(label_title, 6);
    lv_label_set_text(label_title, title_text);
    lv_obj_add_style(label_title, &style_text_title, 0);
    
    lv_obj_t * label_time = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_time, "label_time");
    lv_obj_set_x(label_time, 142);
    lv_obj_set_y(label_time, 9);
    lv_label_set_text(label_time, time_text);
    lv_obj_add_style(label_time, &style_text_muted, 0);
    
    lv_obj_t * label_comm_dot = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_comm_dot, "label_comm_dot");
    lv_obj_set_x(label_comm_dot, 184);
    lv_obj_set_y(label_comm_dot, 9);
    lv_label_set_text(label_comm_dot, comm_ok);
    lv_obj_add_style(label_comm_dot, &style_text_ok, 0);
    
    lv_obj_t * label_wifi_top_status = lv_label_create(lv_obj_0);
    lv_obj_set_name(label_wifi_top_status, "label_wifi_top_status");
    lv_obj_set_x(label_wifi_top_status, 202);
    lv_obj_set_y(label_wifi_top_status, 9);
    lv_label_set_text(label_wifi_top_status, comm_text);
    lv_obj_add_style(label_wifi_top_status, &style_text_muted, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

