/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** win for myrpg
*/

#include "my.h"

sfSprite *clock_win(sfClock **clock, sfSprite *sprite)
{
    sfVector2f scale = {2, 2};
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(*clock));
    if (seconds < 3)
        sfSprite_setScale(sprite, scale);
    else
        *clock = NULL;
    return (sprite);
}

void win_animation(sfRenderWindow *window, t_global *global)
{
    sfVector2f scale = {2, 2};
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(
        global->clocks.win));
    scale.x = seconds * 2;
    scale.y = seconds * 2;
    if (seconds < 6)
        sfSprite_setScale(global->sprites.fuel,  scale);
    update_inventory(window, global, 3);
}

void set_fuel_and_text(t_global *global)
{
    sfVector2f posx = {980, 500};
    sfVector2f hero = {600, 438};
    sfVector2f enemy = {100, 100};
    sfTexture *texture = sfTexture_createFromFile(
        "assets/images/fuel.png", NULL);
    sfVector2f pos = {20, 100};

    global->texts.damage = declare_damage_text(posx);
    global->texts.hero_lv = declare_damage_text(hero);
    global->texts.enemy_lv = declare_damage_text(enemy);
    global->sprites.fuel = sfSprite_create();
    sfSprite_setTexture(global->sprites.fuel, texture, sfTrue);
    sfSprite_setPosition(global->sprites.fuel, pos);
}

void check_victory(sfRenderWindow *window, t_global *global, sfMusic **music)
{
    if (global->en_stats.lp <= 0 && global->win == -1) {
            sfMusic_stop(music[0]);
            sfMusic_play(music[1]);
            sfMusic_setLoop(music[1], sfTrue);
            global->clocks.win = sfClock_create();
            global->win = 1;
    }
    if (global->stats.lp <= 0 && global->en_stats.lp > 0) {
            global->bools.exit = 1;
            sfMusic_stop(music[0]);
            global->current_scene = 6;
            game_over_scene(window, global);
        }
}