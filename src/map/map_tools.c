/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** map_tools
*/

#include <stdlib.h>
#include "my.h"
#include "map.h"

const char *path_main_texture = "assets/images/map_spritesheet.png";

sfTexture *create_texture_from_path(const char *line)
{
    sfTexture *texture = sfTexture_createFromFile(line, NULL);
    char *error_message;

    if (texture == NULL) {
        error_message = str_append("Failed to create texture from path: ",
        line);
        my_putstr_error(error_message);
        free(error_message);
    }
    return (texture);
}

void create_base_textures(t_global *global)
{
    global->map_textures.main_texture =
    create_texture_from_path(path_main_texture);
    global->map_sprites.grass = create_texture_grass(global);
    global->map_sprites.water = create_texture_water(global);
    global->map_sprites.dirt = create_texture_dirt(global);
    global->map_sprites.wall = create_texture_wall(global);
}

char *fix_line(char *map_str)
{
    if (map_str[my_strlen(map_str) - 1] == '\n')
        map_str[my_strlen(map_str) - 1] = '\0';
    return (map_str);
}