/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** cpy char to a other char
*/

char *my_strncpy(char *dest , char  const *src , int n)
{
    int i = 0;

    for (i; i < n; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
