#ifndef HELLO_WORLD_SCREEN_H
#define HELLO_WORLD_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

/**
 * Create and load a simple Hello World screen.
 *
 * The screen contains one centered LVGL button with the text "Hello World".
 * Call this after LVGL has been initialized.
 */
lv_obj_t * hello_world_screen_create(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* HELLO_WORLD_SCREEN_H */
