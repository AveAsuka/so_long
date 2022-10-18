/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:06:00 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 15:20:25 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_two_gnl(int *j, char *str, int len, char *s1)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[(*j)++] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int d)
{
	char	*str;
	int		i;
	int		j;
	int		len_two;
	int		len;

	j = 0;
	len_two = ft_strlen_gnl(s2);
	if (d != -1)
		len_two = d + 1;
	str = (char *)malloc(ft_strlen_gnl(s1) + len_two + 1);
	if (!str)
		return (NULL);
	len = ft_strlen_gnl(s1);
	str = ft_strjoin_two_gnl(&j, str, len, s1);
	i = 0;
	while (i < len_two)
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

int	ft_index(char *str, int d)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == d)
			return (i);
		i++;
	}
	return (-1);
}
