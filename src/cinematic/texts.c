/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** texts
*/

#include "my.h"

const char *font_it = "assets/font/squadron_k4dd.ttf";
const char *up = "You have landed into an unknown planet.";
const char *middle = "You must find a way to leave the planet. \
Good Luck!";
const char *down = "Press any key to continue...";

sfText *create_end_cinematic_text(t_global *global)
{
    sfText *my_text = sfText_create();
    sfText_setFont(my_text, sfFont_createFromFile(path_font));
    sfText_setString(my_text, up);
    sfText_setCharacterSize(my_text, 45);
    sfText_setOutlineColor(my_text, sfColor_fromRGB(255, 255, 0));
    sfText_setOutlineThickness(my_text, 4.0);
    sfText_setFillColor(my_text, sfColor_fromRGB(0, 0, 0));
    sfVector2f my_vector = {
        width / 2 - (sfText_getGlobalBounds(my_text).width / 2)
        , 120};
    sfText_setPosition(my_text, my_vector);
    return (my_text);
}

sfText *create_text_middle(t_global *global)
{
    sfText *my_text = sfText_create();
    sfText_setFont(my_text, sfFont_createFromFile(font_it));
    sfText_setString(my_text, middle);
    sfText_setCharacterSize(my_text, 35);
    sfText_setOutlineColor(my_text, sfColor_fromRGB(255, 255, 0));
    sfText_setOutlineThickness(my_text, 3.0);
    sfText_setFillColor(my_text, sfColor_fromRGB(0, 0, 0));
    sfVector2f my_vector = {
        width / 2 - (sfText_getGlobalBounds(my_text).width / 2)
        , 250};
    sfText_setPosition(my_text, my_vector);
    return (my_text);
}

sfText *create_text_down(t_global *global)
{
    sfText *my_text = sfText_create();
    sfText_setFont(my_text, sfFont_createFromFile(font_it));
    sfText_setString(my_text, down);
    sfText_setCharacterSize(my_text, 40);
    sfText_setOutlineColor(my_text, sfColor_fromRGB(255, 255, 255));
    sfText_setOutlineThickness(my_text, 3.0);
    sfText_setFillColor(my_text, sfColor_fromRGB(0, 0, 0));
    sfVector2f my_vector = {
        width / 2 - (sfText_getGlobalBounds(my_text).width / 2)
        , 500};
    sfText_setPosition(my_text, my_vector);
    return (my_text);
}

void create_texts_cinematic(t_global *global)
{
    global->texts.text_cinematic_up = create_end_cinematic_text(global);
    global->texts.text_cinematic_middle = create_text_middle(global);
    global->texts.text_cinematic_down = create_text_down(global);
}

void draw_texts_cinematic(sfRenderWindow *window, t_global *global)
{
    sfRenderWindow_drawText(window, global->texts.text_cinematic_up, NULL);
    sfRenderWindow_drawText(window, global->texts.text_cinematic_middle, NULL);
    sfRenderWindow_drawText(window, global->texts.text_cinematic_down, NULL);
}