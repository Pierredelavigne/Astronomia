/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** add n characters of a string to another one
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    int j = 0;
    while (src[j] != '\0' && nb > j)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
