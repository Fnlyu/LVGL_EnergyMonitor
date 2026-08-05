/**
 * @file screen_alarms_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_alarms_gen.h"
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

lv_obj_t * screen_alarms_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card;
    static lv_style_t style_card_focused;
    static lv_style_t style_text_normal;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_value;
    static lv_style_t style_status_critical;
    static lv_style_t style_status_warning;
    static lv_style_t style_status_ok;
    static lv_style_t style_tag_overvoltage;
    static lv_style_t style_tag_undervoltage;
    static lv_style_t style_tag_overcurrent;
    static lv_style_t style_tag_short;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen_bg);
        lv_style_init(&style_card);
        lv_style_init(&style_card_focused);
        lv_style_init(&style_text_normal);
        lv_style_init(&style_text_muted);
        lv_style_init(&style_text_value);
        lv_style_init(&style_status_critical);
        lv_style_init(&style_status_warning);
        lv_style_init(&style_status_ok);
        lv_style_init(&style_tag_overvoltage);
        lv_style_init(&style_tag_undervoltage);
        lv_style_init(&style_tag_overcurrent);
        lv_style_init(&style_tag_short);

        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x05070a));
        lv_style_set_bg_color(&style_card, lv_color_hex(0x101821));
        lv_style_set_border_color(&style_card, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_card, 1);
        lv_style_set_radius(&style_card, 6);
        lv_style_set_pad_all(&style_card, 0);
        lv_style_set_border_width(&style_card_focused, 2);
        lv_style_set_border_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_border_opa(&style_card_focused, 255);
        lv_style_set_shadow_width(&style_card_focused, 6);
        lv_style_set_shadow_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_shadow_opa(&style_card_focused, 80);
        lv_style_set_radius(&style_card_focused, 10);
        lv_style_set_text_color(&style_text_normal, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_text_normal, font_cn_12);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x8fa3bf));
        lv_style_set_text_font(&style_text_muted, font_cn_12);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x4dd4ff));
        lv_style_set_text_font(&style_text_value, font_cn_12);
        lv_style_set_text_color(&style_status_critical, lv_color_hex(0xff4757));
        lv_style_set_text_font(&style_status_critical, font_cn_12);
        lv_style_set_text_color(&style_status_warning, lv_color_hex(0xffd166));
        lv_style_set_text_font(&style_status_warning, font_cn_12);
        lv_style_set_text_color(&style_status_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_status_ok, font_cn_12);
        lv_style_set_bg_color(&style_tag_overvoltage, lv_color_hex(0xff4757));
        lv_style_set_radius(&style_tag_overvoltage, 3);
        lv_style_set_pad_all(&style_tag_overvoltage, 2);
        lv_style_set_bg_color(&style_tag_undervoltage, lv_color_hex(0xffa502));
        lv_style_set_radius(&style_tag_undervoltage, 3);
        lv_style_set_pad_all(&style_tag_undervoltage, 2);
        lv_style_set_bg_color(&style_tag_overcurrent, lv_color_hex(0xff6348));
        lv_style_set_radius(&style_tag_overcurrent, 3);
        lv_style_set_pad_all(&style_tag_overcurrent, 2);
        lv_style_set_bg_color(&style_tag_short, lv_color_hex(0xee5a24));
        lv_style_set_radius(&style_tag_short, 3);
        lv_style_set_pad_all(&style_tag_short, 2);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_alarms_#");

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "告警日志", "12:30", "WiFi", "●");
        lv_obj_set_name(top_bar, "top_bar");
        lv_obj_set_x(top_bar, 0);
        lv_obj_set_y(top_bar, 0);
        lv_obj_set_style_opa(top_bar, 0, 0);
        lv_obj_set_style_translate_y(top_bar, -20, 0);

        lv_obj_t * list_container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(list_container, "list_container");
        lv_obj_set_x(list_container, 10);
        lv_obj_set_y(list_container, 38);
        lv_obj_set_width(list_container, 220);
        lv_obj_set_height(list_container, 172);
        lv_obj_set_flag(list_container, LV_OBJ_FLAG_SCROLLABLE, true);
        lv_obj_set_style_opa(list_container, 0, 0);
        lv_obj_set_style_translate_x(list_container, -35, 0);
        lv_obj_set_style_bg_opa(list_container, 0, 0);
        lv_obj_set_style_border_width(list_container, 0, 0);
        lv_obj_set_style_pad_all(list_container, 0, 0);
        lv_obj_set_style_pad_row(list_container, 3, 0);
        lv_obj_t * alarm_1 = lv_obj_create(list_container);
        lv_obj_set_name(alarm_1, "alarm_1");
        lv_obj_set_x(alarm_1, 0);
        lv_obj_set_y(alarm_1, 0);
        lv_obj_set_width(alarm_1, 220);
        lv_obj_set_height(alarm_1, 40);
        lv_obj_set_flag(alarm_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(alarm_1, &style_card, 0);
        lv_obj_add_style(alarm_1, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_obj_1 = lv_obj_create(alarm_1);
        lv_obj_set_x(lv_obj_1, 0);
        lv_obj_set_y(lv_obj_1, 0);
        lv_obj_set_width(lv_obj_1, 4);
        lv_obj_set_height(lv_obj_1, 40);
        lv_obj_set_style_bg_color(lv_obj_1, lv_color_hex(0xff4757), 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_style_radius(lv_obj_1, 0, 0);

        lv_obj_t * lv_label_0 = lv_label_create(alarm_1);
        lv_obj_set_x(lv_label_0, 8);
        lv_obj_set_y(lv_label_0, 1);
        lv_label_set_text(lv_label_0, "过压");
        lv_obj_add_style(lv_label_0, &style_text_normal, 0);

        lv_obj_t * lv_label_1 = lv_label_create(alarm_1);
        lv_obj_set_x(lv_label_1, 140);
        lv_obj_set_y(lv_label_1, 1);
        lv_label_set_text(lv_label_1, "14:32:05");
        lv_obj_add_style(lv_label_1, &style_text_muted, 0);

        lv_obj_t * lv_label_2 = lv_label_create(alarm_1);
        lv_obj_set_x(lv_label_2, 8);
        lv_obj_set_y(lv_label_2, 18);
        lv_label_set_text(lv_label_2, "持续 3min 12s");
        lv_obj_add_style(lv_label_2, &style_text_normal, 0);

        lv_obj_t * lv_label_3 = lv_label_create(alarm_1);
        lv_obj_set_x(lv_label_3, 140);
        lv_obj_set_y(lv_label_3, 18);
        lv_label_set_text(lv_label_3, "● 未恢复");
        lv_obj_add_style(lv_label_3, &style_status_critical, 0);

        lv_obj_t * alarm_2 = lv_obj_create(list_container);
        lv_obj_set_name(alarm_2, "alarm_2");
        lv_obj_set_x(alarm_2, 0);
        lv_obj_set_y(alarm_2, 43);
        lv_obj_set_width(alarm_2, 220);
        lv_obj_set_height(alarm_2, 40);
        lv_obj_set_flag(alarm_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(alarm_2, &style_card, 0);
        lv_obj_add_style(alarm_2, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_obj_2 = lv_obj_create(alarm_2);
        lv_obj_set_x(lv_obj_2, 0);
        lv_obj_set_y(lv_obj_2, 0);
        lv_obj_set_width(lv_obj_2, 4);
        lv_obj_set_height(lv_obj_2, 40);
        lv_obj_set_style_bg_color(lv_obj_2, lv_color_hex(0xffd166), 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_style_radius(lv_obj_2, 0, 0);

        lv_obj_t * lv_label_4 = lv_label_create(alarm_2);
        lv_obj_set_x(lv_label_4, 8);
        lv_obj_set_y(lv_label_4, 1);
        lv_label_set_text(lv_label_4, "欠压");
        lv_obj_add_style(lv_label_4, &style_text_normal, 0);

        lv_obj_t * lv_label_5 = lv_label_create(alarm_2);
        lv_obj_set_x(lv_label_5, 140);
        lv_obj_set_y(lv_label_5, 1);
        lv_label_set_text(lv_label_5, "12:18:22");
        lv_obj_add_style(lv_label_5, &style_text_muted, 0);

        lv_obj_t * lv_label_6 = lv_label_create(alarm_2);
        lv_obj_set_x(lv_label_6, 8);
        lv_obj_set_y(lv_label_6, 18);
        lv_label_set_text(lv_label_6, "持续 0min 45s");
        lv_obj_add_style(lv_label_6, &style_text_normal, 0);

        lv_obj_t * lv_label_7 = lv_label_create(alarm_2);
        lv_obj_set_x(lv_label_7, 140);
        lv_obj_set_y(lv_label_7, 18);
        lv_label_set_text(lv_label_7, "● 已恢复");
        lv_obj_add_style(lv_label_7, &style_status_ok, 0);

        lv_obj_t * alarm_3 = lv_obj_create(list_container);
        lv_obj_set_name(alarm_3, "alarm_3");
        lv_obj_set_x(alarm_3, 0);
        lv_obj_set_y(alarm_3, 86);
        lv_obj_set_width(alarm_3, 220);
        lv_obj_set_height(alarm_3, 40);
        lv_obj_set_flag(alarm_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(alarm_3, &style_card, 0);
        lv_obj_add_style(alarm_3, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_obj_3 = lv_obj_create(alarm_3);
        lv_obj_set_x(lv_obj_3, 0);
        lv_obj_set_y(lv_obj_3, 0);
        lv_obj_set_width(lv_obj_3, 4);
        lv_obj_set_height(lv_obj_3, 40);
        lv_obj_set_style_bg_color(lv_obj_3, lv_color_hex(0xff6348), 0);
        lv_obj_set_style_border_width(lv_obj_3, 0, 0);
        lv_obj_set_style_radius(lv_obj_3, 0, 0);

        lv_obj_t * lv_label_8 = lv_label_create(alarm_3);
        lv_obj_set_x(lv_label_8, 8);
        lv_obj_set_y(lv_label_8, 1);
        lv_label_set_text(lv_label_8, "过流");
        lv_obj_add_style(lv_label_8, &style_text_normal, 0);

        lv_obj_t * lv_label_9 = lv_label_create(alarm_3);
        lv_obj_set_x(lv_label_9, 140);
        lv_obj_set_y(lv_label_9, 1);
        lv_label_set_text(lv_label_9, "11:02:10");
        lv_obj_add_style(lv_label_9, &style_text_muted, 0);

        lv_obj_t * lv_label_10 = lv_label_create(alarm_3);
        lv_obj_set_x(lv_label_10, 8);
        lv_obj_set_y(lv_label_10, 18);
        lv_label_set_text(lv_label_10, "持续 5min 0s");
        lv_obj_add_style(lv_label_10, &style_text_normal, 0);

        lv_obj_t * lv_label_11 = lv_label_create(alarm_3);
        lv_obj_set_x(lv_label_11, 140);
        lv_obj_set_y(lv_label_11, 18);
        lv_label_set_text(lv_label_11, "● 已恢复");
        lv_obj_add_style(lv_label_11, &style_status_ok, 0);

        lv_obj_t * alarm_4 = lv_obj_create(list_container);
        lv_obj_set_name(alarm_4, "alarm_4");
        lv_obj_set_x(alarm_4, 0);
        lv_obj_set_y(alarm_4, 129);
        lv_obj_set_width(alarm_4, 220);
        lv_obj_set_height(alarm_4, 40);
        lv_obj_set_flag(alarm_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(alarm_4, &style_card, 0);
        lv_obj_add_style(alarm_4, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_obj_4 = lv_obj_create(alarm_4);
        lv_obj_set_x(lv_obj_4, 0);
        lv_obj_set_y(lv_obj_4, 0);
        lv_obj_set_width(lv_obj_4, 4);
        lv_obj_set_height(lv_obj_4, 40);
        lv_obj_set_style_bg_color(lv_obj_4, lv_color_hex(0xee5a24), 0);
        lv_obj_set_style_border_width(lv_obj_4, 0, 0);
        lv_obj_set_style_radius(lv_obj_4, 0, 0);

        lv_obj_t * lv_label_12 = lv_label_create(alarm_4);
        lv_obj_set_x(lv_label_12, 8);
        lv_obj_set_y(lv_label_12, 1);
        lv_label_set_text(lv_label_12, "短路");
        lv_obj_add_style(lv_label_12, &style_text_normal, 0);

        lv_obj_t * lv_label_13 = lv_label_create(alarm_4);
        lv_obj_set_x(lv_label_13, 140);
        lv_obj_set_y(lv_label_13, 1);
        lv_label_set_text(lv_label_13, "09:45:03");
        lv_obj_add_style(lv_label_13, &style_text_muted, 0);

        lv_obj_t * lv_label_14 = lv_label_create(alarm_4);
        lv_obj_set_x(lv_label_14, 8);
        lv_obj_set_y(lv_label_14, 18);
        lv_label_set_text(lv_label_14, "持续 0min 12s");
        lv_obj_add_style(lv_label_14, &style_text_normal, 0);

        lv_obj_t * lv_label_15 = lv_label_create(alarm_4);
        lv_obj_set_x(lv_label_15, 140);
        lv_obj_set_y(lv_label_15, 18);
        lv_label_set_text(lv_label_15, "● 已恢复");
        lv_obj_add_style(lv_label_15, &style_status_ok, 0);

        lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "7/8");
        lv_obj_set_name(bottom_bar, "bottom_bar");
        lv_obj_set_x(bottom_bar, 0);
        lv_obj_set_y(bottom_bar, 218);
        lv_obj_set_style_opa(bottom_bar, 0, 0);
        lv_obj_set_style_translate_y(bottom_bar, 20, 0);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_ALARMS_TIMELINE_CNT);
        at_array[SCREEN_ALARMS_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOAD_START, screen_alarms_get_timeline(lv_obj_0, SCREEN_ALARMS_TIMELINE_SCREEN_OPEN), 0, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_alarms_get_timeline(lv_obj_t * obj, screen_alarms_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_ALARMS_TIMELINE_CNT) {
        LV_LOG_WARN("screen_alarms has no timeline with %d ID", timeline_id);
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
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "list_container"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "list_container"));
    lv_anim_set_values(&a, -35, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

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
    for(i = 0; i < _SCREEN_ALARMS_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

