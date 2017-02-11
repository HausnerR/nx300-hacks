#include <Elementary.h>
#include <strings.h>
#include <Ecore.h>
#include <Ecore_Input.h>

Evas_Object *win, *bg, *box, *label, *button_cancel;

static void cancel_button_clicked(void *data, Evas_Object *obj, void *event_info)
{
    elm_exit();
    exit(255);
}

static Eina_Bool key_down_callback(void *data, int type, void *ev)
{
    Ecore_Event_Key *event = ev;

    if (!strcmp("Menu", event->key) || !strcmp("XF86PowerOff", event->key))
    {
        elm_exit();
        exit(255);
    }

    //printf("Key: %s\n", event->key);
    return ECORE_CALLBACK_PASS_ON;
}

EAPI int
elm_main(int argc, char **argv)
{
    ecore_event_handler_add(ECORE_EVENT_KEY_DOWN, key_down_callback, NULL);

    win = elm_win_add(NULL, "Info", ELM_WIN_BASIC);
    evas_object_move(win, 0, 0);
    evas_object_resize(win, 1000, 1000);
    elm_win_title_set(win, "Info");

    evas_object_show(win);


    win = elm_win_add(NULL, "Info", ELM_WIN_BASIC);
    elm_win_rotation_set(win, 270); //NX300 have rotated interface!
    evas_object_move(win, 160, 40);
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
    elm_object_text_set(label, "<align=center>Switch off camera for charge'n'shoot</align>");
    evas_object_size_hint_min_set(label, 700, 40);
    evas_object_size_hint_padding_set(label, 10, 10, 20, 10);
    elm_table_pack(table, label, 1, 1, 1, 1);
    evas_object_show(label);

    button_cancel = elm_button_add(win);
    elm_object_text_set(button_cancel, "Cancel");
    evas_object_size_hint_min_set(button_cancel, 300, 75);
    evas_object_size_hint_padding_set(button_cancel, 210, 210, 10, 10);
    elm_table_pack(table, button_cancel, 1, 2, 1, 1);
    evas_object_smart_callback_add(button_cancel, "clicked", cancel_button_clicked, NULL);
    evas_object_show(button_cancel);

    evas_object_show(win);

    elm_run();

    return 0;
}
ELM_MAIN()
