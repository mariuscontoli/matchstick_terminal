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

char **my_square(int number, int number2);
int how_much_letters(char const *str, int x);
int how_much_words(char const *str);
char *my_strclean(char *dest, char const *src);
int avoid_sep(char const *str, int i);
int my_getnbr(char *str);
int is_alpha(char c);
int my_strlen(char const *str);

#endif /* !MATCHSTICK_H_ */
