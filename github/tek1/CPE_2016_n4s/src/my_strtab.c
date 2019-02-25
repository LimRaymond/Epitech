/*
** my_strtab.c for minishell2 in /home/rlim/Epitech/PSU/PSU_2016_minishell2
** 
** Made by LIM Raymond
** Login   <rlim@epitech.net>
** 
** Started on  Sat May 20 15:39:00 2017 LIM Raymond
** Last update Sun Jun  4 16:40:13 2017 LIM Raymond
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	**my_strtab(char *str, char c)
{
  int	i;
  int	x;
  int	y;
  char	**tab;

  x = 0;
  i = 0;
  if (str == NULL || str[0] == '\0')
    return (NULL);
  tab = malloc(sizeof(char *) * strlen(str) + 1);
  while (str[i])
    {
      while (str[i] == c)
	i++;
      tab[x] = malloc(sizeof(char) * strlen(str) + 1);
      y = 0;
      while (str[i] != c && str[i])
	tab[x][y++] = str[i++];
      tab[x][y] = 0;
      x++;
      if (str[i])
	i++;
    }
  tab[x] = NULL;
  return (tab);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
