#include <Elementary.h>
#include <strings.h>
#include <Ecore.h>
#include <Ecore_Input.h>

Evas_Object *win, *bg, *box, *label, *input, *button_cancel, *button_ok;

static void ok_button_clicked(void *data, Evas_Object *obj, void *event_info)
{
    int i = strtol(elm_object_text_get(input), NULL, 10);

    system("st lcd set 4");

    if (i == 0) {
        system("st key push s1; st key push s2 &");
    } else {
        char* buf = (char *)malloc(100 * sizeof(char));
        sprintf(buf, "while true; do st key push s1; st key click s2; st key release s1; sleep %d; done &", i);
        system(buf);
    }

    elm_exit();
    exit(0);
}

static void cancel_button_clicked(void *data, Evas_Object *obj, void *event_info)
{
    elm_exit();
    exit(255);
}

static Eina_Bool key_down_callback(void *data, int type, void *ev)
{
    Ecore_Event_Key *event = ev;

    if (!strcmp("KP_Enter", event->key))
    {
        ok_button_clicked(NULL, NULL, NULL);
    }

    if (!strcmp("Menu", event->key))
    {
        cancel_button_clicked(NULL, NULL, NULL);
    }

    if (!strcmp("KP_Up", event->key) || !strcmp("KP_Down", event->key))
    {
        int i = strtol(elm_object_text_get(input), NULL, 10);
        if (!strcmp("KP_Up", event->key) && i < 999) i++;
        if (!strcmp("KP_Down", event->key) && i > 0) i--;

        char* buf = (char *)malloc(3 * sizeof(char));
        sprintf(buf, "%d", i);
        elm_object_text_set(input, buf);
        elm_entry_cursor_pos_set(input, 10000);
    }

    //printf("Key: %s\n",event->key);
    return ECORE_CALLBACK_PASS_ON;
}

EAPI int
elm_main(int argc, char **argv)
{
    ecore_event_handler_add(ECORE_EVENT_KEY_DOWN, key_down_callback, NULL);

    win = elm_win_add(NULL, "Info", ELM_WIN_BASIC);
    elm_win_rotation_set(win, 270);
    evas_object_move(win, 310, 80);
    elm_win_title_set(win, "Info");
    //evas_object_smart_callback_add(win, "delete,request", ok_button_clicked, NULL);

    bg = elm_bg_add(win);
    elm_bg_color_set(bg, 230, 230, 230);
    elm_win_resize_object_add(win, bg);
    evas_object_show(bg);

    box = elm_box_add(win);
    elm_win_resize_object_add(win, box);
    evas_object_show(box);

    Evas_Object* table = elm_table_add(win);
    elm_box_pack_end(box, table);
    evas_object_show(table);

    label = elm_label_add(win);
    elm_object_text_set(label, "<align=center>Interval (s):</align>");
    evas_object_size_hint_min_set(label, 300, 40);
    evas_object_size_hint_padding_set(label, 10, 10, 20, 10);
    elm_table_pack(table, label, 1, 1, 1, 1);
    evas_object_show(label);

    static Elm_Entry_Filter_Limit_Size limit_size = {
       .max_char_count = 3,
       .max_byte_count = 0
    };

    input = elm_entry_add(win);
    elm_entry_entry_set(input, "30");
    elm_entry_cursor_pos_set(input, 10000);
    elm_entry_single_line_set(input, EINA_TRUE);
    elm_entry_input_panel_layout_set(input, ELM_INPUT_PANEL_LAYOUT_NUMBERONLY);
    elm_entry_markup_filter_append(input, elm_entry_filter_limit_size, &limit_size);
    evas_object_size_hint_padding_set(input, 10, 10, 20, 10);
    elm_table_pack(table, input, 2, 1, 1, 1);
    evas_object_show(input);
    elm_object_focus_set(input, EINA_TRUE);

    button_cancel = elm_button_add(win);
    elm_object_text_set(button_cancel, "Cancel");
    evas_object_size_hint_min_set(button_cancel, 300, 75);
    evas_object_size_hint_padding_set(button_cancel, 10, 10, 10, 10);
    elm_table_pack(table, button_cancel, 1, 2, 1, 1);
    evas_object_smart_callback_add(button_cancel, "clicked", cancel_button_clicked, NULL);
    evas_object_show(button_cancel);

    button_ok = elm_button_add(win);
    elm_object_text_set(button_ok, "OK");
    evas_object_size_hint_min_set(button_ok, 300, 75);
    evas_object_size_hint_padding_set(button_ok, 10, 10, 10, 10);
    elm_table_pack(table, button_ok, 2, 2, 1, 1);
    evas_object_smart_callback_add(button_ok, "clicked", ok_button_clicked, NULL);
    evas_object_show(button_ok);

    evas_object_show(win);

    elm_run();

    return 0;
}
ELM_MAIN()
