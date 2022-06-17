/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** scene_menu for myrpg
*/

#include "my.h"

sfRectangleShape **set_button_menu(void)
{
    sfRectangleShape **rect = malloc(sizeof(sfRectangleShape *) * 4);
    sfVector2f pos_quit = {5, 550};
    sfVector2f pos_play = {800, 180};
    sfVector2f pos_htp = {5, 10};
    sfVector2f size_quit = {300, 150};
    sfVector2f size_play = {375, 375};
    sfVector2f size_htp = {150, 150};
    rect[0] = init_button(pos_play, size_play, START);
    rect[1] = init_button(pos_quit, size_quit, QUIT);
    rect[2] = init_button(pos_htp, size_htp, HTP);
    return (rect);
}

int manage_menu_mouse_click(sfRenderWindow *window,
t_global *global, sfRectangleShape **button, sfMusic *music)
{
    sfVector2f position = {global->event.mouseButton.x,
    global->event.mouseButton.y};
    if (global->event.mouseButton.button == sfMouseLeft) {
        if (button_is_clicked(button[0], position))
            global->current_scene = 1;
        if (button_is_clicked(button[2], position))
            loop_htp_scene(window, global);
        if (button_is_clicked(button[1], position))
            sfRenderWindow_close(window);
    }
    return (0);
}

int analyse_menu_events(sfRenderWindow* window, t_global *global,
sfRectangleShape **button, sfMusic *music)
{
    while (sfRenderWindow_pollEvent(window, &global->event)) {
        if (global->event.type == sfEvtMouseButtonPressed)
            manage_menu_mouse_click(window, global, button, music);
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (0);
}

sfText *set_astronomia(void)
{
    sfText *astronomia = declare_text();
    sfVector2f pos = {290, 7};

    sfText_setPosition(astronomia, pos);
    sfText_setCharacterSize(astronomia, 120);
    sfText_setString(astronomia, "Astronomia");
    sfText_setColor(astronomia, sfWhite);
    return (astronomia);
}

void loop_menu_scene(sfRenderWindow *window, t_global *global)
{
    sfSprite *bg_s = declare_background_fight(HOME_BACKGROUND);
    sfRectangleShape **button = set_button_menu();
    sfMusic *music = sfMusic_createFromFile(BUTTON_CLICK);
    sfMusic *theme = sfMusic_createFromFile(MAIN_SOUNDTRACK);
    sfText *astronomia = set_astronomia();
    sfMusic_play(theme);
    sfMusic_setLoop(theme, sfTrue);
    while (sfRenderWindow_isOpen(window) && global->current_scene == 0) {
        sfRenderWindow_clear(window, sfBlack);
        analyse_menu_events(window, global, button, music);
        sfRenderWindow_drawSprite(window, bg_s,  NULL);
        sfRenderWindow_drawRectangleShape(window, button[0], NULL);
        sfRenderWindow_drawText(window, astronomia, NULL);
        sfRenderWindow_drawRectangleShape(window, button[1], NULL);
        sfRenderWindow_drawRectangleShape(window, button[2], NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfMusic_destroy(theme);
}