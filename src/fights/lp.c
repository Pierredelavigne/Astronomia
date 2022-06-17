/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** lp for the myrpg
*/

#include "my.h"

int get_lp_ratio(float lp, float max)
{
    float res = (lp / max) * 300;
    return (res);
}

void lp_for_enemy(t_global *global)
{
    global->lp_enemy.full = define_particle();
    global->lp_enemy.lp = define_particle();
    sfVector2f size = {300, 15};
    sfVector2f lp_size = {get_lp_ratio(global->en_stats.lp,
    global->en_stats.lp_max), 15};
    sfVector2f pos = {100, 175};

    if (global->en_stats.lp <= 0)
        lp_size.x = 0;
    sfRectangleShape_setSize(global->lp_enemy.full, size);
    sfRectangleShape_setSize(global->lp_enemy.lp, lp_size);
    sfRectangleShape_setPosition(global->lp_enemy.lp, pos);
    sfRectangleShape_setPosition(global->lp_enemy.full, pos);
    sfRectangleShape_setFillColor(global->lp_enemy.lp, sfGreen);
}

void lp_for_hero(t_global *global)
{
    global->lp_hero.full = define_particle();
    global->lp_hero.lp = define_particle();
    sfVector2f size = {300, 15};
    sfVector2f lp_size = {get_lp_ratio(global->stats.lp,
    global->stats.lp_max), 15};
    sfVector2f pos = {600, 520};

    if (global->stats.lp <= 0)
        lp_size.x = 0;
    sfRectangleShape_setSize(global->lp_hero.full, size);
    sfRectangleShape_setSize(global->lp_hero.lp, lp_size);
    sfRectangleShape_setPosition(global->lp_hero.lp, pos);
    sfRectangleShape_setPosition(global->lp_hero.full, pos);
    sfRectangleShape_setFillColor(global->lp_hero.lp, sfGreen);
}

void declare_lp_fight( t_global *global)
{
    lp_for_hero(global);
    lp_for_enemy(global);
}

void draw_people_fight(sfRenderWindow *window, t_global *global)
{
    sfVector2f lp_size = {get_lp_ratio(global->stats.lp,
    global->stats.lp_max), 15};
    sfVector2f lp_sizes = {get_lp_ratio(global->en_stats.lp,
    global->en_stats.lp_max), 15};

    if (global->en_stats.lp <= 0)
        lp_sizes.x = 0;
    if (global->stats.lp <= 0)
        lp_size.x = 0;
    sfRectangleShape_setSize(global->lp_hero.lp, lp_size);
    sfRectangleShape_setSize(global->lp_enemy.lp, lp_sizes);
    sfRenderWindow_drawRectangleShape(window, global->lp_hero.full, NULL);
    sfRenderWindow_drawRectangleShape(window,  global->lp_hero.lp, NULL);
    sfRenderWindow_drawRectangleShape(window, global->lp_enemy.full, NULL);
    sfRenderWindow_drawRectangleShape(window, global->lp_enemy.lp, NULL);
}