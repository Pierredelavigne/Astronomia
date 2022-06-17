/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** lose for myrpg
*/

#include "my.h"

void analyse_lose_mouse_event(sfRenderWindow *window, t_global *global,
sfRectangleShape *restart, sfRectangleShape *main)
{
    sfVector2f position = {global->event.mouseButton.x,
    global->event.mouseButton.y};
    if (button_is_clicked(restart, position) == 1)
        global->current_scene = 1;
    if (button_is_clicked(main, position) == 1)
        global->current_scene = 0;
}

void events_lose(sfRenderWindow *window, t_global *global,
sfRectangleShape *restart, sfRectangleShape *main)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (global->event.type == sfEvtMouseButtonPressed)
            analyse_lose_mouse_event(window, global, restart, main);
    }
}

sfRectangleShape **set_button_lose(void)
{
    sfRectangleShape **rect = malloc(sizeof(sfRectangleShape *) * 3);
    sfVector2f rest = {300, 450};
    sfVector2f main = {850, 450};
    sfVector2f size = {150, 150};
    rect[0] = init_button(rest, size, "assets/scenes/pause/play.png");
    rect[1] = init_button(main, size, "assets/scenes/pause/home.png");
    return (rect);
}

sfText *set_lose_text(void)
{
    sfText *lose = declare_text();
    sfVector2f pos = {200, 40};

    sfText_setPosition(lose, pos);
    sfText_setString(lose, "GAME OVER");
    sfText_setColor(lose, sfWhite);
    sfText_setCharacterSize(lose, 150);
    return (lose);
}

void game_over_scene(sfRenderWindow *window, t_global *global)
{
    sfText *lose = set_lose_text();
    sfMusic *music = sfMusic_createFromFile("assets/soundtrack/game_over.ogg");
    sfRectangleShape **button = set_button_lose();
    sfRectangleShape **snow = declare_snow_particle(global);
    sfClock *lose_cl = sfClock_create();
    float seconds = 0;

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    while (sfRenderWindow_isOpen(window) && global->current_scene == 6) {
        sfRenderWindow_clear(window, sfBlack);
        events_lose(window, global, button[0], button[1]);
        draw_snow(window, global, snow, lose_cl);
        sfRenderWindow_drawRectangleShape(window, button[0], NULL);
        sfRenderWindow_drawRectangleShape(window, button[1], NULL);
        sfRenderWindow_drawText(window, lose, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
}