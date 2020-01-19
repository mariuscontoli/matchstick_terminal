/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** error function source file
*/

#include "../include/matchstick.h"

int error_line(matchstick_t match, int line)
{
    if (line > 0 && line <= match->numb_lines) {
        if (how_many_matches_line(match, line) == 0) {
            my_printf("Error: this line is empty\n");
            return (84);
        }
        return (0);
    } else {
        my_printf("Error: this line is out of range\n");
        return (84);
    }
}

int error_matche(matchstick_t match, int matche)
{   
    if (matche == 0) {
        return (0);
    }
    if (matche > 0 && matche <= how_many_matches_line(match,
    match->current_line)) {
        return (0);
    } else {
        if (matche > match->offset) {
            return (0);
        }
        my_printf("Error: not enough matches on this line\n");
        return (84);
    }
}

int devil_error(matchstick_t match, int matches)
{
    if (matches == -6) {
        matches = -15;
    }
    if (matches > match->offset) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        match->offset);
        match->step = 1;
        matches = -15;
    }
    if (matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        match->step = 1;
        matches = -15;
    }
    return (matches);
}