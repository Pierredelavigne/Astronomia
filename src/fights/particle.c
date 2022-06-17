/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** particle animation
*/

#include "my.h"
#include "fight.h"

sfRectangleShape *define_particle(void)
{
    sfRectangleShape *particle = sfRectangleShape_create();
    sfVector2f pos = {200, 101};
    sfVector2f size = {5, 5};
    sfColor color = sfRed;

    sfRectangleShape_setPosition(particle, pos);
    sfRectangleShape_setSize(particle, size);
    sfRectangleShape_setFillColor(particle, color);
    sfRectangleShape_setOutlineColor(particle, sfBlue);
    return (particle);
}

sfRectangleShape **set_particle(sfRenderWindow *window)
{
    sfRectangleShape *particle = define_particle();
    sfRectangleShape **part = malloc(sizeof(particle) * 8);

    if (part == NULL)
        sfRenderWindow_close(window);
    part[0] = sfRectangleShape_copy(particle);
    part[1] = sfRectangleShape_copy(particle);
    part[2] = sfRectangleShape_copy(particle);
    part[3] = sfRectangleShape_copy(particle);
    part[4] = sfRectangleShape_copy(particle);
    part[5] = sfRectangleShape_copy(particle);
    part[6] = sfRectangleShape_copy(particle);
    part[7] = sfRectangleShape_copy(particle);
    return (part);
}

sfVector2f set_pos_part(sfVector2f pos, int j)
{
    int h = 6;
    if (j == 0 || j == 1  || j == 7)
        pos.x = pos.x + 1*h;
    if (j == 4 || j == 3 || j == 5)
        pos.x = pos.x - 1*h;
    if (j == 1 || j == 3 || j == 2)
        pos.y = pos.y + 1*h;
    if (j == 5 || j == 6 || j == 7)
        pos.y = pos.y - 1*h;
    return (pos);
}

sfVector2f *create_pos(int x, int y, sfRenderWindow *window)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f)* 8);

    if (pos == NULL)
        sfRenderWindow_close(window);
    for (int i = 0; i < 8; i++) {
        pos[i].x = x;
        pos[i].y = y;
    }
    return (pos);
}

sfRectangleShape **particle_animation(sfRenderWindow *window, int x, int y)
{
    sfSprite *sprites = sfSprite_create();
    sfClock *clock = sfClock_create();
    sfRectangleShape **particle = set_particle(window);
    sfVector2f *pos = create_pos(x, y, window);
    sfVector2f scale = {1.1, 1.1};

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 8; j++) {
            pos[j] = set_pos_part(pos[j], j);
            sfRectangleShape_setPosition(particle[j], pos[j]);
            sfRectangleShape_scale(particle[j], scale);
            sfRenderWindow_drawRectangleShape(window, particle[j], NULL);
        }
        sfRenderWindow_display(window);
    }
    return (particle);
}