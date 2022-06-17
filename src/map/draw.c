/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** draw
*/

#include "my.h"

void draw_map(t_global *global, sfRenderWindow *window)
{
    int i = 0;
    for (; global->blocks_map[i].sprite != NULL; i++) {
        sfSprite_setPosition(global->blocks_map[i].sprite,
        global->blocks_map[i].pos);
        sfRenderWindow_drawSprite(window, global->blocks_map[i].sprite, NULL);
    }
    if (is_weapon_in_inventory(global, 1) == 0) {
        sfSprite_setPosition(global->sprites.saber, global->pos.saber);
        sfRenderWindow_drawSprite(window, global->sprites.saber, NULL);
    }
    if (is_weapon_in_inventory(global, 2) == 0) {
        sfSprite_setPosition(global->sprites.blade, global->pos.blade);
        sfRenderWindow_drawSprite(window, global->sprites.blade, NULL);
    }
}

void draw_main_scene(sfRenderWindow *window, t_global *global)
{
    move_hero(global);
    draw_map(global, window);
    draw_npc(window, global);
    draw_hero(global, window);
    if (global->text_to_draw != NULL)
        sfRenderWindow_drawText(window, global->text_to_draw, NULL);
    display_stats(window, global);
    display_quest(window, global);
}