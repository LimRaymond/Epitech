/*
** my.h for n4s in /home/gfischer/delivery/CPE/n4s_package/include
** 
** Made by Guillaume Fischer
** Login   <gfischer@epitech.net>
** 
** Started on  Tue May 16 15:36:19 2017 Guillaume Fischer
** Last update Sun Jun  4 16:35:36 2017 Pierre Bouteiller
*/

#ifndef MY_H_
# define MY_H_

#define READ_SIZE 1

void	car_setting();
char	*get_next_line(int fd);
char	**my_str_to_wordtab(char *);
char	**my_strtab(char *str, char c);
void	free_tab(char **tab);

#endif /* !MY_H_ */
