/*
** EPITECH PROJECT, 2020
** input.c
** File description:
** input functions source file
*/

#include "../include/matchstick.h"

int input_line(matchstick_t match, int step)
{
    char *str = NULL;
    int line = 0;
    int error = 84;
    size_t len = 0;
    size_t read = 0;
    if (step == 0)
        my_printf("\nYour turn:\n");
    while (error == 84) {
        my_printf("Line: ");
        read = getline(&str, &len, stdin);
        if (read == EOF)
            return -1;
        error = is_valid_line(match, str);
        line = my_getnbr(str);
    }
    error = 84;
    return (line);
}

int input_matches(matchstick_t match)
{
    char *str = NULL;
    int matches = 0;
    int error = 84;
    size_t len = 0;
    size_t read = 0;

    while (error == 84) {
        my_printf("Matches: ");
        read = getline(&str, &len, stdin);
        if (read == EOF)
            return (-1);
        error = is_valid_matche(match, str);
        matches = my_getnbr(str);
        if (error == -6)
            matches = -6;
    }
    error = 84;
    return (matches);
}

int input(matchstick_t match)
{
    int line = 0;
    match->step = 0;
    int matches = -15;
    while (matches == -15) {
        line = input_line(match, match->step);
        if (line == -1)
            return (-1);
        match->current_line = line;
        matches = input_matches(match);
        if (matches == -1)
            return (-1);
        matches = devil_error(match, matches);
    }
    my_printf("Player removed %d match(es) from line %d\n", matches,
    line);
    my_remove(match, line, matches);
    match->match_left -= matches;
}