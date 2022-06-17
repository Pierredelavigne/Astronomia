/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** Check if a number is prime or not
*/

int my_is_prime(int nb)
{
    int i = 0;
    int c = 0;
    for (i = 1; i <= nb; i++) {
        if (nb % i == 0) {
            c++;
        }
    }

    if (c == 2) {
        return (1);
    }
    else {
        return (0);
    }
    return (0);
}