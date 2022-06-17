/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** unset_fight for myrpg
*/

#include "my.h"

const sfVector2f default_scale = {1, 1};

void unset_fight(t_global *global, t_battle *battle,
sfMusic **music, sfSprite *bg_s)
{
    sfMusic_destroy(music[0]);
    sfMusic_destroy(music[1]);
    sfSprite_setScale(global->sprites.hero, default_scale);
    sfSprite_setScale(global->sprites.thief, default_scale);
    sfSprite_destroy(battle->s_weapon);
    sfSprite_destroy(bg_s);
    if (global->clocks.win != NULL)
        sfClock_destroy(global->clocks.win);
    global[0].bools.exit = 0;
    global->win = -1;
}