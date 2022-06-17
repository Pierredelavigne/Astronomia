/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** character
*/

#include "my.h"

const float hero_speed = 150.0;
const char *hero_path = "assets/character/hero.png";

void create_character_textures(t_global *global)
{
    global->textures.hero_texture = create_texture_from_path(hero_path);
}

sfSprite *get_standing_char(sfKeyCode code, sfSprite *sprite,
sfVector2f position)
{
    sfIntRect rect;

    rect.left = 32;
    rect.width = 32;
    rect.height = 32;
    rect.top = 0;
    if (code == sfKeyUp)
        rect.top = 96;
    if (code == sfKeyRight)
        rect.top = 64;
    if (code == sfKeyLeft)
        rect.top = 32;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}

void draw_standing_hero(sfRenderWindow *window, t_global *global,
sfKeyCode code)
{
    global->sprites.hero = get_standing_char(code,
    global->sprites.hero, global->pos.hero);
    sfRenderWindow_drawSprite(window, global->sprites.hero, NULL);
}

void move_hero(t_global *global)
{
    float to_move = sfTime_asSeconds(global->time_clock) * hero_speed;
    sfVector2f new_pos = {global->pos.hero.x, global->pos.hero.y};

    if (global->key_holding == sfKeyUp)
        new_pos.y -= to_move;
    if (global->key_holding == sfKeyDown)
        new_pos.y += to_move;
    if (global->key_holding == sfKeyRight)
        new_pos.x += to_move;
    if (global->key_holding == sfKeyLeft)
        new_pos.x -= to_move;
    if (hero_can_move(global, new_pos)) {
        global->pos.hero.x = new_pos.x;
        global->pos.hero.y = new_pos.y;
        move_it_all(global, to_move, global->key_holding);
    }
}

void draw_hero(t_global *global, sfRenderWindow *window)
{
    if (global->key_holding == 0)
        draw_standing_hero(window, global, global->character_facing);
    if (is_an_arrow_key(global->key_holding))
        draw_walking_hero(window, global, global->key_holding);
}