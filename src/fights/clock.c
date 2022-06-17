/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** clock for myrpg
*/

#include "my.h"

void clock_manage(sfRenderWindow *window, t_global *global, t_battle *battle)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(
        global->clocks.enemy));
    if (seconds >= 0.5 && battle->attacked == 1 && global->win != 1)
        attack_enemy(window, global, battle);
    if (battle->attacked == 0)
        sfClock_restart(global->clocks.enemy);
}