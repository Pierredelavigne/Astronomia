/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** load_map
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "map.h"

const char *map_path = "./maps/main_planet.map";

FILE *test_stream(char const *path)
{
    FILE *stream = fopen(path, "r");
    if (stream == NULL) {
        my_putstr("Could not open map file");
    }
    return (stream);
}

int switch_obj_2(char *line, t_global *global, sfVector2f current_pos,
int *array)
{
    if (line[array[0]] == 'W') {
        global->blocks_map[array[1]].colisable = sfTrue;
        global->blocks_map[array[1]].pos = current_pos;
        global->blocks_map[array[1]].sprite =
        sfSprite_copy(global->map_sprites.water);
        sfSprite_setPosition(global->blocks_map[array[1]].sprite, current_pos);
        return (1);
    }
    if (line[array[0]] == 'w') {
        global->blocks_map[array[1]].colisable = sfTrue;
        global->blocks_map[array[1]].pos = current_pos;
        global->blocks_map[array[1]].sprite =
        sfSprite_copy(global->map_sprites.wall);
        sfSprite_setPosition(global->blocks_map[array[1]].sprite, current_pos);
        return (1);
    }
    return (0);
}

int switch_obj(char *line, t_global *global, sfVector2f current_pos, int *array)
{
    if (line[array[0]] == 'G') {
        global->blocks_map[array[1]].colisable = sfFalse;
        global->blocks_map[array[1]].pos = current_pos;
        global->blocks_map[array[1]].sprite =
        sfSprite_copy(global->map_sprites.grass);
        sfSprite_setPosition(global->blocks_map[array[1]].sprite, current_pos);
        return (array[1] + 1);
    }
    if (line[array[0]] == 'D') {
        global->blocks_map[array[1]].colisable = sfFalse;
        global->blocks_map[array[1]].pos = current_pos;
        global->blocks_map[array[1]].sprite =
        sfSprite_copy(global->map_sprites.dirt);
        sfSprite_setPosition(global->blocks_map[array[1]].sprite, current_pos);
        return (array[1] + 1);
    }
    if (switch_obj_2(line, global, current_pos, array))
        return (array[1] + 1);
    return (array[1] - 1);
}

int loop_in_obj(int line_nb, char *line, int block_count, t_global *global)
{
    int i;
    int *array = malloc(sizeof(int) * 2);
    sfVector2f current_pos;
    current_pos.y = (line_nb * 32);

    for (i = 0; line[i] != '\0'; i++, block_count++) {
            current_pos.x = i * 32;
            array[0] = i;
            array[1] = block_count;
            switch_obj(line, global, current_pos, array);
    }
    free(array);
    return (block_count);
}

void load_map(t_global *global)
{
    char *line = NULL;
    int block_count = 0;
    int line_nb = 1;
    FILE *stream = test_stream(map_path);
    size_t len = 0;
    size_t nread;
    stream = fopen(map_path, "r");
    create_base_textures(global);
    while ((nread = getline(&line, &len, stream)) != -1) {
        line = fix_line(line);
        if (line_nb == 1) {
            global->blocks_map =
            malloc(sizeof(t_map_block) * (my_getnbr(line) + 1 ) );
        }
        else
            block_count = loop_in_obj(line_nb - 2, line, block_count, global);
        line_nb++;
    }
    global->blocks_map[block_count].sprite = NULL;
}