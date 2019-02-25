/*
** get_next_line.c for n4s in /home/rlim/Epitech/CPE/CPE_2016_n4s
** 
** Made by LIM Raymond
** Login   <rlim@epitech.net>
** 
** Started on  Wed May 31 12:56:18 2017 LIM Raymond
** Last update Wed May 31 12:56:26 2017 LIM Raymond
*/


#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_stradd(char *line, char c)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * (my_strlen(line) + 2))) == NULL)
    return (NULL);
  i = 0;
  while (line[i] != '\0')
    {
      new[i] = line[i];
      i++;
    }
  new[i] = c;
  new[i + 1] = '\0';
  free(line);
  return (new);
}

char	*get_next_line(int fd)
{
  int	ret;
  char	c;
  char	*line;

  if ((line = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  line[0] = '\0';
  c = 0;
  while ((ret = read(fd, &c, 1) != 0) && c != '\n')
    {
      if ((line = my_stradd(line, c)) == NULL)
	return (NULL);
    }
  if (ret == 0)
    return (NULL);
  return (line);
}
