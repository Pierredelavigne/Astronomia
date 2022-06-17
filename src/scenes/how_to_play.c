/*
** EPITECH PROJECT, 2020
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** how_to_play.c
*/

#include "my.h"

sfRectangleShape **set_button_htp(void)
{
    sfRectangleShape **rect = malloc(sizeof(sfRectangleShape *) * 2);
    sfVector2f pos_exit = {5, 560};
    sfVector2f size = {150, 150};
    rect[0] = init_button(pos_exit, size, CLOSE_HTP);
    return (rect);
}

int manage_htp_mouse_click(sfRenderWindow *window,
t_global *global, sfRectangleShape **button, sfMusic *music)
{
    sfVector2f position = {global->event.mouseButton.x,
    global->event.mouseButton.y};
    if (global->event.mouseButton.button == sfMouseLeft) {
        sfMusic_play(music);
        if (button_is_clicked(button[0], position))
            global->bools.exit = 1;
    }
    return (0);
}

int analyse_htp_events(sfRenderWindow* window, t_global *global,
sfRectangleShape **button, sfMusic *music)
{
    while (sfRenderWindow_pollEvent(window, &global->event)) {
        if (global->event.type == sfEvtMouseButtonPressed)
            manage_htp_mouse_click(window, global, button, music);
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (0);
}

void loop_htp_scene(sfRenderWindow *window, t_global *global)
{
    sfSprite *bg_s = declare_background_fight(HTP_SCENE);
    sfRectangleShape **button = set_button_htp();
    global->bools.exit = 0;
    sfMusic *music = sfMusic_createFromFile(BUTTON_CLICK);
    while (sfRenderWindow_isOpen(window) && global->bools.exit == 0) {
        sfRenderWindow_clear(window, sfBlack);
        analyse_htp_events(window, global, button, music);
        sfRenderWindow_drawSprite(window, bg_s,  NULL);
        sfRenderWindow_drawRectangleShape(window, button[0], NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
}