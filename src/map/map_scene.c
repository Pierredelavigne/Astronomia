/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** map_scene
*/

#include <stdio.h>
#include "my.h"

const float range = 32;

void event_scene_weapon(sfRenderWindow *window, t_global *global)
{
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeySpace
    && is_in_range(global->pos.hero, global->pos.saber, range) &&
    is_weapon_in_inventory(global, 1) == 0) {
        set_main_to_zero(global);
        update_inventory(window, global, 1);
        sfSprite_destroy(global->sprites.saber);
    }
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeySpace
    && is_in_range(global->pos.hero, global->pos.blade, range) &&
    is_weapon_in_inventory(global, 2) == 0) {
        set_main_to_zero(global);
        update_inventory(window, global, 2);
        sfSprite_destroy(global->sprites.blade);
    }
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyI)
        handle_loop_inventory(window, global);
}

void event_scene_two(sfRenderWindow *window, t_global *global)
{
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeySpace
    && is_in_range(global->pos.hero, global->pos.trader, range))
        interactions(global);
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeySpace
    && is_in_range(global->pos.hero, global->pos.thief, range))
        interaction_thief(window, global);
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyEscape)
        loop_pause_scene(window, global);
    event_scene_weapon(window, global);
}

void event_scene(sfRenderWindow *window, t_global *global)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtKeyPressed &&
        is_an_arrow_key(global->event.key.code)) {
            global->key_holding = global->event.key.code;
            global->character_facing = global->event.key.code;
        }
        if (global->event.type == sfEvtKeyReleased &&
        global->event.key.code == global->key_holding)
            global->key_holding = 0;
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        event_scene_two(window, global);
    }
}

void create_main_scene(t_global *global)
{
    init_variables(global);
    load_map(global);
    create_npc_trader(global);
    create_npc_thief(global);
    create_and_start_main_music(global);
    init_quest(global);
}

void handle_loop_main_scene(sfRenderWindow *window, t_global *global)
{
    sfColor color_clear = sfColor_fromRGB(150, 150, 150);
    create_main_scene(global);
    set_stat_player(global);
    inventory_create(global);
    while (sfRenderWindow_isOpen(window) && global->current_scene == 2)
    {
        sfRenderWindow_clear(window, sfBlack);
        global->time_clock = sfClock_getElapsedTime(global[0].clock);
        sfClock_restart(global->clock);
        sfRenderWindow_clear(window, color_clear);
        handle_moving_clock(global);
        draw_main_scene(window, global);
        sfRenderWindow_display(window);
        event_scene(window, global);
    }
    free_main_scene(global);
}