/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** add a string to another one
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(const char *str);

int my_strlen(const char *str);

char *my_strcat(char *str1, char const *str2)
{
    char *result;
    int i = 0;
    int j = 0;

    if (str1 == NULL && str2 == NULL)
        return (NULL);
    if (str1 == NULL)
        return (my_strdup(str2));
    if (str2 == NULL)
        return (my_strdup(str1));
    result = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    if (result == NULL)
        return (NULL);
    for (; str1[i] != '\0'; i++)
        result[i] = str1[i];
    for (; str2[j] != '\0'; j++, i++)
        result[i] = str2[j];
    result[i] = '\0';
    return (result);
}

char *my_strcat_free(char *str1, char const *str2)
{
    char *result;
    int i = 0;
    int j = 0;

    if (str1 == NULL)
        return (my_strdup(str2));
    result = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)));
    for (; str1[i] != '\0'; i++)
        result[i] = str1[i];
    for (; str2[j] != '\0'; j++, i++)
        result[i] = str2[j];
    result[i] = '\0';
    free(str1);
    return (result);
}