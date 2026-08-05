/**
 * @file ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "ui_gen.h"

#if defined(LV_USE_XML) && LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t ui_target = UI_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_cn_12;
extern lv_font_t font_cn_12_data;
lv_font_t * font_cn_14;
extern lv_font_t font_cn_14_data;
lv_font_t * font_cn_16;
extern lv_font_t font_cn_16_data;
lv_font_t * font_cn_18;
extern lv_font_t font_cn_18_data;
lv_font_t * font_cn_20;
extern lv_font_t font_cn_20_data;
lv_font_t * font_cn_24;
extern lv_font_t font_cn_24_data;
lv_font_t * font_cn_34;
extern lv_font_t font_cn_34_data;

/*----------------
 * Images
 *----------------*/



/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ui_init_gen(const char * asset_path)
{

    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        if (!font_cn_12) {
            /* font_cn_12 */
            /* get font 'font_cn_12' from a C array */
            font_cn_12 = &font_cn_12_data;

        }
        if (!font_cn_14) {
            /* font_cn_14 */
            /* get font 'font_cn_14' from a C array */
            font_cn_14 = &font_cn_14_data;

        }
        if (!font_cn_16) {
            /* font_cn_16 */
            /* get font 'font_cn_16' from a C array */
            font_cn_16 = &font_cn_16_data;

        }
        if (!font_cn_18) {
            /* font_cn_18 */
            /* get font 'font_cn_18' from a C array */
            font_cn_18 = &font_cn_18_data;

        }
        if (!font_cn_20) {
            /* font_cn_20 */
            /* get font 'font_cn_20' from a C array */
            font_cn_20 = &font_cn_20_data;

        }
        if (!font_cn_24) {
            /* font_cn_24 */
            /* get font 'font_cn_24' from a C array */
            font_cn_24 = &font_cn_24_data;

        }
        if (!font_cn_34) {
            /* font_cn_34 */
            /* get font 'font_cn_34' from a C array */
            font_cn_34 = &font_cn_34_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/



    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    /*----------------
     * Translations
     *----------------*/

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_cn_12, "font_cn_12");
    check_font(&font_cn_14, "font_cn_14");
    check_font(&font_cn_16, "font_cn_16");
    check_font(&font_cn_18, "font_cn_18");
    check_font(&font_cn_20, "font_cn_20");
    check_font(&font_cn_24, "font_cn_24");
    check_font(&font_cn_34, "font_cn_34");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_cn_12", font_cn_12);
    lv_xml_register_font(NULL, "font_cn_14", font_cn_14);
    lv_xml_register_font(NULL, "font_cn_16", font_cn_16);
    lv_xml_register_font(NULL, "font_cn_18", font_cn_18);
    lv_xml_register_font(NULL, "font_cn_20", font_cn_20);
    lv_xml_register_font(NULL, "font_cn_24", font_cn_24);
    lv_xml_register_font(NULL, "font_cn_34", font_cn_34);

    /* Register subjects */

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if defined(LV_USE_XML) && LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void ui_set_target(uint32_t target)
{
    ui_target = target;
}

uint32_t ui_get_target(void)
{
    return ui_target;
}

bool ui_check_target(uint32_t target)
{
    return (ui_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}