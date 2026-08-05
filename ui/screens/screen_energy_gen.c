/**
 * @file screen_energy_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_energy_gen.h"
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

lv_obj_t * screen_energy_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card;
    static lv_style_t style_card_focused;
    static lv_style_t style_text_title;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_value;
    static lv_style_t style_text_normal;
    static lv_style_t style_text_highlight;
    static lv_style_t style_text_ok;
    static lv_style_t style_progress_bg;
    static lv_style_t style_progress_peak;
    static lv_style_t style_progress_flat;
    static lv_style_t style_progress_valley;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen_bg);
        lv_style_init(&style_card);
        lv_style_init(&style_card_focused);
        lv_style_init(&style_text_title);
        lv_style_init(&style_text_muted);
        lv_style_init(&style_text_value);
        lv_style_init(&style_text_normal);
        lv_style_init(&style_text_highlight);
        lv_style_init(&style_text_ok);
        lv_style_init(&style_progress_bg);
        lv_style_init(&style_progress_peak);
        lv_style_init(&style_progress_flat);
        lv_style_init(&style_progress_valley);

        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x05070a));
        lv_style_set_bg_color(&style_card, lv_color_hex(0x101821));
        lv_style_set_border_color(&style_card, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_card, 1);
        lv_style_set_radius(&style_card, 8);
        lv_style_set_pad_all(&style_card, 6);
        lv_style_set_border_width(&style_card_focused, 2);
        lv_style_set_border_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_border_opa(&style_card_focused, 255);
        lv_style_set_shadow_width(&style_card_focused, 6);
        lv_style_set_shadow_color(&style_card_focused, lv_color_hex(0x35cfff));
        lv_style_set_shadow_opa(&style_card_focused, 80);
        lv_style_set_radius(&style_card_focused, 12);
        lv_style_set_text_color(&style_text_title, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_title, font_cn_14);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x8fa3bf));
        lv_style_set_text_font(&style_text_muted, font_cn_12);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x4dd4ff));
        lv_style_set_text_font(&style_text_value, font_cn_12);
        lv_style_set_text_color(&style_text_normal, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_text_normal, font_cn_12);
        lv_style_set_text_color(&style_text_highlight, lv_color_hex(0xffd166));
        lv_style_set_text_font(&style_text_highlight, font_cn_12);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_12);
        lv_style_set_bg_color(&style_progress_bg, lv_color_hex(0x1a2632));
        lv_style_set_radius(&style_progress_bg, 2);
        lv_style_set_bg_color(&style_progress_peak, lv_color_hex(0xff4757));
        lv_style_set_radius(&style_progress_peak, 2);
        lv_style_set_bg_color(&style_progress_flat, lv_color_hex(0xffd166));
        lv_style_set_radius(&style_progress_flat, 2);
        lv_style_set_bg_color(&style_progress_valley, lv_color_hex(0x61d394));
        lv_style_set_radius(&style_progress_valley, 2);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_energy_#");

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "能效分析", "12:30", "WiFi", "●");
        lv_obj_set_name(top_bar, "top_bar");
        lv_obj_set_x(top_bar, 0);
        lv_obj_set_y(top_bar, 0);
        lv_obj_set_style_opa(top_bar, 0, 0);
        lv_obj_set_style_translate_y(top_bar, -20, 0);

        lv_obj_t * scroll_container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(scroll_container, "scroll_container");
        lv_obj_set_x(scroll_container, 10);
        lv_obj_set_y(scroll_container, 38);
        lv_obj_set_width(scroll_container, 220);
        lv_obj_set_height(scroll_container, 172);
        lv_obj_set_flag(scroll_container, LV_OBJ_FLAG_SCROLLABLE, true);
        lv_obj_set_style_opa(scroll_container, 0, 0);
        lv_obj_set_style_translate_x(scroll_container, -35, 0);
        lv_obj_set_style_bg_opa(scroll_container, 0, 0);
        lv_obj_set_style_border_width(scroll_container, 0, 0);
        lv_obj_set_style_pad_all(scroll_container, 0, 0);
        lv_obj_set_style_pad_row(scroll_container, 6, 0);
        lv_obj_t * card_compare = lv_obj_create(scroll_container);
        lv_obj_set_name(card_compare, "card_compare");
        lv_obj_set_x(card_compare, 0);
        lv_obj_set_y(card_compare, 5);
        lv_obj_set_width(card_compare, 220);
        lv_obj_set_height(card_compare, 65);
        lv_obj_set_flag(card_compare, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(card_compare, &style_card, 0);
        lv_obj_add_style(card_compare, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_label_0 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_0, 4);
        lv_obj_set_y(lv_label_0, 2);
        lv_label_set_text(lv_label_0, "同环比对比");
        lv_obj_add_style(lv_label_0, &style_text_title, 0);

        lv_obj_t * lv_label_1 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_1, 4);
        lv_obj_set_y(lv_label_1, 18);
        lv_label_set_text(lv_label_1, "今日用电");
        lv_obj_add_style(lv_label_1, &style_text_muted, 0);

        lv_obj_t * lv_label_2 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_2, 70);
        lv_obj_set_y(lv_label_2, 18);
        lv_label_set_text(lv_label_2, "6.72 KWh");
        lv_obj_add_style(lv_label_2, &style_text_value, 0);

        lv_obj_t * lv_label_3 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_3, 130);
        lv_obj_set_y(lv_label_3, 18);
        lv_label_set_text(lv_label_3, "↑ 8.2%");
        lv_obj_add_style(lv_label_3, &style_text_highlight, 0);

        lv_obj_t * lv_label_4 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_4, 4);
        lv_obj_set_y(lv_label_4, 34);
        lv_label_set_text(lv_label_4, "本周用电");
        lv_obj_add_style(lv_label_4, &style_text_muted, 0);

        lv_obj_t * lv_label_5 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_5, 70);
        lv_obj_set_y(lv_label_5, 34);
        lv_label_set_text(lv_label_5, "42.3 KWh");
        lv_obj_add_style(lv_label_5, &style_text_value, 0);

        lv_obj_t * lv_label_6 = lv_label_create(card_compare);
        lv_obj_set_x(lv_label_6, 130);
        lv_obj_set_y(lv_label_6, 34);
        lv_label_set_text(lv_label_6, "↓ 3.1%");
        lv_obj_add_style(lv_label_6, &style_text_ok, 0);

        lv_obj_t * card_top5 = lv_obj_create(scroll_container);
        lv_obj_set_name(card_top5, "card_top5");
        lv_obj_set_x(card_top5, 0);
        lv_obj_set_y(card_top5, 75);
        lv_obj_set_width(card_top5, 220);
        lv_obj_set_height(card_top5, 100);
        lv_obj_set_flag(card_top5, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(card_top5, &style_card, 0);
        lv_obj_add_style(card_top5, &style_card_focused, LV_STATE_FOCUSED);
        lv_obj_t * lv_label_7 = lv_label_create(card_top5);
        lv_obj_set_x(lv_label_7, 4);
        lv_obj_set_y(lv_label_7, 2);
        lv_label_set_text(lv_label_7, "高耗电器 Top5");
        lv_obj_add_style(lv_label_7, &style_text_title, 0);

        lv_obj_t * lv_label_8 = lv_label_create(card_top5);
        lv_obj_set_x(lv_label_8, 6);
        lv_obj_set_y(lv_label_8, 18);
        lv_label_set_text(lv_label_8, "1. 空调 2.30KW");
        lv_obj_add_style(lv_label_8, &style_text_normal, 0);

        lv_obj_t * lv_label_9 = lv_label_create(card_top5);
        lv_obj_set_x(lv_label_9, 6);
        lv_obj_set_y(lv_label_9, 32);
        lv_label_set_text(lv_label_9, "2. 厨房电器 1.85KW");
        lv_obj_add_style(lv_label_9, &style_text_normal, 0);

        lv_obj_t * lv_label_10 = lv_label_create(card_top5);
        lv_obj_set_x(lv_label_10, 6);
        lv_obj_set_y(lv_label_10, 46);
        lv_label_set_text(lv_label_10, "3. 热水器 1.20KW");
        lv_obj_add_style(lv_label_10, &style_text_normal, 0);

        lv_obj_t * lv_label_11 = lv_label_create(card_top5);
        lv_obj_set_x(lv_label_11, 6);
        lv_obj_set_y(lv_label_11, 60);
        lv_label_set_text(lv_label_11, "4. 电冰箱 0.95KW");
        lv_obj_add_style(lv_label_11, &style_text_normal, 0);

        lv_obj_t * lv_label_12 = lv_label_create(card_top5);
        lv_obj_set_x(lv_label_12, 6);
        lv_obj_set_y(lv_label_12, 74);
        lv_label_set_text(lv_label_12, "5. 洗衣机 0.72KW");
        lv_obj_add_style(lv_label_12, &style_text_normal, 0);

        lv_obj_t * lv_obj_1 = lv_obj_create(scroll_container);
        lv_obj_set_x(lv_obj_1, 0);
        lv_obj_set_y(lv_obj_1, 248);
        lv_obj_set_width(lv_obj_1, 1);
        lv_obj_set_height(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);

        lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "4/8");
        lv_obj_set_name(bottom_bar, "bottom_bar");
        lv_obj_set_x(bottom_bar, 0);
        lv_obj_set_y(bottom_bar, 218);
        lv_obj_set_style_opa(bottom_bar, 0, 0);
        lv_obj_set_style_translate_y(bottom_bar, 20, 0);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_ENERGY_TIMELINE_CNT);
        at_array[SCREEN_ENERGY_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOAD_START, screen_energy_get_timeline(lv_obj_0, SCREEN_ENERGY_TIMELINE_SCREEN_OPEN), 0, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_energy_get_timeline(lv_obj_t * obj, screen_energy_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_ENERGY_TIMELINE_CNT) {
        LV_LOG_WARN("screen_energy has no timeline with %d ID", timeline_id);
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
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "scroll_container"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 250);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "scroll_container"));
    lv_anim_set_values(&a, -35, 0);
    lv_anim_set_duration(&a, 250);
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
    for(i = 0; i < _SCREEN_ENERGY_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

