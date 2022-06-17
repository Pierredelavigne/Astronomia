/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** event_fight for myrpg
*/

#include "my.h"

void choose_weapon(sfRenderWindow *window, t_global *global, t_battle *battle)
{
    sfSprite *bg = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(
        "assets/images/inventory_fight.png", NULL);
    sfVector2f pos = {297, 363};
    int res = 0;

    sfSprite_setTexture(bg, texture, sfTrue);
    sfSprite_setPosition(bg, pos);
    sfRenderWindow_drawSprite(window, bg, NULL);
    res = draw_fight_inventory(window, global);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1 || res == 1)
        battle->choose = 0;
    return;
}

void analyse_fight_mouse_event(sfRenderWindow *window,
t_global *global, t_battle *battle)
{
    sfVector2f position = {global->event.mouseButton.x,
    global->event.mouseButton.y};
    if (button_is_clicked(battle->attack, position) == 1 &&
    battle->attacked == 0) {
            particle_animation(window, 1080, 250);
            global->en_stats.lp -= global->stats.strength +
            get_weapon_damage(global);
            battle->attacked = 1;
    }
    if (button_is_clicked(battle->weapon, position) == 1) {
        battle->choose = 1;
    }
}

void attack_enemy(sfRenderWindow *window, t_global *global, t_battle *battle)
{
    particle_animation(window, 200, 650);
    global->stats.lp -= global->en_stats.strength;
    battle->attacked = 0;
    return;
}