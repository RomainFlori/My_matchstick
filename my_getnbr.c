/*
** EPITECH PROJECT, 2019
** getnbr
** File description:
** 
*/

#include "my.h"
#include <unistd.h>

int reduc(char const *str, int x, int i)
{
    if (str[i] == '-')
        x = x * -1;
    return (x);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int y = 0;
    int x = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (y <= 0)
            x = reduc(str, x, i);
        while (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + str[i] - 48;
            y++;
            i++;
        }
        i++;
    }
    return (nb * x);
}
