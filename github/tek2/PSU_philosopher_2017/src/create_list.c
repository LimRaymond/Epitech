/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by rlim,
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "../include/my.h"

void add_elem(philo_t **start, int eat_max)
{
	philo_t *elem;

	elem = malloc(sizeof(philo_t));
	if (elem == NULL)
		return ;
	elem->next = *start;
	elem->states = TIRED;
	pthread_mutex_init(&elem->mutex, NULL);
	elem->max_eat = eat_max;
	*start = elem;
}

philo_t *fill_list(int nb_philo, int eat_max)
{
	int i;
	philo_t *start = NULL;
	philo_t *buf;
	for (i = 0; nb_philo > i; i++) {
		add_elem(&start, eat_max);
	}
	buf = start;
	if (buf != NULL) {
		while (buf->next != NULL)
			buf = buf->next;
		buf->next = start;
	}
	return (start);
}
