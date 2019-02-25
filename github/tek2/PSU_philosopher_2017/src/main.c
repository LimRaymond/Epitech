/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by rlim,
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extern.h"
#include "my.h"
#include "../include/my.h"

int check_number(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int check_digit(char *str)
{
	int i = 0;

	if (str != NULL) {
		i = check_number(str);
			return (i);
	} else
		return (84);
}

int check_argument(vector_t *vector, char *av, char *second)
{
	if (strcmp(av, "-p") == 0) {
		if (check_digit(second) == 0 && atoi(second) != 1 &&
			atoi(second) != 0)
			vector->p = atoi(second);
		else
			return (84);
	}
	else if (strcmp(av, "-e") == 0) {
		if (check_digit(second) == 0 && atoi(second) != 0)
			vector->e = atoi(second);
		else
			return (84);
	}
	else
		return (84);
	return (0);
}

int main(int ac, char **av)
{
	philo_t *philo;
	vector_t vector = {0, 0};
	int i = 1;

	if (ac == 1)
		return (84);
	if (display_help(av[1]) == 1)
		return (0);
	if (ac != 5)
		return (84);
	while (av[i]) {
		if (check_argument(&vector, av[i], av[i + 1]) == 84)
			return (84);
		i += 2;
	}
	RCFStartup(ac, av);
	philo = fill_list(vector.p, vector.e);
	create_nb_thread(philo, vector.p);
	RCFCleanup();
	return (0);
}