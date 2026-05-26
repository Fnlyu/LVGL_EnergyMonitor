/**
 * @file screen_voltage_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_voltage_gen.h"
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

lv_obj_t * screen_voltage_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card;
    static lv_style_t style_card_main;
    static lv_style_t style_text_normal;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_value;
    static lv_style_t style_text_big_value;
    static lv_style_t style_text_ok;
    static lv_style_t style_text_warn;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_screen_bg);
        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x0b1220));

        lv_style_init(&style_card);
        lv_style_set_bg_color(&style_card, lv_color_hex(0x111c2e));
        lv_style_set_border_color(&style_card, lv_color_hex(0x26384f));
        lv_style_set_border_width(&style_card, 1);
        lv_style_set_radius(&style_card, 8);
        lv_style_set_pad_all(&style_card, 6);

        lv_style_init(&style_card_main);
        lv_style_set_bg_color(&style_card_main, lv_color_hex(0x10263c));
        lv_style_set_border_color(&style_card_main, lv_color_hex(0x2e5a7a));
        lv_style_set_border_width(&style_card_main, 1);
        lv_style_set_radius(&style_card_main, 10);
        lv_style_set_pad_all(&style_card_main, 8);

        lv_style_init(&style_text_normal);
        lv_style_set_text_color(&style_text_normal, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_text_normal, font_cn_12);

        lv_style_init(&style_text_muted);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x8fa3bf));
        lv_style_set_text_font(&style_text_muted, font_cn_12);

        lv_style_init(&style_text_value);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x4dd4ff));
        lv_style_set_text_font(&style_text_value, font_cn_18);

        lv_style_init(&style_text_big_value);
        lv_style_set_text_color(&style_text_big_value, lv_color_hex(0x4dd4ff));
        lv_style_set_text_font(&style_text_big_value, font_cn_24);

        lv_style_init(&style_text_ok);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_12);

        lv_style_init(&style_text_warn);
        lv_style_set_text_color(&style_text_warn, lv_color_hex(0xffd166));
        lv_style_set_text_font(&style_text_warn, font_cn_12);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "screen_voltage_#");

    lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
    lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "电压/频率", "12:30", "WiFi", "●");
    lv_obj_set_name(top_bar, "top_bar");
    lv_obj_set_x(top_bar, 0);
    lv_obj_set_y(top_bar, 0);
    
    lv_obj_t * main_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(main_card, "main_card");
    lv_obj_set_x(main_card, 10);
    lv_obj_set_y(main_card, 38);
    lv_obj_set_width(main_card, 220);
    lv_obj_set_height(main_card, 62);
    lv_obj_add_style(main_card, &style_card_main, 0);
    lv_obj_t * lv_label_0 = lv_label_create(main_card);
    lv_obj_set_x(lv_label_0, 0);
    lv_obj_set_y(lv_label_0, 0);
    lv_label_set_text(lv_label_0, "当前电压");
    lv_obj_add_style(lv_label_0, &style_text_muted, 0);
    
    lv_obj_t * label_voltage_main = lv_label_create(main_card);
    lv_obj_set_name(label_voltage_main, "label_voltage_main");
    lv_obj_set_x(label_voltage_main, 0);
    lv_obj_set_y(label_voltage_main, 23);
    lv_label_set_text(label_voltage_main, "---.- V");
    lv_obj_add_style(label_voltage_main, &style_text_big_value, 0);
    
    lv_obj_t * label_voltage_status = lv_label_create(main_card);
    lv_obj_set_name(label_voltage_status, "label_voltage_status");
    lv_obj_set_x(label_voltage_status, 158);
    lv_obj_set_y(label_voltage_status, 32);
    lv_label_set_text(label_voltage_status, "正常");
    lv_obj_add_style(label_voltage_status, &style_text_ok, 0);
    
    lv_obj_t * phase_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(phase_card, "phase_card");
    lv_obj_set_x(phase_card, 10);
    lv_obj_set_y(phase_card, 108);
    lv_obj_set_width(phase_card, 105);
    lv_obj_set_height(phase_card, 72);
    lv_obj_add_style(phase_card, &style_card, 0);
    lv_obj_t * lv_label_1 = lv_label_create(phase_card);
    lv_obj_set_x(lv_label_1, 0);
    lv_obj_set_y(lv_label_1, 0);
    lv_label_set_text(lv_label_1, "Ua");
    lv_obj_add_style(lv_label_1, &style_text_muted, 0);
    
    lv_obj_t * label_voltage_ua = lv_label_create(phase_card);
    lv_obj_set_name(label_voltage_ua, "label_voltage_ua");
    lv_obj_set_x(label_voltage_ua, 34);
    lv_obj_set_y(label_voltage_ua, 0);
    lv_label_set_text(label_voltage_ua, "---.-V");
    lv_obj_add_style(label_voltage_ua, &style_text_value, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(phase_card);
    lv_obj_set_x(lv_label_2, 0);
    lv_obj_set_y(lv_label_2, 24);
    lv_label_set_text(lv_label_2, "Ub");
    lv_obj_add_style(lv_label_2, &style_text_muted, 0);
    
    lv_obj_t * label_voltage_ub = lv_label_create(phase_card);
    lv_obj_set_name(label_voltage_ub, "label_voltage_ub");
    lv_obj_set_x(label_voltage_ub, 34);
    lv_obj_set_y(label_voltage_ub, 24);
    lv_label_set_text(label_voltage_ub, "---.-V");
    lv_obj_add_style(label_voltage_ub, &style_text_value, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(phase_card);
    lv_obj_set_x(lv_label_3, 0);
    lv_obj_set_y(lv_label_3, 48);
    lv_label_set_text(lv_label_3, "Uc");
    lv_obj_add_style(lv_label_3, &style_text_muted, 0);
    
    lv_obj_t * label_voltage_uc = lv_label_create(phase_card);
    lv_obj_set_name(label_voltage_uc, "label_voltage_uc");
    lv_obj_set_x(label_voltage_uc, 34);
    lv_obj_set_y(label_voltage_uc, 48);
    lv_label_set_text(label_voltage_uc, "---.-V");
    lv_obj_add_style(label_voltage_uc, &style_text_value, 0);
    
    lv_obj_t * freq_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(freq_card, "freq_card");
    lv_obj_set_x(freq_card, 125);
    lv_obj_set_y(freq_card, 108);
    lv_obj_set_width(freq_card, 105);
    lv_obj_set_height(freq_card, 72);
    lv_obj_add_style(freq_card, &style_card, 0);
    lv_obj_t * lv_label_4 = lv_label_create(freq_card);
    lv_obj_set_x(lv_label_4, 0);
    lv_obj_set_y(lv_label_4, 0);
    lv_label_set_text(lv_label_4, "频率");
    lv_obj_add_style(lv_label_4, &style_text_muted, 0);
    
    lv_obj_t * label_frequency = lv_label_create(freq_card);
    lv_obj_set_name(label_frequency, "label_frequency");
    lv_obj_set_x(label_frequency, 0);
    lv_obj_set_y(label_frequency, 22);
    lv_label_set_text(label_frequency, "--.--Hz");
    lv_obj_add_style(label_frequency, &style_text_value, 0);
    
    lv_obj_t * lv_label_5 = lv_label_create(freq_card);
    lv_obj_set_x(lv_label_5, 0);
    lv_obj_set_y(lv_label_5, 48);
    lv_label_set_text(lv_label_5, "状态");
    lv_obj_add_style(lv_label_5, &style_text_muted, 0);
    
    lv_obj_t * label_phase_status = lv_label_create(freq_card);
    lv_obj_set_name(label_phase_status, "label_phase_status");
    lv_obj_set_x(label_phase_status, 38);
    lv_obj_set_y(label_phase_status, 48);
    lv_label_set_text(label_phase_status, "正常");
    lv_obj_add_style(label_phase_status, &style_text_ok, 0);
    
    lv_obj_t * hint_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(hint_card, "hint_card");
    lv_obj_set_x(hint_card, 10);
    lv_obj_set_y(hint_card, 188);
    lv_obj_set_width(hint_card, 220);
    lv_obj_set_height(hint_card, 22);
    lv_obj_add_style(hint_card, &style_card, 0);
    lv_obj_t * label_voltage_hint = lv_label_create(hint_card);
    lv_obj_set_name(label_voltage_hint, "label_voltage_hint");
    lv_obj_set_x(label_voltage_hint, 0);
    lv_obj_set_y(label_voltage_hint, 0);
    lv_label_set_text(label_voltage_hint, "异常提示：无过压/欠压/断相");
    lv_obj_add_style(label_voltage_hint, &style_text_ok, 0);
    
    lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "2/8");
    lv_obj_set_name(bottom_bar, "bottom_bar");
    lv_obj_set_x(bottom_bar, 0);
    lv_obj_set_y(bottom_bar, 218);
    
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_VOLTAGE_TIMELINE_CNT);
    at_array[SCREEN_VOLTAGE_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, screen_voltage_get_timeline(lv_obj_0, SCREEN_VOLTAGE_TIMELINE_SCREEN_OPEN), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * screen_voltage_get_timeline(lv_obj_t * obj, screen_voltage_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_VOLTAGE_TIMELINE_CNT) {
        LV_LOG_WARN("screen_voltage has no timeline with %d ID", timeline_id);
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
    lv_anim_set_values(&a, 40, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "phase_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 160, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "phase_card"));
    lv_anim_set_values(&a, -35, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 160, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "freq_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 220, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "freq_card"));
    lv_anim_set_values(&a, 35, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 220, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "hint_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 300, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "hint_card"));
    lv_anim_set_values(&a, 25, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
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
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 380, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _SCREEN_VOLTAGE_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

