/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** init
*/

#include "my.h"

const char *path_bg_end = "assets/end/6.png";
const char *end_cinematic_music_path = "assets/soundtrack/aeriths.ogg";
const char *text_end = "You have successfully left Astronomia !";
const sfVector2f spawn_trader_end = {1000, 500};
const sfVector2f spawn_hero_end = {0, 500};
const sfVector2f spawn_ship_end = {400, 80};
const sfVector2f scale_value = {4, 4};

sfSprite *get_ship(sfSprite *sprite,
sfVector2f position)
{
    sfIntRect rect;
    sfVector2f scale = {8, 8};

    rect.left = 0;
    rect.width = 64;
    rect.height = 64;
    rect.top = 0;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

void define_positions(t_global *global)
{
    global->pos.trader_end = spawn_trader_end;
    global->pos.hero_end = spawn_hero_end;
    global->pos.spaceship_end = spawn_ship_end;
    sfSprite_scale(global->sprites.end_cinematic_hero, scale_value);
    sfSprite_scale(global->sprites.end_cinematic_trader, scale_value);
}

void create_end_cinematic_sprites(t_global *global)
{
    sfVector2f planet_pos = {300, 0};
    sfVector2f planet_two_pos = {700, 100};

    global->sprites.end_cinematic_spaceship = sfSprite_create();
    sfSprite_setTexture(global->sprites.end_cinematic_spaceship,
    create_texture_from_path(spaceship_path), sfFalse);
    global->sprites.end_cinematic_trader = sfSprite_create();
    sfSprite_setTexture(global->sprites.end_cinematic_trader,
    create_texture_from_path(trader_path), sfFalse);
    global->sprites.end_cinematic_hero = sfSprite_create();
    sfSprite_setTexture(global->sprites.end_cinematic_hero,
    create_texture_from_path(hero_path), sfFalse);
    global->sprites.end_cinematic_spaceship =
    get_ship(global->sprites.end_cinematic_spaceship, spawn_ship_end);
    define_positions(global);
}

sfText *create_end_text(void)
{
    sfText *my_text = sfText_create();
    sfText_setFont(my_text, sfFont_createFromFile(path_font));
    sfText_setString(my_text, text_end);
    sfText_setCharacterSize(my_text, 55);
    sfVector2f my_vector = {
        width / 2 - (sfText_getGlobalBounds(my_text).width / 2)
        , height / 2 - (sfText_getGlobalBounds(my_text).height / 2)};
    sfText_setPosition(my_text, my_vector);
    return (my_text);
}

void set_end_cinematic(t_global *global)
{
    sfClock_restart(global->clock);
    global->bools.skip_cinematic = 0;
    global->clocks.hero = sfClock_create();
    global->texts.end = create_end_text();
    global->musics.end = sfMusic_createFromFile(end_cinematic_music_path);
    sfMusic_play(global->musics.end);
    global->fade_value = 0;
    create_end_cinematic_sprites(global);
    global->clocks.end_cinematic = sfClock_create();
}