/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** music
*/

#include "my.h"

const char *cinematic_music_path = "assets/soundtrack/surviving_mars_02.ogg";
const char *cinematic_enemy_fire = "assets/sounds/shoot.wav";

void stop_and_destroy_cinematic_music(t_global *global)
{
    sfMusic_stop(global->musics.cinematic);
    sfMusic_destroy(global->musics.cinematic);
    sfSound_destroy(global->sounds.cinmatic_enemy_fire);
}

void create_and_start_cinematic_music(t_global *global)
{
    sfSoundBuffer *buffer;
    global->musics.cinematic = sfMusic_createFromFile(cinematic_music_path);
    sfMusic_play(global->musics.cinematic);
    sfMusic_setLoop(global->musics.cinematic, sfTrue);
    global->sounds.cinmatic_enemy_fire = sfSound_create();
    buffer = sfSoundBuffer_createFromFile(cinematic_enemy_fire);
    sfSound_setBuffer(global->sounds.cinmatic_enemy_fire, buffer);
}