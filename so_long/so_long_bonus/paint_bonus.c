/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:04:00 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:30 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	paint_two(t_game_map *game, int i, int x, int y)
{
	if (game->map[i] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
	else if (game->map[i] == '0')
	{
	}
	else if (game->map[i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->end_img, x, y);
	else if (game->map[i] == 'V')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy, x, y);
	else if (game->map[i] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->items, x, y);
	x = x + 64;
	return (x);
}

void	paint(t_game_map *game)
{
	int	x;
	int	y;
	int	i;

	x = 64;
	y = 0;
	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
			x = x + 64;
		}
		else if (game->map[i] == '|')
		{
			x = 64;
			y = y + 64;
		}
		else
			x = paint_two(game, i, x, y);
		i++;
	}
}
