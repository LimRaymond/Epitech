/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by maje
*/

#ifndef my_HPP_
# define my_HPP_

# include <pthread.h>

enum status {
	THINKING,
	HUNGRY,
	TIRED
};

typedef struct vector_s {
	int e;
	int p;
} vector_t;

typedef struct philo_s {
	int nb_philo;
	int max_eat;
	enum status states;
	pthread_t t;
	pthread_mutex_t mutex;
	struct philo_s *next;
}philo_t;

int display_help(char *av);
philo_t *fill_list(int, int);
void create_nb_thread(philo_t *, int);

#endif //_my_HPP_
