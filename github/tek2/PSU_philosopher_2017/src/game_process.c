/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by rlim,
*/

#include <stdlib.h>
#include <pthread.h>
#include "extern.h"
#include "my.h"
#include "../include/my.h"
#include "../include/extern.h"

int eat(philo_t *philo, int max_eat)
{
	if (pthread_mutex_trylock(&philo->mutex) == 0) {
		lphilo_take_chopstick(&philo->mutex);
		if (pthread_mutex_trylock(&philo->next->mutex) == 0) {
			lphilo_take_chopstick(&philo->next->mutex);
			lphilo_eat();
			philo->states = TIRED;
			pthread_mutex_unlock(&philo->next->mutex);
			lphilo_release_chopstick(&philo->next->mutex);
			max_eat--;
		}
		pthread_mutex_unlock(&philo->mutex);
		lphilo_release_chopstick(&philo->mutex);
	}
	return (max_eat);
}

void think(philo_t *philo)
{
	if (pthread_mutex_trylock(&philo->mutex) == 0) {
		lphilo_take_chopstick(&philo->mutex);
		lphilo_think();
		philo->states = HUNGRY;
		pthread_mutex_unlock(&philo->mutex);
		lphilo_release_chopstick(&philo->mutex);
	}
}

void sleeper(philo_t *philo)
{
	lphilo_sleep();
	philo->states = THINKING;
}

void *loop_process(void *tab)
{
	philo_t *philo = (philo_t *)tab;
	while (philo->max_eat > 0) {
		if (philo->states == HUNGRY)
			philo->max_eat = eat(philo, philo->max_eat);
		else if (philo->states == THINKING)
			think(philo);
		else
			sleeper(philo);
	}
	return (NULL);
}

void create_nb_thread(philo_t *philo, int nb_philo)
{
	int i;
	philo_t *start = philo;

	for (i = 0; i < nb_philo; i++) {
		pthread_create(&philo->t, NULL, loop_process, philo);
		philo = philo->next;
	}
	philo = start;
	for (i = 0; i < nb_philo; i++) {
		pthread_join(philo->t, NULL);
		philo = philo->next;
	}
}