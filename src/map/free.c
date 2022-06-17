/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** free
*/

#include "my.h"

void free_main_scene(t_global *global)
{
    sfClock_destroy(global->clocks.hero);
    stop_and_destroy_main_music(global);
    for (int i = 0; global->blocks_map[i].sprite != NULL; i++)
        sfSprite_destroy(global->blocks_map[i].sprite);
    free(global->blocks_map);
}