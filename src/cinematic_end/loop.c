/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** loop
*/

#include "my.h"

void events_end_cinematic(sfRenderWindow *window, t_global *global)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (global->event.type == sfEvtKeyPressed)
            global->current_scene = 0;
    }
}

sfVector2f move_entity_end(t_global *global,
sfVector2f current_pos, sfKeyCode key)
{
    float to_move = sfTime_asSeconds(global->time_clock) * hero_speed;
    sfVector2f new_pos = {current_pos.x, current_pos.y};

    if (key == sfKeyUp)
        new_pos.y -= to_move;
    if (key == sfKeyDown)
        new_pos.y += to_move;
    if (key == sfKeyRight)
        new_pos.x += to_move;
    if (key == sfKeyLeft)
        new_pos.x -= to_move;
    return (new_pos);
}

void free_end(t_global *global)
{
    sfMusic_stop(global->musics.end);
    sfMusic_destroy(global->musics.end);
    sfClock_destroy(global->clocks.end_cinematic);
    sfClock_destroy(global->clocks.hero);
    sfSprite_destroy(global->sprites.end_cinematic_hero);
    sfSprite_destroy(global->sprites.end_cinematic_trader);
    sfSprite_destroy(global->sprites.end_cinematic_spaceship);
}

void handle_loop_end_cinematic(sfRenderWindow *window, t_global *global)
{
    sfColor color_clear = sfColor_fromRGB(0, 0, 0);
    set_end_cinematic(global);
    while (sfRenderWindow_isOpen(window) && global->current_scene == 7)
    {
        global->time_clock = sfClock_getElapsedTime(global->clock);
        sfClock_restart(global->clock);
        handle_moving_clock(global);
        sfRenderWindow_clear(window, color_clear);
        events_end_cinematic(window, global);
        draw_end_cinematic(window, global);
        sfRenderWindow_display(window);
    }
    free_end(global);
}