/**
 * @file screen_wifi_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_wifi_gen.h"
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

lv_obj_t * screen_wifi_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_card_main;
    static lv_style_t style_text_normal;
    static lv_style_t style_text_muted;
    static lv_style_t style_text_title;
    static lv_style_t style_text_value;
    static lv_style_t style_text_ok;
    static lv_style_t style_text_fail;
    static lv_style_t style_text_warn;
    static lv_style_t style_btn_text;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen_bg);
        lv_style_init(&style_card_main);
        lv_style_init(&style_text_normal);
        lv_style_init(&style_text_muted);
        lv_style_init(&style_text_title);
        lv_style_init(&style_text_value);
        lv_style_init(&style_text_ok);
        lv_style_init(&style_text_fail);
        lv_style_init(&style_text_warn);
        lv_style_init(&style_btn_text);

        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x05070a));
        lv_style_set_bg_color(&style_card_main, lv_color_hex(0x0b1118));
        lv_style_set_border_color(&style_card_main, lv_color_hex(0x172331));
        lv_style_set_border_width(&style_card_main, 1);
        lv_style_set_radius(&style_card_main, 10);
        lv_style_set_pad_all(&style_card_main, 8);
        lv_style_set_text_color(&style_text_normal, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_text_normal, font_cn_12);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_muted, font_cn_12);
        lv_style_set_text_color(&style_text_title, lv_color_hex(0xbfd6ec));
        lv_style_set_text_font(&style_text_title, font_cn_16);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0x20e6d2));
        lv_style_set_text_font(&style_text_value, font_cn_14);
        lv_style_set_text_color(&style_text_ok, lv_color_hex(0x61d394));
        lv_style_set_text_font(&style_text_ok, font_cn_12);
        lv_style_set_text_color(&style_text_fail, lv_color_hex(0xff6b6b));
        lv_style_set_text_font(&style_text_fail, font_cn_12);
        lv_style_set_text_color(&style_text_warn, lv_color_hex(0xffd166));
        lv_style_set_text_font(&style_text_warn, font_cn_12);
        lv_style_set_text_color(&style_btn_text, lv_color_hex(0xd8e2f0));
        lv_style_set_text_font(&style_btn_text, font_cn_12);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_wifi_#");

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        lv_obj_t * top_bar = top_status_bar_create(lv_obj_0, "WiFi 配网", "12:30", "AP", "●");
        lv_obj_set_name(top_bar, "top_bar");
        lv_obj_set_x(top_bar, 0);
        lv_obj_set_y(top_bar, 0);
        lv_obj_set_style_opa(top_bar, 0, 0);
        lv_obj_set_style_translate_y(top_bar, -20, 0);

        lv_obj_t * main_card = lv_obj_create(lv_obj_0);
        lv_obj_set_name(main_card, "main_card");
        lv_obj_set_x(main_card, 10);
        lv_obj_set_y(main_card, 38);
        lv_obj_set_width(main_card, 220);
        lv_obj_set_height(main_card, 172);
        lv_obj_set_flag(main_card, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_opa(main_card, 0, 0);
        lv_obj_set_style_translate_x(main_card, -40, 0);
        lv_obj_add_style(main_card, &style_card_main, 0);
        lv_obj_t * lv_label_0 = lv_label_create(main_card);
        lv_obj_set_x(lv_label_0, 0);
        lv_obj_set_y(lv_label_0, 2);
        lv_obj_set_width(lv_label_0, lv_pct(100));
        lv_label_set_text(lv_label_0, "AP 热点配网");
        lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_add_style(lv_label_0, &style_text_title, 0);

        lv_obj_t * lv_label_1 = lv_label_create(main_card);
        lv_obj_set_x(lv_label_1, 0);
        lv_obj_set_y(lv_label_1, 32);
        lv_label_set_text(lv_label_1, "热点名称");
        lv_obj_add_style(lv_label_1, &style_text_muted, 0);

        lv_obj_t * label_ssid = lv_label_create(main_card);
        lv_obj_set_name(label_ssid, "label_ssid");
        lv_obj_set_x(label_ssid, 78);
        lv_obj_set_y(label_ssid, 32);
        lv_label_set_text(label_ssid, "SmartHome_8266");
        lv_obj_add_style(label_ssid, &style_text_value, 0);

        lv_obj_t * lv_label_2 = lv_label_create(main_card);
        lv_obj_set_x(lv_label_2, 0);
        lv_obj_set_y(lv_label_2, 56);
        lv_label_set_text(lv_label_2, "配置地址");
        lv_obj_add_style(lv_label_2, &style_text_muted, 0);

        lv_obj_t * label_ip = lv_label_create(main_card);
        lv_obj_set_name(label_ip, "label_ip");
        lv_obj_set_x(label_ip, 78);
        lv_obj_set_y(label_ip, 56);
        lv_label_set_text(label_ip, "192.168.4.1");
        lv_obj_add_style(label_ip, &style_text_value, 0);

        lv_obj_t * lv_label_3 = lv_label_create(main_card);
        lv_obj_set_x(lv_label_3, 0);
        lv_obj_set_y(lv_label_3, 84);
        lv_obj_set_width(lv_label_3, lv_pct(100));
        lv_label_set_text(lv_label_3, "1 手机连接此 WiFi 热点 2 浏览器访问配置地址 3 等待设备自动联网");
        lv_obj_set_style_text_align(lv_label_3, LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_style(lv_label_3, &style_text_muted, 0);

        lv_obj_t * lv_label_4 = lv_label_create(main_card);
        lv_obj_set_x(lv_label_4, 0);
        lv_obj_set_y(lv_label_4, 146);
        lv_obj_set_width(lv_label_4, lv_pct(100));
        lv_label_set_text(lv_label_4, "状态: ● 等待连接");
        lv_obj_set_style_text_align(lv_label_4, LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_style(lv_label_4, &style_text_warn, 0);

        lv_obj_t * label_status = lv_label_create(main_card);
        lv_obj_set_name(label_status, "label_status");
        lv_obj_set_x(label_status, 38);
        lv_obj_set_y(label_status, 146);
        lv_label_set_text(label_status, "");
        lv_obj_add_style(label_status, &style_text_warn, 0);

        lv_obj_t * bottom_bar = bottom_key_bar_create(lv_obj_0, "上/下 切页", "确认 详情", "0/8");
        lv_obj_set_name(bottom_bar, "bottom_bar");
        lv_obj_set_x(bottom_bar, 0);
        lv_obj_set_y(bottom_bar, 218);
        lv_obj_set_style_opa(bottom_bar, 0, 0);
        lv_obj_set_style_translate_y(bottom_bar, 20, 0);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_WIFI_TIMELINE_CNT);
        at_array[SCREEN_WIFI_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOAD_START, screen_wifi_get_timeline(lv_obj_0, SCREEN_WIFI_TIMELINE_SCREEN_OPEN), 0, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_wifi_get_timeline(lv_obj_t * obj, screen_wifi_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_WIFI_TIMELINE_CNT) {
        LV_LOG_WARN("screen_wifi has no timeline with %d ID", timeline_id);
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
    for(i = 0; i < _SCREEN_WIFI_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

