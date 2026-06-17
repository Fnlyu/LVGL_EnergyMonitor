/**
 * @file screen_wt3213_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_wt3213_gen.h"
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

lv_obj_t * screen_wt3213_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_screen_bg;
    static lv_style_t style_inner_panel;
    static lv_style_t style_panel;
    static lv_style_t style_top_panel;
    static lv_style_t style_metric_card;
    static lv_style_t style_accent_cyan;
    static lv_style_t style_accent_green;
    static lv_style_t style_accent_yellow;
    static lv_style_t style_divider;
    static lv_style_t style_alarm_track;
    static lv_style_t style_text_online;
    static lv_style_t style_text_title;
    static lv_style_t style_text_value;
    static lv_style_t style_text_value_small;
    static lv_style_t style_text_big;
    static lv_style_t style_text_cyan;
    static lv_style_t style_text_yellow;
    static lv_style_t style_text_muted;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_screen_bg);
        lv_style_set_bg_color(&style_screen_bg, lv_color_hex(0x05070a));

        lv_style_init(&style_inner_panel);
        lv_style_set_bg_color(&style_inner_panel, lv_color_hex(0x080c12));
        lv_style_set_border_color(&style_inner_panel, lv_color_hex(0x101a24));
        lv_style_set_border_width(&style_inner_panel, 1);
        lv_style_set_radius(&style_inner_panel, 10);
        lv_style_set_pad_all(&style_inner_panel, 0);

        lv_style_init(&style_panel);
        lv_style_set_bg_color(&style_panel, lv_color_hex(0x0b1118));
        lv_style_set_border_color(&style_panel, lv_color_hex(0x142331));
        lv_style_set_border_width(&style_panel, 1);
        lv_style_set_radius(&style_panel, 9);
        lv_style_set_pad_all(&style_panel, 0);

        lv_style_init(&style_top_panel);
        lv_style_set_bg_color(&style_top_panel, lv_color_hex(0x0b1118));
        lv_style_set_border_color(&style_top_panel, lv_color_hex(0x172331));
        lv_style_set_border_width(&style_top_panel, 1);
        lv_style_set_radius(&style_top_panel, 7);
        lv_style_set_pad_all(&style_top_panel, 0);

        lv_style_init(&style_metric_card);
        lv_style_set_bg_color(&style_metric_card, lv_color_hex(0x101821));
        lv_style_set_border_color(&style_metric_card, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_metric_card, 1);
        lv_style_set_radius(&style_metric_card, 7);
        lv_style_set_pad_all(&style_metric_card, 0);

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

        lv_style_init(&style_divider);
        lv_style_set_bg_color(&style_divider, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_divider, 0);
        lv_style_set_radius(&style_divider, 0);
        lv_style_set_pad_all(&style_divider, 0);

        lv_style_init(&style_alarm_track);
        lv_style_set_bg_color(&style_alarm_track, lv_color_hex(0x101821));
        lv_style_set_border_color(&style_alarm_track, lv_color_hex(0x1a2632));
        lv_style_set_border_width(&style_alarm_track, 1);
        lv_style_set_radius(&style_alarm_track, 4);
        lv_style_set_pad_all(&style_alarm_track, 0);

        lv_style_init(&style_text_online);
        lv_style_set_text_color(&style_text_online, lv_color_hex(0x32f27a));
        lv_style_set_text_font(&style_text_online, font_cn_12);

        lv_style_init(&style_text_title);
        lv_style_set_text_color(&style_text_title, lv_color_hex(0x7a8a99));
        lv_style_set_text_font(&style_text_title, font_cn_12);

        lv_style_init(&style_text_value);
        lv_style_set_text_color(&style_text_value, lv_color_hex(0xe6eef5));
        lv_style_set_text_font(&style_text_value, font_cn_14);

        lv_style_init(&style_text_value_small);
        lv_style_set_text_color(&style_text_value_small, lv_color_hex(0xe6eef5));
        lv_style_set_text_font(&style_text_value_small, font_cn_12);

        lv_style_init(&style_text_big);
        lv_style_set_text_color(&style_text_big, lv_color_hex(0x20e6d2));
        lv_style_set_text_font(&style_text_big, font_cn_24);

        lv_style_init(&style_text_cyan);
        lv_style_set_text_color(&style_text_cyan, lv_color_hex(0x20e6d2));
        lv_style_set_text_font(&style_text_cyan, font_cn_12);

        lv_style_init(&style_text_yellow);
        lv_style_set_text_color(&style_text_yellow, lv_color_hex(0xffb020));
        lv_style_set_text_font(&style_text_yellow, font_cn_12);

        lv_style_init(&style_text_muted);
        lv_style_set_text_color(&style_text_muted, lv_color_hex(0x7a8a99));
        lv_style_set_text_font(&style_text_muted, font_cn_12);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "screen_wt3213_#");

    lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
    lv_obj_t * inner_panel = lv_obj_create(lv_obj_0);
    lv_obj_set_name(inner_panel, "inner_panel");
    lv_obj_set_x(inner_panel, 4);
    lv_obj_set_y(inner_panel, 4);
    lv_obj_set_width(inner_panel, 232);
    lv_obj_set_height(inner_panel, 232);
    lv_obj_add_style(inner_panel, &style_inner_panel, 0);
    
    lv_obj_t * top_bar = lv_obj_create(lv_obj_0);
    lv_obj_set_name(top_bar, "top_bar");
    lv_obj_set_x(top_bar, 8);
    lv_obj_set_y(top_bar, 8);
    lv_obj_set_width(top_bar, 224);
    lv_obj_set_height(top_bar, 24);
    lv_obj_add_style(top_bar, &style_top_panel, 0);
    lv_obj_t * status_dot = lv_obj_create(top_bar);
    lv_obj_set_name(status_dot, "status_dot");
    lv_obj_set_x(status_dot, 7);
    lv_obj_set_y(status_dot, 8);
    lv_obj_set_width(status_dot, 6);
    lv_obj_set_height(status_dot, 6);
    lv_obj_add_style(status_dot, &style_accent_green, 0);
    
    lv_obj_t * label_device_status = lv_label_create(top_bar);
    lv_obj_set_name(label_device_status, "label_device_status");
    lv_obj_set_x(label_device_status, 17);
    lv_obj_set_y(label_device_status, 5);
    lv_label_set_text(label_device_status, "ONLINE");
    lv_obj_add_style(label_device_status, &style_text_online, 0);
    
    lv_obj_t * label_time = lv_label_create(top_bar);
    lv_obj_set_name(label_time, "label_time");
    lv_obj_set_x(label_time, 94);
    lv_obj_set_y(label_time, 5);
    lv_label_set_text(label_time, "14:28");
    lv_obj_add_style(label_time, &style_text_value_small, 0);
    
    lv_obj_t * label_wifi_icon = lv_label_create(top_bar);
    lv_obj_set_name(label_wifi_icon, "label_wifi_icon");
    lv_obj_set_x(label_wifi_icon, 149);
    lv_obj_set_y(label_wifi_icon, 5);
    lv_label_set_text(label_wifi_icon, "WiFi");
    lv_obj_add_style(label_wifi_icon, &style_text_cyan, 0);
    
    lv_obj_t * label_ble_icon = lv_label_create(top_bar);
    lv_obj_set_name(label_ble_icon, "label_ble_icon");
    lv_obj_set_x(label_ble_icon, 176);
    lv_obj_set_y(label_ble_icon, 5);
    lv_label_set_text(label_ble_icon, "B");
    lv_obj_add_style(label_ble_icon, &style_text_muted, 0);
    
    lv_obj_t * label_rs485_icon = lv_label_create(top_bar);
    lv_obj_set_name(label_rs485_icon, "label_rs485_icon");
    lv_obj_set_x(label_rs485_icon, 194);
    lv_obj_set_y(label_rs485_icon, 5);
    lv_label_set_text(label_rs485_icon, "485");
    lv_obj_add_style(label_rs485_icon, &style_text_muted, 0);
    
    lv_obj_t * power_area = lv_obj_create(lv_obj_0);
    lv_obj_set_name(power_area, "power_area");
    lv_obj_set_x(power_area, 8);
    lv_obj_set_y(power_area, 38);
    lv_obj_set_width(power_area, 224);
    lv_obj_set_height(power_area, 70);
    lv_obj_add_style(power_area, &style_panel, 0);
    lv_obj_t * lv_label_0 = lv_label_create(power_area);
    lv_obj_set_x(lv_label_0, 85);
    lv_obj_set_y(lv_label_0, 8);
    lv_label_set_text(lv_label_0, "TOTAL POWER");
    lv_obj_add_style(lv_label_0, &style_text_title, 0);
    
    lv_obj_t * label_total_power_value = lv_label_create(power_area);
    lv_obj_set_name(label_total_power_value, "label_total_power_value");
    lv_obj_set_x(label_total_power_value, 44);
    lv_obj_set_y(label_total_power_value, 17);
    lv_label_set_text(label_total_power_value, "3.28");
    lv_obj_add_style(label_total_power_value, &style_text_big, 0);
    
    lv_obj_t * label_total_power_unit = lv_label_create(power_area);
    lv_obj_set_name(label_total_power_unit, "label_total_power_unit");
    lv_obj_set_x(label_total_power_unit, 152);
    lv_obj_set_y(label_total_power_unit, 34);
    lv_label_set_text(label_total_power_unit, "kW");
    lv_obj_add_style(label_total_power_unit, &style_text_value, 0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(power_area);
    lv_obj_set_x(lv_obj_1, 80);
    lv_obj_set_y(lv_obj_1, 58);
    lv_obj_set_width(lv_obj_1, 5);
    lv_obj_set_height(lv_obj_1, 5);
    lv_obj_add_style(lv_obj_1, &style_accent_green, 0);
    
    lv_obj_t * label_alarm_status = lv_label_create(power_area);
    lv_obj_set_name(label_alarm_status, "label_alarm_status");
    lv_obj_set_x(label_alarm_status, 89);
    lv_obj_set_y(label_alarm_status, 53);
    lv_label_set_text(label_alarm_status, "NORMAL");
    lv_obj_add_style(label_alarm_status, &style_text_online, 0);
    
    lv_obj_t * voltage_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(voltage_card, "voltage_card");
    lv_obj_set_x(voltage_card, 8);
    lv_obj_set_y(voltage_card, 116);
    lv_obj_set_width(voltage_card, 70);
    lv_obj_set_height(voltage_card, 42);
    lv_obj_add_style(voltage_card, &style_metric_card, 0);
    lv_obj_t * lv_obj_2 = lv_obj_create(voltage_card);
    lv_obj_set_x(lv_obj_2, 0);
    lv_obj_set_y(lv_obj_2, 0);
    lv_obj_set_width(lv_obj_2, 3);
    lv_obj_set_height(lv_obj_2, 42);
    lv_obj_add_style(lv_obj_2, &style_accent_cyan, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(voltage_card);
    lv_obj_set_x(lv_label_1, 7);
    lv_obj_set_y(lv_label_1, 5);
    lv_label_set_text(lv_label_1, "VOLTAGE");
    lv_obj_add_style(lv_label_1, &style_text_title, 0);
    
    lv_obj_t * label_voltage = lv_label_create(voltage_card);
    lv_obj_set_name(label_voltage, "label_voltage");
    lv_obj_set_x(label_voltage, 7);
    lv_obj_set_y(label_voltage, 20);
    lv_label_set_text(label_voltage, "220.3 V");
    lv_obj_add_style(label_voltage, &style_text_value_small, 0);
    
    lv_obj_t * current_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(current_card, "current_card");
    lv_obj_set_x(current_card, 85);
    lv_obj_set_y(current_card, 116);
    lv_obj_set_width(current_card, 70);
    lv_obj_set_height(current_card, 42);
    lv_obj_add_style(current_card, &style_metric_card, 0);
    lv_obj_t * lv_obj_3 = lv_obj_create(current_card);
    lv_obj_set_x(lv_obj_3, 0);
    lv_obj_set_y(lv_obj_3, 0);
    lv_obj_set_width(lv_obj_3, 3);
    lv_obj_set_height(lv_obj_3, 42);
    lv_obj_add_style(lv_obj_3, &style_accent_green, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(current_card);
    lv_obj_set_x(lv_label_2, 7);
    lv_obj_set_y(lv_label_2, 5);
    lv_label_set_text(lv_label_2, "CURRENT");
    lv_obj_add_style(lv_label_2, &style_text_title, 0);
    
    lv_obj_t * label_current = lv_label_create(current_card);
    lv_obj_set_name(label_current, "label_current");
    lv_obj_set_x(label_current, 7);
    lv_obj_set_y(label_current, 20);
    lv_label_set_text(label_current, "12.6 A");
    lv_obj_add_style(label_current, &style_text_value_small, 0);
    
    lv_obj_t * pf_card = lv_obj_create(lv_obj_0);
    lv_obj_set_name(pf_card, "pf_card");
    lv_obj_set_x(pf_card, 162);
    lv_obj_set_y(pf_card, 116);
    lv_obj_set_width(pf_card, 70);
    lv_obj_set_height(pf_card, 42);
    lv_obj_add_style(pf_card, &style_metric_card, 0);
    lv_obj_t * lv_obj_4 = lv_obj_create(pf_card);
    lv_obj_set_x(lv_obj_4, 0);
    lv_obj_set_y(lv_obj_4, 0);
    lv_obj_set_width(lv_obj_4, 3);
    lv_obj_set_height(lv_obj_4, 42);
    lv_obj_add_style(lv_obj_4, &style_accent_yellow, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(pf_card);
    lv_obj_set_x(lv_label_3, 7);
    lv_obj_set_y(lv_label_3, 5);
    lv_label_set_text(lv_label_3, "PF");
    lv_obj_add_style(lv_label_3, &style_text_title, 0);
    
    lv_obj_t * label_power_factor = lv_label_create(pf_card);
    lv_obj_set_name(label_power_factor, "label_power_factor");
    lv_obj_set_x(label_power_factor, 7);
    lv_obj_set_y(label_power_factor, 18);
    lv_label_set_text(label_power_factor, "0.98");
    lv_obj_add_style(label_power_factor, &style_text_value, 0);
    
    lv_obj_t * energy_flow_area = lv_obj_create(lv_obj_0);
    lv_obj_set_name(energy_flow_area, "energy_flow_area");
    lv_obj_set_x(energy_flow_area, 8);
    lv_obj_set_y(energy_flow_area, 166);
    lv_obj_set_width(energy_flow_area, 224);
    lv_obj_set_height(energy_flow_area, 66);
    lv_obj_add_style(energy_flow_area, &style_panel, 0);
    lv_obj_t * lv_label_4 = lv_label_create(energy_flow_area);
    lv_obj_set_x(lv_label_4, 10);
    lv_obj_set_y(lv_label_4, 8);
    lv_label_set_text(lv_label_4, "ENERGY");
    lv_obj_add_style(lv_label_4, &style_text_title, 0);
    
    lv_obj_t * label_energy = lv_label_create(energy_flow_area);
    lv_obj_set_name(label_energy, "label_energy");
    lv_obj_set_x(label_energy, 10);
    lv_obj_set_y(label_energy, 22);
    lv_label_set_text(label_energy, "128.6 kWh");
    lv_obj_add_style(label_energy, &style_text_value, 0);
    
    lv_obj_t * lv_obj_5 = lv_obj_create(energy_flow_area);
    lv_obj_set_x(lv_obj_5, 108);
    lv_obj_set_y(lv_obj_5, 10);
    lv_obj_set_width(lv_obj_5, 1);
    lv_obj_set_height(lv_obj_5, 44);
    lv_obj_add_style(lv_obj_5, &style_divider, 0);
    
    lv_obj_t * lv_label_5 = lv_label_create(energy_flow_area);
    lv_obj_set_x(lv_label_5, 122);
    lv_obj_set_y(lv_label_5, 8);
    lv_label_set_text(lv_label_5, "PV EXPORT");
    lv_obj_add_style(lv_label_5, &style_text_title, 0);
    
    lv_obj_t * label_flow_source = lv_label_create(energy_flow_area);
    lv_obj_set_name(label_flow_source, "label_flow_source");
    lv_obj_set_x(label_flow_source, 122);
    lv_obj_set_y(label_flow_source, 28);
    lv_label_set_text(label_flow_source, "PV");
    lv_obj_add_style(label_flow_source, &style_text_yellow, 0);
    
    lv_obj_t * lv_obj_6 = lv_obj_create(energy_flow_area);
    lv_obj_set_x(lv_obj_6, 141);
    lv_obj_set_y(lv_obj_6, 31);
    lv_obj_set_width(lv_obj_6, 6);
    lv_obj_set_height(lv_obj_6, 6);
    lv_obj_add_style(lv_obj_6, &style_accent_yellow, 0);
    
    lv_obj_t * flow_line = lv_obj_create(energy_flow_area);
    lv_obj_set_name(flow_line, "flow_line");
    lv_obj_set_x(flow_line, 146);
    lv_obj_set_y(flow_line, 34);
    lv_obj_set_width(flow_line, 28);
    lv_obj_set_height(flow_line, 2);
    lv_obj_add_style(flow_line, &style_accent_cyan, 0);
    
    lv_obj_t * flow_arrow_head = lv_label_create(energy_flow_area);
    lv_obj_set_name(flow_arrow_head, "flow_arrow_head");
    lv_obj_set_x(flow_arrow_head, 171);
    lv_obj_set_y(flow_arrow_head, 28);
    lv_label_set_text(flow_arrow_head, "");
    lv_obj_add_style(flow_arrow_head, &style_text_cyan, 0);
    
    lv_obj_t * lv_obj_7 = lv_obj_create(energy_flow_area);
    lv_obj_set_x(lv_obj_7, 176);
    lv_obj_set_y(lv_obj_7, 31);
    lv_obj_set_width(lv_obj_7, 6);
    lv_obj_set_height(lv_obj_7, 6);
    lv_obj_add_style(lv_obj_7, &style_accent_cyan, 0);
    
    lv_obj_t * label_flow_target = lv_label_create(energy_flow_area);
    lv_obj_set_name(label_flow_target, "label_flow_target");
    lv_obj_set_x(label_flow_target, 185);
    lv_obj_set_y(label_flow_target, 28);
    lv_label_set_text(label_flow_target, "HOME");
    lv_obj_add_style(label_flow_target, &style_text_cyan, 0);
    
    lv_obj_t * alarm_track = lv_obj_create(lv_obj_0);
    lv_obj_set_name(alarm_track, "alarm_track");
    lv_obj_set_x(alarm_track, 151);
    lv_obj_set_y(alarm_track, 219);
    lv_obj_set_width(alarm_track, 73);
    lv_obj_set_height(alarm_track, 7);
    lv_obj_add_style(alarm_track, &style_alarm_track, 0);
    
    lv_obj_t * alarm_dot = lv_obj_create(lv_obj_0);
    lv_obj_set_name(alarm_dot, "alarm_dot");
    lv_obj_set_x(alarm_dot, 157);
    lv_obj_set_y(alarm_dot, 221);
    lv_obj_set_width(alarm_dot, 3);
    lv_obj_set_height(alarm_dot, 3);
    lv_obj_add_style(alarm_dot, &style_accent_green, 0);
    
    lv_obj_t * alarm_text = lv_label_create(lv_obj_0);
    lv_obj_set_name(alarm_text, "alarm_text");
    lv_obj_set_x(alarm_text, 164);
    lv_obj_set_y(alarm_text, 217);
    lv_label_set_text(alarm_text, "ALARM READY");
    lv_obj_add_style(alarm_text, &style_text_muted, 0);
    
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_WT3213_TIMELINE_CNT);
    at_array[SCREEN_WT3213_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, screen_wt3213_get_timeline(lv_obj_0, SCREEN_WT3213_TIMELINE_SCREEN_OPEN), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * screen_wt3213_get_timeline(lv_obj_t * obj, screen_wt3213_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_WT3213_TIMELINE_CNT) {
        LV_LOG_WARN("screen_wt3213 has no timeline with %d ID", timeline_id);
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
    lv_anim_set_values(&a, -18, 0);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "power_area"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "power_area"));
    lv_anim_set_values(&a, -18, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 80, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "voltage_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 160, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "voltage_card"));
    lv_anim_set_values(&a, -30, 0);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 160, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "current_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 220, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "current_card"));
    lv_anim_set_values(&a, 18, 0);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 220, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "pf_card"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 280, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "pf_card"));
    lv_anim_set_values(&a, 30, 0);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 280, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "energy_flow_area"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 360, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "energy_flow_area"));
    lv_anim_set_values(&a, 22, 0);
    lv_anim_set_duration(&a, 220);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 360, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "alarm_track"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 440, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "alarm_dot"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 460, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "alarm_text"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 180);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 480, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _SCREEN_WT3213_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

