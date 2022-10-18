/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:33:59 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:01:46 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_something(t_game_map *game, int x)
{
	if (game->map[x] == '1')
	{
	}
	if (game->map[x] == 'E')
		find_door(game);
	else if (game->map[x] == '0')
		find_zero(game, x);
	else if (game->map[x] == 'C')
		find_items(game, x);
	mlx_clear_window(game->mlx, game->win);
	paint(game);
}

static void	move_left(t_game_map *game)
{
	int	x;

	x = game->player_position - 1;
	find_something(game, x);
}

static void	move_right(t_game_map *game)
{
	int	x;

	x = game->player_position + 1;
	find_something(game, x);
}

int	key_hook(int keycode, t_game_map *game)
{
	if (keycode == 0)
		move_left(game);
	if (keycode == 2)
		move_right(game);
	if (keycode == 53)
		exit_hook(game);
	return (key_hook_two(keycode, game));
}
