/*
** EPITECH PROJECT, 2020
** char_to_end_of_str.c
** File description:
** Add a char to the end of a string
*/
#include <stdlib.h>

char *my_strdup(char *str);

int my_strlen(char *str);

char *char_to_end_of_str(char *str, char c)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));
    int lenght = my_strlen(str);
    result = my_strdup(str);
    result[lenght] = c;
    result[lenght+1] = '\0';
    return (result);
}