/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "my.h"

extern const char *path_main_texture;

sfSprite *create_texture_grass(t_global *global);

sfSprite *create_texture_water(t_global *global);

sfSprite *create_texture_dirt(t_global *global);

sfSprite *create_texture_wall(t_global *global);

void create_base_textures(t_global *global);

char *fix_line(char *map_str);

FILE *test_stream(char const *path);

#endif /* !MAP_H_ */
