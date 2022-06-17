/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr fuction
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int i_two = 0;

    for (i; str[i] != '\0' + 1; i++) {
        if (to_find[i] == '\0') {
            str[i] = '\0';
            return (&str[i - i_two]);
        }
        if (to_find[i_two] == str[i])
            i_two++;
        else
            i_two = 0;
    }
    return ("NULL");
}
