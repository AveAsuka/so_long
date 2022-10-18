/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:19:59 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/10 20:39:51 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);
char	*get_next_line_two(int *check, char **buffer, int fd, char *result);
char	*buffer_is_there(char *buffer, char *result, int *check);
char	*move_buf(char *buffer, int check);
void	exterminate(char **execution);
int		ft_index(char *str, int d);
char	*ft_strjoin_GNL(char *s1, char *s2, int d);
char	*ft_strjoin_two_GNL(int *j, char *str, int len, char *s1);
int		ft_strlen_GNL(char *str); // ?

#endif
