/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban-clement.chausson
** File description:
** print_double_array
*/
#include <unistd.h>

void my_putstr(char *str);

void my_putchar(char c);

char *str_append(char const *original, char const *to_append);

char *print_double_array(char **arg)
{
    char *result = "";
    for (int i = 0; arg[i] != NULL; i++)
    {
        result = str_append(str_append(result, arg[i]), "\n");
    }
    return (result);
}