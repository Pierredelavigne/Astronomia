/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** map_sprites
*/

#include <stdlib.h>
#include "my.h"
#include "map.h"

sfSprite *create_texture_grass(t_global *global)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->top = 64;
    rect->left = 0;
    rect->height = 32;
    rect->width = 32;
    sfTexture *texture = sfTexture_createFromFile(path_main_texture, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

sfSprite *create_texture_water(t_global *global)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->top = 64;
    rect->left = 32;
    rect->height = 32;
    rect->width = 32;
    sfTexture *texture = sfTexture_createFromFile(path_main_texture, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

sfSprite *create_texture_dirt(t_global *global)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->top = 64;
    rect->left = 64;
    rect->height = 32;
    rect->width = 32;
    sfTexture *texture = sfTexture_createFromFile(path_main_texture, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

sfSprite *create_texture_wall(t_global *global)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->top = 64;
    rect->left = 96;
    rect->height = 32;
    rect->width = 32;
    sfTexture *texture = sfTexture_createFromFile(path_main_texture, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}