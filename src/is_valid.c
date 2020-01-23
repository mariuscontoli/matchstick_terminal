/*
** EPITECH PROJECT, 2020
** is_valid.c
** File description:
** verification func source file
*/

#include "../include/matchstick.h"

int is_valid_line(matchstick_t match, char *str)
{
    int line = 0;

    if (is_valid_input(str) == 84) {
        return (84);
    }
    line = my_getnbr(str);
    if (error_line(match, line) == 84) {
        return (84);
    }
    return (0);
}

int is_valid_input(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    return (0);
}

int is_valid_matche(matchstick_t match, char *str)
{
    int matche = 0;

    if (is_valid_input(str) == 84) {
        return (-6);
    }
    matche = my_getnbr(str);
    if (error_matche(match, matche) == 84) {
        return (-6);
    }
    return (0);
}