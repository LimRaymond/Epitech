/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by maje
*/

#ifndef __LIBRICEFEREE_EXTERN__
# define __LIBRICEFEREE_EXTERN__

#include <pthread.h>

/* MUST be the first instruction in your main to Init the library */
int	RCFStartup(int ac, char **av);

/* MUST be called after use to release library ressources */
void	RCFCleanup();

/* Call it when a philo is eating */
int	lphilo_eat();

/* Call it when a philo is sleeping */
int	lphilo_sleep();

/* Call it when a philo is thinking */
int	lphilo_think();

/* Call it when a philo takes a chopstick */
int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);

/* Call it when a philo releases a chopstick */
int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* __LIBRICEFEREE_EXTERN__ */
