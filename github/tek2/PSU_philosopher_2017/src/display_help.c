/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by rlim,
*/

#include <string.h>
#include <stdio.h>
#include "my.h"

int display_help(char *av)
{
	if (strcmp(av, "--help") == 0) {
		printf("USAGE\n");
		printf("\t./philo -p nbr_p -e nbr_e\n\n");
		printf("DESCRIPTION\n");
		printf("\t-p nbr_p number of philosophers\n");
		printf("\t-e nbr_e maximum number times a"
			" philosopher eats before "
			"exiting the program.\n");
		return (1);
	}
	return (0);
}