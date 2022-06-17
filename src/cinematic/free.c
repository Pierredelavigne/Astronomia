/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** free
*/

#include "my.h"

void free_cinematic(t_global *global)
{
    sfText_destroy(global->texts.text_cinematic_up);
    sfText_destroy(global->texts.text_cinematic_middle);
    sfText_destroy(global->texts.text_cinematic_down);
    sfSprite_destroy(global->sprites.cinematic_spaceship);
    sfSprite_destroy(global->sprites.cinematic_bg);
    sfSprite_destroy(global->sprites.cinematic_planet);
    sfSprite_destroy(global->sprites.cinematic_planet_two);
    sfSprite_destroy(global->sprites.cinematic_enemy);
    sfSprite_destroy(global->sprites.cinematic_fire);
    stop_and_destroy_cinematic_music(global);
}