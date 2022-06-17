/*
** EPITECH PROJECT, 2020
** str_append.c
** File description:
** Append two strings together
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *str_append(char const *original, char const *to_append)
{
    char *result = malloc(sizeof(char) *
    (my_strlen(original) + my_strlen(to_append) + 1));
    int count = 0;
    int cout = 0;
    for (; original[count] != '\0'; count++)
        result[count] = original[count];
    for (; to_append[cout] != '\0'; count++, cout++)
        result[count] = to_append[cout];
    result[count] = '\0';
    return (result);
}