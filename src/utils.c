/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary source file
*/

#include "../include/matchstick.h"

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int	tmp = 0;

    while (str[i] == ' ') {
        i++;
    }
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        tmp = tmp * 10 + str[i] - '0';
        i++;
    }
    return (tmp * sign);
}