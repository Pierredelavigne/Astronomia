/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** starting_game
*/

#include "my.h"

const char *spaceship_path = "assets/images/cinematic_spaceship.png";
const char *bg_path = "assets/images/space_intro_bg.png";
const char *planet_path = "assets/images/planets.png";
const char *enemy = "assets/images/enemy_ship.png";
const char *fire = "assets/images/fire.png";

void create_cinematic_sprites_two(t_global *global)
{
    sfVector2f enemy_pos = {1000, 0};

    global->sprites.cinematic_enemy = sfSprite_create();
    sfSprite_setTexture(global->sprites.cinematic_enemy,
    create_texture_from_path(enemy), sfFalse);
    global->sprites.cinematic_fire = sfSprite_create();
    sfSprite_setTexture(global->sprites.cinematic_fire,
    create_texture_from_path(fire), sfFalse);
}

void create_cinematic_sprites(t_global *global)
{
    sfVector2f planet_pos = {300, 0};
    sfVector2f planet_two_pos = {700, 100};

    global->sprites.cinematic_spaceship = sfSprite_create();
    sfSprite_setTexture(global->sprites.cinematic_spaceship,
    create_texture_from_path(spaceship_path), sfFalse);
    global->sprites.cinematic_bg = sfSprite_create();
    sfSprite_setTexture(global->sprites.cinematic_bg,
    create_texture_from_path(bg_path), sfFalse);
    global->sprites.cinematic_planet = sfSprite_create();
    sfSprite_setTexture(global->sprites.cinematic_planet,
    create_texture_from_path(planet_path), sfFalse);
    sfSprite_setPosition(global->sprites.cinematic_planet, planet_pos);
    global->sprites.cinematic_planet_two = sfSprite_create();
    sfSprite_setTexture(global->sprites.cinematic_planet_two,
    create_texture_from_path(planet_path), sfFalse);
    sfSprite_setPosition(global->sprites.cinematic_planet, planet_two_pos);
    create_cinematic_sprites_two(global);
}

void set_cinematic(t_global *global)
{
    sfClock_restart(global->clock);
    global->bools.skip_cinematic = 0;
    global->bools.fire_sound = 0;
    global->clocks.cinematic = sfClock_create();
    global->cinematic.scale = 4;
    global->cinematic.angle = 0;
    global->cinematic.enemy_x = 1300;
    global->cinematic.fire_animation = 0;
    create_cinematic_sprites(global);
    create_texts_cinematic(global);
    global->clocks.fire_cinematic = sfClock_create();
    create_and_start_cinematic_music(global);
}

void handle_loop_cinematic(sfRenderWindow *window, t_global *global)
{
    sfColor color_clear = sfColor_fromRGB(0, 0, 0);
    set_cinematic(global);
    while (sfRenderWindow_isOpen(window) && global->current_scene == 1)
    {
        global->time_clock = sfClock_getElapsedTime(global->clock);
        sfClock_restart(global->clock);
        sfRenderWindow_clear(window, color_clear);
        events_cinematic(window, global);
        draw_cinematic(window, global);
        sfRenderWindow_display(window);
    }
    free_cinematic(global);
}