/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get nbr
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

char *my_strdup(char const *str);

char *remove_nan(char const *str)
{
    char *new_str = malloc(sizeof(char *) * my_strlen(str));
    int i = 0;
    int j = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] <= '9' && str[i] >= '0') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}

int my_getnbr(char const *str_og)
{
    char *str = remove_nan(str_og);
    int nb = 0;
    int neg = 1;
    int i = 0;
    int length;
    int j;

    while (str[i] == '-')
        i++;
    j = i;
    if (i % 2 == 1)
        neg = (-1);
    length = my_strlen(str) - 1 - i;
    for (; str[i] != '\0'; i++)
        nb += (str[i] - 48) * my_compute_power_rec(10, (length - (i-j)));
    nb = nb * neg;
    free(str);
    return (nb);
}
