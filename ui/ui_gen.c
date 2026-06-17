/**
 * @file ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "ui_gen.h"

#if LV_USE_XML
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

/**********************
 *  STATIC VARIABLES
 **********************/

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
lv_font_t * font_cn_18;
extern lv_font_t font_cn_18_data;
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
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* get font 'font_cn_12' from a C array */
    font_cn_12 = &font_cn_12_data;
    /* get font 'font_cn_14' from a C array */
    font_cn_14 = &font_cn_14_data;
    /* get font 'font_cn_18' from a C array */
    font_cn_18 = &font_cn_18_data;
    /* get font 'font_cn_24' from a C array */
    font_cn_24 = &font_cn_24_data;
    /* get font 'font_cn_34' from a C array */
    font_cn_34 = &font_cn_34_data;


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

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "font_cn_12", font_cn_12);
    lv_xml_register_font(NULL, "font_cn_14", font_cn_14);
    lv_xml_register_font(NULL, "font_cn_18", font_cn_18);
    lv_xml_register_font(NULL, "font_cn_24", font_cn_24);
    lv_xml_register_font(NULL, "font_cn_34", font_cn_34);

    /* Register subjects */

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/