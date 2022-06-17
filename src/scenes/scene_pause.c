/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** scene_pause for myrpg
*/

#include "my.h"

sfRectangleShape **set_button_pause(void)
{
    sfRectangleShape **rect = malloc(sizeof(sfRectangleShape *) * 4);
    sfVector2f pos_resume = {530, 260};
    sfVector2f pos_home = {-8, -8};
    sfVector2f pos_exit = {1075, 12};
    sfVector2f size = {200, 200};
    rect[0] = init_button(pos_resume, size, RESUME);
    rect[1] = init_button(pos_home, size, HOMEPAGE);
    rect[2] = init_button(pos_exit, size, EXIT);
    return (rect);
}

int manage_pause_mouse_click(sfRenderWindow *window,
t_global *global, sfRectangleShape **button, sfMusic *music)
{
    sfVector2f position = {global->event.mouseButton.x,
    global->event.mouseButton.y};
    if (global->event.mouseButton.button == sfMouseLeft) {
        sfMusic_play(music);
        if (button_is_clicked(button[0], position)) {
            global->current_scene = 2;
        }
        if (button_is_clicked(button[1], position)){
            global->current_scene = 0;
        }
        if (button_is_clicked(button[2], position))
            sfRenderWindow_close(window);
    }
    return (0);
}

int analyse_pause_events(sfRenderWindow* window, t_global *global,
sfRectangleShape **button, sfMusic *music)
{
    while (sfRenderWindow_pollEvent(window, &global->event)) {
        if (global->event.type == sfEvtMouseButtonPressed)
            manage_pause_mouse_click(window, global, button, music);
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (global->event.type == sfEvtKeyPressed &&
            global->event.key.code == sfKeyEscape){
                global->bools.exit = 1;
                global->current_scene = 2;
        }
    }
    return (0);
}

void loop_pause_scene(sfRenderWindow *window, t_global *global)
{
    sfSprite *bg_s = declare_background_fight(PAUSE_BACKGROUND);
    sfRectangleShape **button = set_button_pause();
    global->bools.exit = 0;
    global->current_scene = 4;
    sfMusic *music = sfMusic_createFromFile(BUTTON_CLICK);
    while (sfRenderWindow_isOpen(window) && global->current_scene == 4) {
        sfRenderWindow_clear(window, sfBlack);
        analyse_pause_events(window, global, button, music);
        sfRenderWindow_drawSprite(window, bg_s,  NULL);
        sfRenderWindow_drawRectangleShape(window, button[0], NULL);
        sfRenderWindow_drawRectangleShape(window, button[1], NULL);
        sfRenderWindow_drawRectangleShape(window, button[2], NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfClock_restart(global->clock);
}