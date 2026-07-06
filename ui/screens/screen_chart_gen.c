/**
 * @file screen_chart_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_chart_gen.h"
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

lv_obj_t * screen_chart_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card;
    static lv_style_t style_card_main;
    static lv_style_t style_card_focused;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_title;
    static lv_style_t style_text_value;
    static lv_style_t style_chart_main;
    static lv_style_t style_chart_items;
    static lv_style_t style_chart_indicator_hidden;
    static lv_style_t style_curve_dot;
    static lv_style_t style_peak_dot;
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
        lv_style_set_pad_all(&style_card, 0);

        lv_style_init(&style_card_main);
        lv_style_set_bg_color(&style_card_main, lv_color_hex(0x0b1118));
        lv_style_set_border_color(&style_card_main, lv_color_hex(0x172331));
        lv_style_set_border_width(&style_card_main, 1);
        lv_style_set_radius(&style_card_main, 10);
        lv_style_set_pad_all(&style_card_main, 0);

        lv_style_init(&style_card_focused);
        lv_style_set_border_width(&style_card_focused, 2);
        lv_style_set_border_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_border_opa(&style_card_focused, 255);
        lv_style_set_shadow_width(&style_card_focused, 8);
        lv_style_set_shadow_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_shadow_opa(&style_card_focused, 90);
        lv_style_set_radius(&style_card_focused, 14);

        lv_style_init(&style_text_muted);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_muted, font_cn_12);

        lv_style_init(&style_text_title);
        lv_style_set_text_color(&style_text_title, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_title, font_cn_18);

        lv_style_init(&style_text_value);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x20e6d2));
        lv_style_set_text_font(&style_text_value, font_cn_18);

        lv_style_init(&style_chart_main);
        lv_style_set_bg_opa(&style_chart_main, 0);
        lv_style_set_border_width(&style_chart_main, 0);
        lv_style_set_radius(&style_chart_main, 0);
        lv_style_set_pad_all(&style_chart_main, 0);
        lv_style_set_line_color(&style_chart_main, lv_color_hex(0x1a2632));
        lv_style_set_line_width(&style_chart_main, 1);
        lv_style_set_line_opa(&style_chart_main, 255);

        lv_style_init(&style_chart_items);
        lv_style_set_line_color(&style_chart_items, lv_color_hex(0x20e6d2));
        lv_style_set_line_width(&style_chart_items, 2);
        lv_style_set_line_opa(&style_chart_items, 255);

        lv_style_init(&style_chart_indicator_hidden);
        lv_style_set_width(&style_chart_indicator_hidden, 0);
        lv_style_set_height(&style_chart_indicator_hidden, 0);
        lv_style_set_bg_opa(&style_chart_indicator_hidden, 0);
        lv_style_set_border_width(&style_chart_indicator_hidden, 0);

        lv_style_init(&style_curve_dot);
        lv_style_set_bg_color(&style_curve_dot, lv_color_hex(0x20e6d2));
        lv_style_set_bg_opa(&style_curve_dot, 255);
        lv_style_set_border_width(&style_curve_dot, 0);
        lv_style_set_radius(&style_curve_dot, 3);
        lv_style_set_pad_all(&style_curve_dot, 0);

        lv_style_init(&style_peak_dot);
        lv_style_set_bg_color(&style_peak_dot, lv_color_hex(0xffb020));
        lv_style_set_bg_opa(&style_peak_dot, 255);
        lv_style_set_border_width(&style_peak_dot, 0);
        lv_style_set_radius(&style_peak_dot, 4);
        lv_style_set_pad_all(&style_peak_dot, 0);

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
    lv_obj_set_name_static(lv_obj_0, "screen_chart_#");

    lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
    lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "功率曲线", "12:30", "WiFi", "●");
    lv_obj_set_name(top_bar, "top_bar");
    lv_obj_set_x(top_bar, 0);
    lv_obj_set_y(top_bar, 0);
    lv_obj_set_style_opa(top_bar, 0, 0);
    lv_obj_set_style_translate_y(top_bar, -20, 0);
    
    lv_obj_t * chart_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(chart_card, "chart_card");
    lv_obj_set_x(chart_card, 10);
    lv_obj_set_y(chart_card, 36);
    lv_obj_set_width(chart_card, 220);
    lv_obj_set_height(chart_card, 128);
    lv_obj_set_flag(chart_card, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_opa(chart_card, 0, 0);
    lv_obj_set_style_translate_x(chart_card, -40, 0);
    lv_obj_add_style(chart_card, &style_card_main, 0);
    lv_obj_add_style(chart_card, &style_card_focused, LV_STATE_FOCUSED);
    lv_obj_t * lv_label_0 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_0, 8);
    lv_obj_set_y(lv_label_0, 3);
    lv_label_set_text(lv_label_0, "今日功率曲线");
    lv_obj_add_style(lv_label_0, &style_text_title, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_1, 166);
    lv_obj_set_y(lv_label_1, 8);
    lv_label_set_text(lv_label_1, "24h / KW");
    lv_obj_add_style(lv_label_1, &style_text_muted, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_2, 0);
    lv_obj_set_y(lv_label_2, 29);
    lv_label_set_text(lv_label_2, "8KW");
    lv_obj_add_style(lv_label_2, &style_text_muted, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_3, 0);
    lv_obj_set_y(lv_label_3, 67);
    lv_label_set_text(lv_label_3, "4KW");
    lv_obj_add_style(lv_label_3, &style_text_muted, 0);
    
    lv_obj_t * lv_label_4 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_4, 0);
    lv_obj_set_y(lv_label_4, 101);
    lv_label_set_text(lv_label_4, "0KW");
    lv_obj_add_style(lv_label_4, &style_text_muted, 0);
    
    lv_obj_t * chart_power = lv_chart_create(chart_card);
    lv_obj_set_name(chart_power, "chart_power");
    lv_obj_set_x(chart_power, 34);
    lv_obj_set_y(chart_power, 31);
    lv_obj_set_width(chart_power, 174);
    lv_obj_set_height(chart_power, 76);
    lv_chart_set_type(chart_power, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(chart_power, 25);
    lv_chart_set_update_mode(chart_power, LV_CHART_UPDATE_MODE_SHIFT);
    lv_chart_set_hor_div_line_count(chart_power, 3);
    lv_chart_set_ver_div_line_count(chart_power, 4);
    lv_obj_set_flag(chart_power, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(chart_power, &style_chart_main, LV_PART_MAIN);
    lv_obj_add_style(chart_power, &style_chart_items, LV_PART_ITEMS);
    lv_obj_add_style(chart_power, &style_chart_indicator_hidden, LV_PART_INDICATOR);
    lv_chart_set_axis_min_value(chart_power, LV_CHART_AXIS_PRIMARY_Y, 0);
    lv_chart_set_axis_max_value(chart_power, LV_CHART_AXIS_PRIMARY_Y, 800);
    lv_chart_series_t * lv_chart_series_0 = lv_chart_add_series(chart_power, lv_color_hex(0x20e6d2), LV_CHART_AXIS_PRIMARY_Y);
    static const int32_t chart_power_values_0[] = {100, 100, 100, 260, 260, 260, 220, 220, 220, 580, 580, 580, 710, 710, 500, 500, 500, 500, 780, 780, 780, 780, 672, 672, 672};
    lv_chart_set_series_values(chart_power, lv_chart_series_0, chart_power_values_0, 25);
    
    lv_obj_t * lv_label_5 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_5, 34);
    lv_obj_set_y(lv_label_5, 110);
    lv_label_set_text(lv_label_5, "00");
    lv_obj_add_style(lv_label_5, &style_text_muted, 0);
    
    lv_obj_t * lv_label_6 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_6, 94);
    lv_obj_set_y(lv_label_6, 110);
    lv_label_set_text(lv_label_6, "08");
    lv_obj_add_style(lv_label_6, &style_text_muted, 0);
    
    lv_obj_t * lv_label_7 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_7, 155);
    lv_obj_set_y(lv_label_7, 110);
    lv_label_set_text(lv_label_7, "16");
    lv_obj_add_style(lv_label_7, &style_text_muted, 0);
    
    lv_obj_t * lv_label_8 = lv_label_create(chart_card);
    lv_obj_set_x(lv_label_8, 194);
    lv_obj_set_y(lv_label_8, 110);
    lv_label_set_text(lv_label_8, "24");
    lv_obj_add_style(lv_label_8, &style_text_muted, 0);
    
    lv_obj_t * now_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(now_card, "now_card");
    lv_obj_set_x(now_card, 8);
    lv_obj_set_y(now_card, 171);
    lv_obj_set_width(now_card, 72);
    lv_obj_set_height(now_card, 40);
    lv_obj_set_flag(now_card, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_opa(now_card, 0, 0);
    lv_obj_set_style_translate_y(now_card, 24, 0);
    lv_obj_add_style(now_card, &style_card, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(now_card);
    lv_obj_set_x(lv_obj_1, 0);
    lv_obj_set_y(lv_obj_1, 7);
    lv_obj_set_width(lv_obj_1, 3);
    lv_obj_set_height(lv_obj_1, 26);
    lv_obj_add_style(lv_obj_1, &style_accent_cyan, 0);
    
    lv_obj_t * lv_label_9 = lv_label_create(now_card);
    lv_obj_set_x(lv_label_9, 8);
    lv_obj_set_y(lv_label_9, 3);
    lv_label_set_text(lv_label_9, "当前");
    lv_obj_add_style(lv_label_9, &style_text_muted, 0);
    
    lv_obj_t * label_power_now = lv_label_create(now_card);
    lv_obj_set_name(label_power_now, "label_power_now");
    lv_obj_set_x(label_power_now, 8);
    lv_obj_set_y(label_power_now, 20);
    lv_label_set_text(label_power_now, "6.72KW");
    lv_obj_add_style(label_power_now, &style_text_value, 0);
    
    lv_obj_t * peak_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(peak_card, "peak_card");
    lv_obj_set_x(peak_card, 84);
    lv_obj_set_y(peak_card, 171);
    lv_obj_set_width(peak_card, 72);
    lv_obj_set_height(peak_card, 40);
    lv_obj_set_flag(peak_card, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_opa(peak_card, 0, 0);
    lv_obj_set_style_translate_y(peak_card, 24, 0);
    lv_obj_add_style(peak_card, &style_card, 0);
    lv_obj_t * lv_obj_2 = lv_obj_create(peak_card);
    lv_obj_set_x(lv_obj_2, 0);
    lv_obj_set_y(lv_obj_2, 7);
    lv_obj_set_width(lv_obj_2, 3);
    lv_obj_set_height(lv_obj_2, 26);
    lv_obj_add_style(lv_obj_2, &style_accent_yellow, 0);
    
    lv_obj_t * lv_label_10 = lv_label_create(peak_card);
    lv_obj_set_x(lv_label_10, 8);
    lv_obj_set_y(lv_label_10, 3);
    lv_label_set_text(lv_label_10, "峰值");
    lv_obj_add_style(lv_label_10, &style_text_muted, 0);
    
    lv_obj_t * label_power_peak = lv_label_create(peak_card);
    lv_obj_set_name(label_power_peak, "label_power_peak");
    lv_obj_set_x(label_power_peak, 8);
    lv_obj_set_y(label_power_peak, 20);
    lv_label_set_text(label_power_peak, "7.80KW");
    lv_obj_add_style(label_power_peak, &style_text_value, 0);
    
    lv_obj_t * avg_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(avg_card, "avg_card");
    lv_obj_set_x(avg_card, 160);
    lv_obj_set_y(avg_card, 171);
    lv_obj_set_width(avg_card, 72);
    lv_obj_set_height(avg_card, 40);
    lv_obj_set_flag(avg_card, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_opa(avg_card, 0, 0);
    lv_obj_set_style_translate_y(avg_card, 24, 0);
    lv_obj_add_style(avg_card, &style_card, 0);
    lv_obj_t * lv_obj_3 = lv_obj_create(avg_card);
    lv_obj_set_x(lv_obj_3, 0);
    lv_obj_set_y(lv_obj_3, 7);
    lv_obj_set_width(lv_obj_3, 3);
    lv_obj_set_height(lv_obj_3, 26);
    lv_obj_add_style(lv_obj_3, &style_accent_green, 0);
    
    lv_obj_t * lv_label_11 = lv_label_create(avg_card);
    lv_obj_set_x(lv_label_11, 8);
    lv_obj_set_y(lv_label_11, 3);
    lv_label_set_text(lv_label_11, "平均");
    lv_obj_add_style(lv_label_11, &style_text_muted, 0);
    
    lv_obj_t * label_power_avg = lv_label_create(avg_card);
    lv_obj_set_name(label_power_avg, "label_power_avg");
    lv_obj_set_x(label_power_avg, 8);
    lv_obj_set_y(label_power_avg, 20);
    lv_label_set_text(label_power_avg, "4.92KW");
    lv_obj_add_style(label_power_avg, &style_text_value, 0);
    
    lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "2/8");
    lv_obj_set_name(bottom_bar, "bottom_bar");
    lv_obj_set_x(bottom_bar, 0);
    lv_obj_set_y(bottom_bar, 216);
    lv_obj_set_style_opa(bottom_bar, 0, 0);
    lv_obj_set_style_translate_y(bottom_bar, 20, 0);
    
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_CHART_TIMELINE_CNT);
    at_array[SCREEN_CHART_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOAD_START, screen_chart_get_timeline(lv_obj_0, SCREEN_CHART_TIMELINE_SCREEN_OPEN), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * screen_chart_get_timeline(lv_obj_t * obj, screen_chart_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_CHART_TIMELINE_CNT) {
        LV_LOG_WARN("screen_chart has no timeline with %d ID", timeline_id);
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
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "chart_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "chart_card"));
    lv_anim_set_values(&a, -40, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "now_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 180, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "now_card"));
    lv_anim_set_values(&a, 24, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 180, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "peak_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 240, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "peak_card"));
    lv_anim_set_values(&a, 24, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 240, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "avg_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 300, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "avg_card"));
    lv_anim_set_values(&a, 24, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 300, &a);

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
    lv_anim_timeline_add(at, 380, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _SCREEN_CHART_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

