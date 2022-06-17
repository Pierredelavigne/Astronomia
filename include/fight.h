/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** fight
*/

#include "my.h"

#ifndef FIGHT_H_
#define FIGHT_H_

typedef struct skill
{
    char *name;
    int damage;
} t_skill;

typedef struct fighter
{
    int health;
    int health_max;
    sfSprite *sprite;
} t_fighter;

typedef struct battle
{
    t_fighter hero;
    t_fighter *enemies;
    sfRectangleShape *attack;
    sfRectangleShape *weapon;
    sfSprite *s_weapon;
    int choose;
    int attacked;
} t_battle;

sfRectangleShape **particle_animation(sfRenderWindow *window, int x, int y);

sfRectangleShape *define_particle(void);

int button_is_clicked(sfRectangleShape *button, sfVector2f click_position);

sfRectangleShape *init_button(sfVector2f position, sfVector2f size,
                char *filename);

sfText *declare_damage_text(sfVector2f pos);

sfSprite *declare_background_fight(char *filename);

#endif /* !FIGHT_H_ */
