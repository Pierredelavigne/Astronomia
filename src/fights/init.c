/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** init
*/

#include "my.h"

void init_fight(t_global *global)
{
    global[0].bools.exit = 0;
    global->win = -1;
    global->clocks.enemy = sfClock_create();
    set_people(global);
    set_fuel_and_text(global);
    global->clocks.win = 0;
}