/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-clement.chausson
** File description:
** str_match
*/

#include <stdlib.h>

int my_strlen(const char *str);

int str_compare(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}