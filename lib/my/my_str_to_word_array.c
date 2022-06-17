/*
** EPITECH PROJECT, 2020
**  my_str_to_word_array
** File description:
** Split a string into words
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int is_alphanumeric(char mychar)
{
    for (int i = 65; i < 91; i++) {
        if (mychar == i)
            return (1);
    }
    for (int i = 97; i < 123; i++) {
        if (mychar == i)
            return (1);
    }
    for (int i = 48; i < 58; i++) {
        if (mychar == i)
            return (1);
    }
    return (0);
}

int count_double_array_size(char const *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (is_alphanumeric(str[i]) == 0)
            count++;
        i++;
    }
    count++;
    return (count);
}

char **create_double_array(char **new_str, char const *str)
{
    int j = 0;
    int i = 0;

    for (int s_c = 0, lwn_alpha = 0; str[s_c] != '\0'; s_c++)
    {
        if (is_alphanumeric(str[s_c]) == 0 && lwn_alpha == 0) {
            new_str[i][j] = '\0';
            lwn_alpha = 1;
            i++;
            j = 0;
        }
        else  {
            new_str[i][j] = str[s_c];
            j = j + 1 - lwn_alpha;
            lwn_alpha = 0;
        }
    }
    new_str[i][j] = '\0';
    new_str[i+1] = '\0';
    return (new_str);
}

char **my_str_to_word_array(char  const *str)
{
    int lenght = (count_double_array_size(str) + 1);
    char **new_str;

    new_str = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; i <= count_double_array_size(str) + 1; i++)
    {
        new_str[i] = malloc(sizeof(char) * my_strlen(str));
    }
    return (create_double_array(new_str, str));
}
