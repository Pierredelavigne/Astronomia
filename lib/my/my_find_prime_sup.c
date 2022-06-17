/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** smallest prime number greater or equal than the number given
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int count = nb;
    while (my_is_prime(count) == 0)
    {
        count++;
    }
    return (count);
}
