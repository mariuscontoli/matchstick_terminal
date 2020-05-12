/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary source file
*/

#include "../include/matchstick.h"

void display_map(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_printf("%s\n", tab[i]);
    }
}

int how_many_matches(matchstick_t match)
{
    int len = 0;

    for (int i = 0; i != match->height; i++) {
        for (int j = 0; match->map[i][j]; j++) {
            if (match->map[i][j] == '|')
                len += 1;
        }
    }
    return (len);
}

int how_many_matches_line(matchstick_t match, int line)
{
    int len = 0;

    for (int i = 0; i != match->len_line; i++) {
        if (match->map[line][i] == '|')
            len += 1;
    }
    return (len);
}

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int	tmp = 0;
    int devil = 0;

    while (str[i] == ' ')
        i++;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    if (str[i] == '0')
        devil = 1;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        tmp = tmp * 10 + str[i] - '0';
        i++;
        devil++;
    }
    if (devil != 1 && tmp == 0)
        return -6;
    return (tmp * sign);
}

void free_struct(matchstick_t match)
{
    int i = 0;
    while (match->map[i] != NULL) {
        free(match->map[i]);
        i++;
    }
    free(match->map);
    free(match);
}