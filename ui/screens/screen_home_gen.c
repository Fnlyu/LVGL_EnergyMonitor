/**
 * @file screen_home_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_home_gen.h"
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

lv_obj_t * screen_home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card;
    static lv_style_t style_card_main;
    static lv_style_t style_text_normal;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_biaoti_da;
    static lv_style_t style_text_value_xiao;
    static lv_style_t style_text_value;
    static lv_style_t style_text_value_KW;
    static lv_style_t style_text_ok;
    static lv_style_t style_text_warn;
    static lv_style_t style_accent_cyan;
    static lv_style_t style_accent_green;
    static lv_style_t style_accent_yellow;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_screen_bg);
        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x05070a));

        lv_style_init(&style_card);
        lv_style_set_bg_color(&style_card, lv_color_hex(0x101821));
        lv_style_set_border_color(&style_card, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_card, 1);
        lv_style_set_radius(&style_card, 8);
        lv_style_set_pad_all(&style_card, 6);

        lv_style_init(&style_card_main);
        lv_style_set_bg_color(&style_card_main, lv_color_hex(0x0b1118));
        lv_style_set_border_color(&style_card_main, lv_color_hex(0x172331));
        lv_style_set_border_width(&style_card_main, 1);
        lv_style_set_radius(&style_card_main, 10);
        lv_style_set_pad_all(&style_card_main, 8);

        lv_style_init(&style_text_normal);
        lv_style_set_text_color(&style_text_normal, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_text_normal, font_cn_12);

        lv_style_init(&style_text_muted);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_muted, font_cn_16);

        lv_style_init(&style_text_biaoti_da);
        lv_style_set_text_color(&style_text_biaoti_da, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_biaoti_da, font_cn_18);

        lv_style_init(&style_text_value_xiao);
        lv_style_set_text_color(&style_text_value_xiao, lv_color_hex(0xe6eef5));
        lv_style_set_text_font(&style_text_value_xiao, font_cn_16);

        lv_style_init(&style_text_value);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x20e6d2));
        lv_style_set_text_font(&style_text_value, font_cn_34);

        lv_style_init(&style_text_value_KW);
        lv_style_set_text_color(&style_text_value_KW, lv_color_hex(0xe6eef5));
        lv_style_set_text_font(&style_text_value_KW, font_cn_34);

        lv_style_init(&style_text_ok);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_12);

        lv_style_init(&style_text_warn);
        lv_style_set_text_color(&style_text_warn, lv_color_hex(0xffd166));
        lv_style_set_text_font(&style_text_warn, font_cn_12);

        lv_style_init(&style_accent_cyan);
        lv_style_set_bg_color(&style_accent_cyan, lv_color_hex(0x20e6d2));
        lv_style_set_border_width(&style_accent_cyan, 0);
        lv_style_set_radius(&style_accent_cyan, 3);
        lv_style_set_pad_all(&style_accent_cyan, 0);

        lv_style_init(&style_accent_green);
        lv_style_set_bg_color(&style_accent_green, lv_color_hex(0x32f27a));
        lv_style_set_border_width(&style_accent_green, 0);
        lv_style_set_radius(&style_accent_green, 3);
        lv_style_set_pad_all(&style_accent_green, 0);

        lv_style_init(&style_accent_yellow);
        lv_style_set_bg_color(&style_accent_yellow, lv_color_hex(0xffb020));
        lv_style_set_border_width(&style_accent_yellow, 0);
        lv_style_set_radius(&style_accent_yellow, 3);
        lv_style_set_pad_all(&style_accent_yellow, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "screen_home_#");

    lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
    lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "家庭能量监测", "12:30", "WiFi", "●");
    lv_obj_set_name(top_bar, "top_bar");
    lv_obj_set_x(top_bar, 0);
    lv_obj_set_y(top_bar, 0);
    
    lv_obj_t * main_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(main_card, "main_card");
    lv_obj_set_x(main_card, 10);
    lv_obj_set_y(main_card, 38);
    lv_obj_set_width(main_card, 220);
    lv_obj_set_height(main_card, 92);
    lv_obj_add_style(main_card, &style_card_main, 0);
    lv_obj_t * lv_label_0 = lv_label_create(main_card);
    lv_obj_set_x(lv_label_0, 0);
    lv_obj_set_y(lv_label_0, 2);
    lv_obj_set_width(lv_label_0, 200);
    lv_label_set_text(lv_label_0, "当前总功率");
    lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_style(lv_label_0, &style_text_biaoti_da, 0);
    
    lv_obj_t * power_row = lv_obj_create(main_card);
    lv_obj_set_name(power_row, "power_row");
    lv_obj_set_x(power_row, 0);
    lv_obj_set_y(power_row, 30);
    lv_obj_set_width(power_row, 200);
    lv_obj_set_height(power_row, 40);
    lv_obj_set_flag(power_row, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(power_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(power_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(power_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_bg_opa(power_row, 0, 0);
    lv_obj_set_style_border_width(power_row, 0, 0);
    lv_obj_set_style_pad_all(power_row, 0, 0);
    lv_obj_set_style_pad_column(power_row, 0, 0);
    lv_obj_t * label_total_power = lv_label_create(power_row);
    lv_obj_set_name(label_total_power, "label_total_power");
    lv_label_set_text(label_total_power, "6722.33");
    lv_obj_add_style(label_total_power, &style_text_value, 0);
    
    lv_obj_t * label_total_power_unit = lv_label_create(power_row);
    lv_obj_set_name(label_total_power_unit, "label_total_power_unit");
    lv_label_set_text(label_total_power_unit, "KW");
    lv_obj_add_style(label_total_power_unit, &style_text_value_KW, 0);
    
    lv_obj_t * today_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(today_card, "today_card");
    lv_obj_set_x(today_card, 10);
    lv_obj_set_y(today_card, 140);
    lv_obj_set_width(today_card, 105);
    lv_obj_set_height(today_card, 70);
    lv_obj_set_flag(today_card, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(today_card, &style_card, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(today_card);
    lv_obj_set_x(lv_obj_1, 0);
    lv_obj_set_y(lv_obj_1, 0);
    lv_obj_set_width(lv_obj_1, 3);
    lv_obj_set_height(lv_obj_1, 52);
    lv_obj_add_style(lv_obj_1, &style_accent_yellow, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(today_card);
    lv_obj_set_x(lv_label_1, 10);
    lv_obj_set_y(lv_label_1, 0);
    lv_label_set_text(lv_label_1, "今日用电");
    lv_obj_add_style(lv_label_1, &style_text_muted, 0);
    
    lv_obj_t * power_row = lv_obj_create(today_card);
    lv_obj_set_name(power_row, "power_row");
    lv_obj_set_x(power_row, 10);
    lv_obj_set_y(power_row, 25);
    lv_obj_set_width(power_row, 100);
    lv_obj_set_height(power_row, 20);
    lv_obj_set_flag(power_row, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(power_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(power_row, LV_FLEX_ALIGN_START, 0);
    lv_obj_set_style_flex_cross_place(power_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_bg_opa(power_row, 0, 0);
    lv_obj_set_style_border_width(power_row, 0, 0);
    lv_obj_set_style_pad_all(power_row, 0, 0);
    lv_obj_set_style_pad_column(power_row, 0, 0);
    lv_obj_t * label_total_power = lv_label_create(power_row);
    lv_obj_set_name(label_total_power, "label_total_power");
    lv_label_set_text(label_total_power, "6722.33");
    lv_obj_add_style(label_total_power, &style_text_value_xiao, 0);
    
    lv_obj_t * label_total_power_unit = lv_label_create(power_row);
    lv_obj_set_name(label_total_power_unit, "label_total_power_unit");
    lv_label_set_text(label_total_power_unit, "KW");
    lv_obj_add_style(label_total_power_unit, &style_text_value_xiao, 0);
    
    lv_obj_t * month_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(month_card, "month_card");
    lv_obj_set_x(month_card, 125);
    lv_obj_set_y(month_card, 140);
    lv_obj_set_width(month_card, 105);
    lv_obj_set_height(month_card, 70);
    lv_obj_set_flag(month_card, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(month_card, &style_card, 0);
    lv_obj_t * lv_obj_2 = lv_obj_create(month_card);
    lv_obj_set_x(lv_obj_2, 0);
    lv_obj_set_y(lv_obj_2, 0);
    lv_obj_set_width(lv_obj_2, 3);
    lv_obj_set_height(lv_obj_2, 52);
    lv_obj_add_style(lv_obj_2, &style_accent_green, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(month_card);
    lv_obj_set_x(lv_label_2, 10);
    lv_obj_set_y(lv_label_2, 0);
    lv_label_set_text(lv_label_2, "本月用电");
    lv_obj_add_style(lv_label_2, &style_text_muted, 0);
    
    lv_obj_t * power_row = lv_obj_create(month_card);
    lv_obj_set_name(power_row, "power_row");
    lv_obj_set_x(power_row, 10);
    lv_obj_set_y(power_row, 25);
    lv_obj_set_width(power_row, 100);
    lv_obj_set_height(power_row, 20);
    lv_obj_set_flag(power_row, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(power_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(power_row, LV_FLEX_ALIGN_START, 0);
    lv_obj_set_style_flex_cross_place(power_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_bg_opa(power_row, 0, 0);
    lv_obj_set_style_border_width(power_row, 0, 0);
    lv_obj_set_style_pad_all(power_row, 0, 0);
    lv_obj_set_style_pad_column(power_row, 0, 0);
    lv_obj_t * label_total_power = lv_label_create(power_row);
    lv_obj_set_name(label_total_power, "label_total_power");
    lv_label_set_text(label_total_power, "6722.33");
    lv_obj_add_style(label_total_power, &style_text_value_xiao, 0);
    
    lv_obj_t * label_total_power_unit = lv_label_create(power_row);
    lv_obj_set_name(label_total_power_unit, "label_total_power_unit");
    lv_label_set_text(label_total_power_unit, "KW");
    lv_obj_add_style(label_total_power_unit, &style_text_value_xiao, 0);
    
    lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "1/8");
    lv_obj_set_name(bottom_bar, "bottom_bar");
    lv_obj_set_x(bottom_bar, 0);
    lv_obj_set_y(bottom_bar, 218);
    
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_HOME_TIMELINE_CNT);
    at_array[SCREEN_HOME_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, screen_home_get_timeline(lv_obj_0, SCREEN_HOME_TIMELINE_SCREEN_OPEN), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * screen_home_get_timeline(lv_obj_t * obj, screen_home_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_HOME_TIMELINE_CNT) {
        LV_LOG_WARN("screen_home has no timeline with %d ID", timeline_id);
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
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "main_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "main_card"));
    lv_anim_set_values(&a, -40, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "today_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 160, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "today_card"));
    lv_anim_set_values(&a, -35, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 160, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "month_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 220, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "month_card"));
    lv_anim_set_values(&a, 35, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 220, &a);

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
    for(i = 0; i < _SCREEN_HOME_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

