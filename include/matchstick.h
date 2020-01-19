/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** matchstick header file
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../my_printf/include/my_printf.h"

typedef struct matchstick
{
    char **map;
    int stop;
    int length;
    int offset;
    int numb_lines;
    int len_line;
    int len_map;
    int height;
    int error;
    int current_line;
    int match_left;
    int step;
}*matchstick_t;

void my_square(matchstick_t match);
void fill_with_matches(matchstick_t match);
void my_remove(matchstick_t match, int line, int matches);
void game(matchstick_t match);
void input(matchstick_t match);
void display_map(char **tab);
int input_line(matchstick_t match, int step);
int input_matches(matchstick_t match);
int is_valid_line(matchstick_t match, char *str);
int is_valid_input(char *str);
int is_valid_matche(matchstick_t match, char *str);
int how_many_matches(matchstick_t match);
int how_many_matches_line(matchstick_t match, int line);
int error_line(matchstick_t match, int line);
int error_matche(matchstick_t match, int matche);
int devil_error(matchstick_t match, int matches);
int how_much_letters(char const *str, int x);
int how_much_words(char const *str);
int my_getnbr(char *str);
int my_strlen(char const *str);

#endif /* !MATCHSTICK_H_ */
