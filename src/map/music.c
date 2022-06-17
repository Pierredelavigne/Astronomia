/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** music
*/

#include "my.h"

const char *main_music_path = "assets/soundtrack/red_carpet_wooden_floor.ogg";

void stop_and_destroy_main_music(t_global *global)
{
    sfMusic_stop(global->musics.main_menu_red_carpet);
    sfMusic_destroy(global->musics.main_menu_red_carpet);
}

void create_and_start_main_music(t_global *global)
{
    global->musics.main_menu_red_carpet
    = sfMusic_createFromFile(main_music_path);
    sfMusic_play(global->musics.main_menu_red_carpet);
    sfMusic_setLoop(global->musics.main_menu_red_carpet, sfTrue);
}