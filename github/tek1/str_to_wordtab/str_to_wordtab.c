/*                                                                                             
** EPITECH PROJECT, 2018                                                                       
**                                                                                             
** File description:                                                                           
**                                                                                             
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char    **my_str_to_wordtab(char *str)
{
  int   i = 0;
  int   x = 0;
  int   y ;
  char  **tab;

  if (str == NULL || str[0] == '\0')
    return (NULL);
  tab = malloc(sizeof(char *) * (strlen(str) / 2 + 2));
  for (; str[i]; i++) {
      tab[x] = malloc(sizeof(char) * (strlen(str)) + 1);
      y = 0;
      while (((str[i] >= '0' && str[i] <= '9') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z')) && str[i] != '\0')
        tab[x][y++] = str[i++];
      tab[x][y] = '\0';
      x++;
    }
  tab[x] = NULL;
  return (tab);
}
