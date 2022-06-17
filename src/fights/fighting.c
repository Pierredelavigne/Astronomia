/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** fighting
*/

#include "my.h"
#include <string.h>
#include <stdio.h>

void events_fight(sfRenderWindow *window, t_global *global,
t_battle *battle, sfMusic **music)
{
    while (sfRenderWindow_pollEvent(window, &global->event))
    {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (global->event.type == sfEvtMouseButtonPressed &&
        global->win == -1)
            analyse_fight_mouse_event(window, global, battle);
        if (global->win == 1 && global->event.type == sfEvtKeyPressed) {
            global->current_scene = 7;
            sfMusic_stop(music[1]);
            handle_loop_end_cinematic(window, global);
            global[0].bools.exit = 1;
        }
    }
}

void draw_element(sfRenderWindow *window, t_global *global, sfSprite *bg_s,
sfSprite *weapon)
{
    sfRenderWindow_drawSprite(window, bg_s, NULL);
    sfRenderWindow_drawSprite(window, weapon, NULL);
    sfRenderWindow_drawSprite(window, global->sprites.hero, NULL);
    sfRenderWindow_drawSprite(window, global->sprites.thief, NULL);
}

void display_element(sfRenderWindow *window, t_global *global,
t_battle *battle, sfSprite *bg_s)
{
    int damage = get_weapon_damage(global);

    draw_element(window, global, bg_s, battle->s_weapon);
    draw_text_fight(window, global);
    draw_people_fight(window, global);
    draw_button(window, global, battle);
    if (battle->choose == 1)
        choose_weapon(window, global, battle);
    if (global->win == 1)
        win_animation(window, global);
    sfRenderWindow_drawSprite(window, global->sprites.fuel, NULL);
    sfRenderWindow_display(window);
    return;
}

sfMusic **set_music(void)
{
    sfMusic **music = malloc(sizeof(sfMusic *) * 2);
    music[0] = sfMusic_createFromFile("assets/soundtrack/the-arival.ogg");
    music[1] = sfMusic_createFromFile("assets/sounds/win.ogg");
    sfMusic_setVolume(music[0], 40);
    sfMusic_play(music[0]);
    return (music);
}

void loop_fight(sfRenderWindow *window, t_global *global)
{
    t_battle *battle = malloc(sizeof(t_battle));
    set_button(battle);
    sfMusic **music = set_music();
    sfSprite *bg_s = declare_background_fight("assets/images/battlegrass.png");
    init_fight(global);

    while (sfRenderWindow_isOpen(window) && !global[0].bools.exit)
    {
        battle->s_weapon = get_weapon_main_sprite(global);
        clock_manage(window, global, battle);
        display_element(window, global, battle, bg_s);
        events_fight(window, global, battle, music);
        check_victory(window, global, music);
    }
    unset_fight(global, battle, music, bg_s);
    return ;
}