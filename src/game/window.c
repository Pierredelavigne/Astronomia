/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-clement.chausson
** File description:
** window
*/

#include "../include/my.h"

const int width = 1280;
const int height = 720;
const int fps = 60;
const char *program_name = "Astronomia";

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, program_name, sfClose, NULL);

    if (!window) {
        my_putstr_error("Cannot create window!");
        return (NULL);
    }
    sfRenderWindow_setFramerateLimit(window, fps);
    return (window);
}