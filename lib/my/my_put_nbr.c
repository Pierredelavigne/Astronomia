/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** nbr
*/

char *str_append(char const *original, char const *to_append);

char *char_to_end_of_str(char *str, char c);

void my_putchar(char c);

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    else {
        my_putchar((nb) + 48);
    }
}

char *nbr_to_str(int nb)
{
    char *result = "";
    if (nb < 0) {
        result = str_append(result, "-");
        nb = nb * (-1);
    }
    if (nb >= 10) {
        result = str_append(result, nbr_to_str(nb / 10));
        result = char_to_end_of_str(result, (nb % 10) + 48);
    }
    else {
        result = char_to_end_of_str(result, nb + 48);
    }
}