/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick main file
*/

#include "../include/matchstick.h"

/* read, write, malloc, free, time, getpid, random, srandom, getline */

char *input_line(void)
{
    char *line = NULL;
    size_t len = 0;
    size_t read = 0;

    my_printf("Your turn:\n");
    my_printf("Line: ");
    read = getline(&line, &len, stdin);
    return (line);
}

char *input_matches(void)
{
    char *matches = NULL;
    size_t len = 0;
    size_t read = 0;

    my_printf("Matches: ");
    read = getline(&matches, &len, stdin);
    return (matches);
}

void display_map(char **tab)
{
    for (int i = 0; tab && tab[i]; i++) {
        my_printf("%s\n", tab[i]);
    }
    my_printf("\n");
}

int main(int ac, char **av)
{
    int number = my_getnbr(av[1]);
    int number2 = (number * 2 + 1);
    char **tab = my_square(number, number2);
    char *line = NULL;
    char *matches = NULL;

    if (ac != 3)
        return (84);
    display_map(tab);
    line = input_line();
    matches = input_matches();
    my_printf("Player removed %d match(es) from line %d\n", my_getnbr(matches),
    my_getnbr(line));
    return 0;
}