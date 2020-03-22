/*
** EPITECH PROJECT, 2020
** directory
** File description:
** my
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_atoi(char const *str);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int my_putnbr(int nb);
char **map(int ac, char **av);
char *get_next_line(int fd);
char **removepipe(int nbline, int nbmatches, char **map1);

#endif /* !MY_H_ */
