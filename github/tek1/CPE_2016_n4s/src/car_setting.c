/*
** car_setting.c for car_setting in /home/gfischer/delivery/CPE/n4s_package
** 
** Made by Guillaume Fischer
** Login   <gfischer@epitech.net>
** 
** Started on  Mon May 15 14:00:00 2017 Guillaume Fischer
** Last update Sun Jun  4 16:34:26 2017 Pierre Bouteiller
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

static int	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "Track Cleared", 5) == 0)
	write(1, "stop_simulation\n", strlen("stop_simulation\n"));;
      i++;
    }
  return (i);
}

static void	set_speed(char **speed)
{
  int		i;
  double	mid;

  i = 0;
  aff_tab(speed);
  if ((atof(speed[15]) >= 2000.0))
    write(1, "car_forward:1.0\n", strlen("car_forward:1.0\n"));
  else if (atof(speed[15]) >= 1500.0)
    write(1, "car_forward:0.6\n", strlen("car_forward:0.8\n"));
  else if (atof(speed[15]) >= 1000.0)
    write(1, "car_forward:0.5\n", strlen("car_forward:0.5\n"));
  else if (atof(speed[15]) >= 600.0)
    write(1, "car_forward:0.3\n", strlen("car_forward:0.3\n"));
  else if (atof(speed[15]) >= 400.0)
    write(1, "car_forward:0.2\n", strlen("car_forward:0.8\n"));
  else
    write(1, "car_forward:0.1\n", strlen("car_forward:0.1\n"));
  get_next_line(0);
}

static void	direction(char *val, double dir)
{
  write(1, "wheels_dir:", strlen("wheels_dir:"));
  if (dir < 0.0)
    write(1, "-", 1);
  write(1, val, strlen(val));
  get_next_line(0);
}

static void	set_dir(char **speed)
{
  int		i;
  double	dir;

  dir = atof(speed[6]) - atof(speed[30]);
  i = 0;
  if (atof(speed[15]) >= 1500.0)
    direction("0.005\n", dir);
  else if (atof(speed[15]) >= 1000.0)
    direction("0.05\n", dir);
  else if (atof(speed[15]) >= 600.0)
    direction("0.1\n", dir);
  else if (atof(speed[15]) >= 400.0)
    direction("0.2\n", dir);
  else if (atof(speed[15]) >= 200.0)
    direction("0.3\n", dir);
  else
    direction("0.5\n", dir);
}

void		car_setting()
{
  int		i;
  char		*buff;
  char		**tab;

  write(1, "START_SIMULATION\n", strlen("START_SIMULTATION\n"));
  get_next_line(0);
  while (1)
    {
      write(1, "GET_INFO_LIDAR\n", strlen("get_info_lidar\n"));
      buff = get_next_line(0);
      tab = my_strtab(buff, ':');
      i = aff_tab(tab);
      if (i > 4)
	{
	  set_speed(tab);
	  set_dir(tab);
	}
    }
  free_tab(tab);
}
