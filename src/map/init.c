/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** init
*/

#include "my.h"

const sfVector2f spawn_point = {64, 64};
const char *saber = "assets/images/saber.png";
const char *blade = "assets/images/blade.png";

void init_variables(t_global *global)
{
    global->sprites.hero = sfSprite_create();
    sfSprite_setTexture(global->sprites.hero,
    global->textures.hero_texture, sfFalse);
    global->pos.hero.x = spawn_point.x;
    global->pos.hero.y = spawn_point.y;
    global->sprites.hero = get_standing_char(sfKeyDown,
    global->sprites.hero, global->pos.hero);
    global->bools.default_scene = 0;
    global->key_holding = 0;
    global->character_facing = sfKeyDown;
    global->bools.in_trader_conv = 0;
    global->bools.in_thief_conv = 0;
    global->clocks.hero = sfClock_create();
    global->sprites.saber = set_weapon(saber, 600, 30, &global->pos.saber);
    global->sprites.blade = set_weapon(blade, 50, 400, &global->pos.blade);
    global->text_to_draw = NULL;
}