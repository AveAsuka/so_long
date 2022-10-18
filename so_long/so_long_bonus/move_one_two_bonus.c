/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_one_two_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:39:13 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:24 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_up(t_game_map *game)
{
	int	x;

	x = game->player_position - (game->map_length / 64);
	find_something(game, x);
}

static void	move_down(t_game_map *game)
{
	int	x;

	x = game->player_position + (game->map_length / 64);
	find_something(game, x);
}

int	key_hook_two(int keycode, t_game_map *game)
{
	if (keycode == 13)
		move_up(game);
	if (keycode == 1)
		move_down(game);
	return (0);
}
