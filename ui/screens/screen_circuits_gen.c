/**
 * @file screen_circuits_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_circuits_gen.h"
#include "../ui.h"

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

static lv_anim_timeline_t * timeline_screen_open_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_circuits_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card;
    static lv_style_t style_card_focused;
    static lv_style_t style_text_normal;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_value;
    static lv_style_t style_text_ok;
    static lv_style_t style_text_fail;
    static lv_style_t style_text_warn;
    static lv_style_t style_text_alarm;
    static lv_style_t style_alarm_bar;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen_bg);
        lv_style_init(&style_card);
        lv_style_init(&style_card_focused);
        lv_style_init(&style_text_normal);
        lv_style_init(&style_text_muted);
        lv_style_init(&style_text_value);
        lv_style_init(&style_text_ok);
        lv_style_init(&style_text_fail);
        lv_style_init(&style_text_warn);
        lv_style_init(&style_text_alarm);
        lv_style_init(&style_alarm_bar);

        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x05070a));
        lv_style_set_bg_color(&style_card, lv_color_hex(0x101821));
        lv_style_set_border_color(&style_card, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_card, 1);
        lv_style_set_radius(&style_card, 8);
        lv_style_set_pad_all(&style_card, 0);
        lv_style_set_border_width(&style_card_focused, 2);
        lv_style_set_border_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_border_opa(&style_card_focused, 255);
        lv_style_set_shadow_width(&style_card_focused, 8);
        lv_style_set_shadow_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_shadow_opa(&style_card_focused, 90);
        lv_style_set_radius(&style_card_focused, 12);
        lv_style_set_text_color(&style_text_normal, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_text_normal, font_cn_12);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x8fa3bf));
        lv_style_set_text_font(&style_text_muted, font_cn_12);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x4dd4ff));
        lv_style_set_text_font(&style_text_value, font_cn_16);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_12);
        lv_style_set_text_color(&style_text_fail, lv_color_hex(0xff6b6b));
        lv_style_set_text_font(&style_text_fail, font_cn_12);
        lv_style_set_text_color(&style_text_warn, lv_color_hex(0xffd166));
        lv_style_set_text_font(&style_text_warn, font_cn_12);
        lv_style_set_text_color(&style_text_alarm, lv_color_hex(0xff6b6b));
        lv_style_set_text_font(&style_text_alarm, font_cn_12);
        lv_style_set_bg_color(&style_alarm_bar, lv_color_hex(0x331a1a));
        lv_style_set_border_color(&style_alarm_bar, lv_color_hex(0xff6b6b));
        lv_style_set_border_width(&style_alarm_bar, 1);
        lv_style_set_radius(&style_alarm_bar, 6);
        lv_style_set_pad_all(&style_alarm_bar, 4);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_circuits_#");

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "支路监测", "12:30", "WiFi", "●");
        lv_obj_set_name(top_bar, "top_bar");
        lv_obj_set_x(top_bar, 0);
        lv_obj_set_y(top_bar, 0);
        lv_obj_set_style_opa(top_bar, 0, 0);
        lv_obj_set_style_translate_y(top_bar, -20, 0);

        lv_obj_t * alarm_bar = lv_obj_create(lv_obj_0);
        lv_obj_set_name(alarm_bar, "alarm_bar");
        lv_obj_set_x(alarm_bar, 10);
        lv_obj_set_y(alarm_bar, 38);
        lv_obj_set_width(alarm_bar, 220);
        lv_obj_set_height(alarm_bar, 24);
        lv_obj_set_flag(alarm_bar, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_opa(alarm_bar, 0, 0);
        lv_obj_set_style_translate_y(alarm_bar, -10, 0);
        lv_obj_add_style(alarm_bar, &style_alarm_bar, 0);
        lv_obj_t * alarm_text = lv_label_create(alarm_bar);
        lv_obj_set_name(alarm_text, "alarm_text");
        lv_obj_set_x(alarm_text, 4);
        lv_obj_set_y(alarm_text, 0);
        lv_label_set_text(alarm_text, "⚠ 厨房回路断电！");
        lv_obj_add_style(alarm_text, &style_text_alarm, 0);

        lv_obj_t * list_container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(list_container, "list_container");
        lv_obj_set_x(list_container, 10);
        lv_obj_set_y(list_container, 68);
        lv_obj_set_width(list_container, 220);
        lv_obj_set_height(list_container, 142);
        lv_obj_set_flag(list_container, LV_OBJ_FLAG_SCROLLABLE, true);
        lv_obj_set_style_opa(list_container, 0, 0);
        lv_obj_set_style_translate_x(list_container, -35, 0);
        lv_obj_set_style_bg_opa(list_container, 0, 0);
        lv_obj_set_style_border_width(list_container, 0, 0);
        lv_obj_set_style_pad_all(list_container, 0, 0);
        lv_obj_set_style_pad_row(list_container, 4, 0);
        lv_obj_t * circuit_1 = lv_obj_create(list_container);
        lv_obj_set_name(circuit_1, "circuit_1");
        lv_obj_set_x(circuit_1, 0);
        lv_obj_set_y(circuit_1, 0);
        lv_obj_set_width(circuit_1, 220);
        lv_obj_set_height(circuit_1, 50);
        lv_obj_set_flag(circuit_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(circuit_1, &style_card, 0);
        lv_obj_add_style(circuit_1, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_label_0 = lv_label_create(circuit_1);
        lv_obj_set_x(lv_label_0, 6);
        lv_obj_set_y(lv_label_0, 2);
        lv_label_set_text(lv_label_0, "客厅");
        lv_obj_add_style(lv_label_0, &style_text_normal, 0);

        lv_obj_t * label_power_1 = lv_label_create(circuit_1);
        lv_obj_set_name(label_power_1, "label_power_1");
        lv_obj_set_x(label_power_1, 140);
        lv_obj_set_y(label_power_1, 2);
        lv_label_set_text(label_power_1, "0.85KW");
        lv_obj_add_style(label_power_1, &style_text_value, 0);

        lv_obj_t * lv_label_1 = lv_label_create(circuit_1);
        lv_obj_set_x(lv_label_1, 6);
        lv_obj_set_y(lv_label_1, 22);
        lv_label_set_text(lv_label_1, "今日用电");
        lv_obj_add_style(lv_label_1, &style_text_muted, 0);

        lv_obj_t * label_energy_1 = lv_label_create(circuit_1);
        lv_obj_set_name(label_energy_1, "label_energy_1");
        lv_obj_set_x(label_energy_1, 68);
        lv_obj_set_y(label_energy_1, 22);
        lv_label_set_text(label_energy_1, "3.2KWh");
        lv_obj_add_style(label_energy_1, &style_text_muted, 0);

        lv_obj_t * lv_label_2 = lv_label_create(circuit_1);
        lv_obj_set_x(lv_label_2, 140);
        lv_obj_set_y(lv_label_2, 22);
        lv_label_set_text(lv_label_2, "峰值");
        lv_obj_add_style(lv_label_2, &style_text_muted, 0);

        lv_obj_t * label_peak_1 = lv_label_create(circuit_1);
        lv_obj_set_name(label_peak_1, "label_peak_1");
        lv_obj_set_x(label_peak_1, 178);
        lv_obj_set_y(label_peak_1, 22);
        lv_label_set_text(label_peak_1, "1.2KW");
        lv_obj_add_style(label_peak_1, &style_text_muted, 0);

        lv_obj_t * lv_label_3 = lv_label_create(circuit_1);
        lv_obj_set_x(lv_label_3, 6);
        lv_obj_set_y(lv_label_3, 38);
        lv_label_set_text(lv_label_3, "断路器");
        lv_obj_add_style(lv_label_3, &style_text_muted, 0);

        lv_obj_t * label_status_1 = lv_label_create(circuit_1);
        lv_obj_set_name(label_status_1, "label_status_1");
        lv_obj_set_x(label_status_1, 66);
        lv_obj_set_y(label_status_1, 38);
        lv_label_set_text(label_status_1, "● 闭合");
        lv_obj_add_style(label_status_1, &style_text_ok, 0);

        lv_obj_t * circuit_2 = lv_obj_create(list_container);
        lv_obj_set_name(circuit_2, "circuit_2");
        lv_obj_set_x(circuit_2, 0);
        lv_obj_set_y(circuit_2, 54);
        lv_obj_set_width(circuit_2, 220);
        lv_obj_set_height(circuit_2, 50);
        lv_obj_set_flag(circuit_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(circuit_2, &style_card, 0);
        lv_obj_add_style(circuit_2, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_label_4 = lv_label_create(circuit_2);
        lv_obj_set_x(lv_label_4, 6);
        lv_obj_set_y(lv_label_4, 2);
        lv_label_set_text(lv_label_4, "卧室");
        lv_obj_add_style(lv_label_4, &style_text_normal, 0);

        lv_obj_t * label_power_2 = lv_label_create(circuit_2);
        lv_obj_set_name(label_power_2, "label_power_2");
        lv_obj_set_x(label_power_2, 140);
        lv_obj_set_y(label_power_2, 2);
        lv_label_set_text(label_power_2, "0.42KW");
        lv_obj_add_style(label_power_2, &style_text_value, 0);

        lv_obj_t * lv_label_5 = lv_label_create(circuit_2);
        lv_obj_set_x(lv_label_5, 6);
        lv_obj_set_y(lv_label_5, 22);
        lv_label_set_text(lv_label_5, "今日用电");
        lv_obj_add_style(lv_label_5, &style_text_muted, 0);

        lv_obj_t * label_energy_2 = lv_label_create(circuit_2);
        lv_obj_set_name(label_energy_2, "label_energy_2");
        lv_obj_set_x(label_energy_2, 68);
        lv_obj_set_y(label_energy_2, 22);
        lv_label_set_text(label_energy_2, "1.8KWh");
        lv_obj_add_style(label_energy_2, &style_text_muted, 0);

        lv_obj_t * lv_label_6 = lv_label_create(circuit_2);
        lv_obj_set_x(lv_label_6, 140);
        lv_obj_set_y(lv_label_6, 22);
        lv_label_set_text(lv_label_6, "峰值");
        lv_obj_add_style(lv_label_6, &style_text_muted, 0);

        lv_obj_t * label_peak_2 = lv_label_create(circuit_2);
        lv_obj_set_name(label_peak_2, "label_peak_2");
        lv_obj_set_x(label_peak_2, 178);
        lv_obj_set_y(label_peak_2, 22);
        lv_label_set_text(label_peak_2, "0.6KW");
        lv_obj_add_style(label_peak_2, &style_text_muted, 0);

        lv_obj_t * lv_label_7 = lv_label_create(circuit_2);
        lv_obj_set_x(lv_label_7, 6);
        lv_obj_set_y(lv_label_7, 38);
        lv_label_set_text(lv_label_7, "断路器");
        lv_obj_add_style(lv_label_7, &style_text_muted, 0);

        lv_obj_t * label_status_2 = lv_label_create(circuit_2);
        lv_obj_set_name(label_status_2, "label_status_2");
        lv_obj_set_x(label_status_2, 66);
        lv_obj_set_y(label_status_2, 38);
        lv_label_set_text(label_status_2, "● 断开");
        lv_obj_add_style(label_status_2, &style_text_fail, 0);

        lv_obj_t * circuit_3 = lv_obj_create(list_container);
        lv_obj_set_name(circuit_3, "circuit_3");
        lv_obj_set_x(circuit_3, 0);
        lv_obj_set_y(circuit_3, 108);
        lv_obj_set_width(circuit_3, 220);
        lv_obj_set_height(circuit_3, 50);
        lv_obj_set_flag(circuit_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(circuit_3, &style_card, 0);
        lv_obj_add_style(circuit_3, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_label_8 = lv_label_create(circuit_3);
        lv_obj_set_x(lv_label_8, 6);
        lv_obj_set_y(lv_label_8, 2);
        lv_label_set_text(lv_label_8, "厨房");
        lv_obj_add_style(lv_label_8, &style_text_normal, 0);

        lv_obj_t * label_power_3 = lv_label_create(circuit_3);
        lv_obj_set_name(label_power_3, "label_power_3");
        lv_obj_set_x(label_power_3, 140);
        lv_obj_set_y(label_power_3, 2);
        lv_label_set_text(label_power_3, "2.30KW");
        lv_obj_add_style(label_power_3, &style_text_value, 0);

        lv_obj_t * lv_label_9 = lv_label_create(circuit_3);
        lv_obj_set_x(lv_label_9, 6);
        lv_obj_set_y(lv_label_9, 22);
        lv_label_set_text(lv_label_9, "今日用电");
        lv_obj_add_style(lv_label_9, &style_text_muted, 0);

        lv_obj_t * label_energy_3 = lv_label_create(circuit_3);
        lv_obj_set_name(label_energy_3, "label_energy_3");
        lv_obj_set_x(label_energy_3, 68);
        lv_obj_set_y(label_energy_3, 22);
        lv_label_set_text(label_energy_3, "5.6KWh");
        lv_obj_add_style(label_energy_3, &style_text_muted, 0);

        lv_obj_t * lv_label_10 = lv_label_create(circuit_3);
        lv_obj_set_x(lv_label_10, 140);
        lv_obj_set_y(lv_label_10, 22);
        lv_label_set_text(lv_label_10, "峰值");
        lv_obj_add_style(lv_label_10, &style_text_muted, 0);

        lv_obj_t * label_peak_3 = lv_label_create(circuit_3);
        lv_obj_set_name(label_peak_3, "label_peak_3");
        lv_obj_set_x(label_peak_3, 178);
        lv_obj_set_y(label_peak_3, 22);
        lv_label_set_text(label_peak_3, "2.8KW");
        lv_obj_add_style(label_peak_3, &style_text_muted, 0);

        lv_obj_t * lv_label_11 = lv_label_create(circuit_3);
        lv_obj_set_x(lv_label_11, 6);
        lv_obj_set_y(lv_label_11, 38);
        lv_label_set_text(lv_label_11, "断路器");
        lv_obj_add_style(lv_label_11, &style_text_muted, 0);

        lv_obj_t * label_status_3 = lv_label_create(circuit_3);
        lv_obj_set_name(label_status_3, "label_status_3");
        lv_obj_set_x(label_status_3, 66);
        lv_obj_set_y(label_status_3, 38);
        lv_label_set_text(label_status_3, "● 闭合");
        lv_obj_add_style(label_status_3, &style_text_ok, 0);

        lv_obj_t * circuit_4 = lv_obj_create(list_container);
        lv_obj_set_name(circuit_4, "circuit_4");
        lv_obj_set_x(circuit_4, 0);
        lv_obj_set_y(circuit_4, 162);
        lv_obj_set_width(circuit_4, 220);
        lv_obj_set_height(circuit_4, 50);
        lv_obj_set_flag(circuit_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(circuit_4, &style_card, 0);
        lv_obj_add_style(circuit_4, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_label_12 = lv_label_create(circuit_4);
        lv_obj_set_x(lv_label_12, 6);
        lv_obj_set_y(lv_label_12, 2);
        lv_label_set_text(lv_label_12, "空调");
        lv_obj_add_style(lv_label_12, &style_text_normal, 0);

        lv_obj_t * label_power_4 = lv_label_create(circuit_4);
        lv_obj_set_name(label_power_4, "label_power_4");
        lv_obj_set_x(label_power_4, 140);
        lv_obj_set_y(label_power_4, 2);
        lv_label_set_text(label_power_4, "1.75KW");
        lv_obj_add_style(label_power_4, &style_text_value, 0);

        lv_obj_t * lv_label_13 = lv_label_create(circuit_4);
        lv_obj_set_x(lv_label_13, 6);
        lv_obj_set_y(lv_label_13, 22);
        lv_label_set_text(lv_label_13, "今日用电");
        lv_obj_add_style(lv_label_13, &style_text_muted, 0);

        lv_obj_t * label_energy_4 = lv_label_create(circuit_4);
        lv_obj_set_name(label_energy_4, "label_energy_4");
        lv_obj_set_x(label_energy_4, 68);
        lv_obj_set_y(label_energy_4, 22);
        lv_label_set_text(label_energy_4, "4.2KWh");
        lv_obj_add_style(label_energy_4, &style_text_muted, 0);

        lv_obj_t * lv_label_14 = lv_label_create(circuit_4);
        lv_obj_set_x(lv_label_14, 140);
        lv_obj_set_y(lv_label_14, 22);
        lv_label_set_text(lv_label_14, "峰值");
        lv_obj_add_style(lv_label_14, &style_text_muted, 0);

        lv_obj_t * label_peak_4 = lv_label_create(circuit_4);
        lv_obj_set_name(label_peak_4, "label_peak_4");
        lv_obj_set_x(label_peak_4, 178);
        lv_obj_set_y(label_peak_4, 22);
        lv_label_set_text(label_peak_4, "2.0KW");
        lv_obj_add_style(label_peak_4, &style_text_muted, 0);

        lv_obj_t * lv_label_15 = lv_label_create(circuit_4);
        lv_obj_set_x(lv_label_15, 6);
        lv_obj_set_y(lv_label_15, 38);
        lv_label_set_text(lv_label_15, "断路器");
        lv_obj_add_style(lv_label_15, &style_text_muted, 0);

        lv_obj_t * label_status_4 = lv_label_create(circuit_4);
        lv_obj_set_name(label_status_4, "label_status_4");
        lv_obj_set_x(label_status_4, 66);
        lv_obj_set_y(label_status_4, 38);
        lv_label_set_text(label_status_4, "● 闭合");
        lv_obj_add_style(label_status_4, &style_text_ok, 0);

        lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "5/8");
        lv_obj_set_name(bottom_bar, "bottom_bar");
        lv_obj_set_x(bottom_bar, 0);
        lv_obj_set_y(bottom_bar, 218);
        lv_obj_set_style_opa(bottom_bar, 0, 0);
        lv_obj_set_style_translate_y(bottom_bar, 20, 0);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_CIRCUITS_TIMELINE_CNT);
        at_array[SCREEN_CIRCUITS_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOAD_START, screen_circuits_get_timeline(lv_obj_0, SCREEN_CIRCUITS_TIMELINE_SCREEN_OPEN), 0, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_circuits_get_timeline(lv_obj_t * obj, screen_circuits_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_CIRCUITS_TIMELINE_CNT) {
        LV_LOG_WARN("screen_circuits has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_screen_open_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "top_bar"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "top_bar"));
    lv_anim_set_values(&a, -20, 0);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "alarm_bar"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 60, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "alarm_bar"));
    lv_anim_set_values(&a, -10, 0);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 60, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "list_container"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 250);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 120, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "list_container"));
    lv_anim_set_values(&a, -35, 0);
    lv_anim_set_duration(&a, 250);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 120, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "bottom_bar"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 380, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "bottom_bar"));
    lv_anim_set_values(&a, 20, 0);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 380, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _SCREEN_CIRCUITS_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

