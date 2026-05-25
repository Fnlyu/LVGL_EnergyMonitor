#include "hello_world_screen.h"

static void hello_world_button_event_cb(lv_event_t * event)
{
    LV_UNUSED(event);
}

lv_obj_t * hello_world_screen_create(void)
{
    lv_obj_t * screen = lv_obj_create(NULL);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t * button = lv_btn_create(screen);
    lv_obj_set_size(button, 140, 50);
    lv_obj_center(button);
    lv_obj_add_event_cb(button, hello_world_button_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t * label = lv_label_create(button);
    lv_label_set_text(label, "Hello World");
    lv_obj_center(label);

    lv_scr_load(screen);

    return screen;
}
