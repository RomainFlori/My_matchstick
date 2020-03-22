/*
** EPITECH PROJECT, 2019
** atoi
** File description:
** str to int
*/

#include <stdio.h>
#include "my.h"

int my_atoi(char const *str)
{
    int i = 0;
    int res = 0;
    int moins = 1;

    while (str[i] == '-') {
        moins = moins * -1;
        i++;
    }
    while (str[i] != '\0') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * moins);
}