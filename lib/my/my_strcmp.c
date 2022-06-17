/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my_strcmp
*/

char *my_strcpy(char *dst, const char *src)
{
    char *result = dst;

    while ((*dst = *src) != '\0')
    {
        dst++;
        src++;
    }
    return (result);
}

int my_strcmp(const char *string_one, const char *string_two)
{
    while (*string_one == *string_two++)
        if (*string_one++ == 0)
            return (0);
    return (*(unsigned char *)string_one - *(unsigned char *)--string_two);
}