/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:45:07 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 15:31:14 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_game_map *game)
{	
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	game->map = NULL;
	exit(0);
	return (0);
}

int	alert(char *text, t_game_map *game)
{
	int	i;

	i = 0;
	while (text[i])
		i++;
	write(1, "Erorr!", 6);
	write(1, "\n", 1);
	write(1, text, i);
	write(1, "\n", 1);
	if (game)
		exit_hook(game);
	return (0);
}

int	map_checker_name(char *file)
{
	int	i;

	i = ft_strlen(file);
	i--;
	if (file[i] != 'r')
		return (0);
	i--;
	if (file[i] != 'e')
		return (0);
	i--;
	if (file[i] != 'b')
		return (0);
	i--;
	if (file[i] != '.')
		return (0);
	return (1);
}
