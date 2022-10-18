/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_two_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:33:02 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:28 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_zero(t_game_map *game, int x)
{
	game->map[x] = 'P';
	game->map[game->player_position] = '0';
	game->player_position = x;
	game->steps++;
}

void	find_door(t_game_map *game)
{
	if (game->game_score == game->max_score)
	{
		game->map[game->player_position] = '0';
		game->steps++;
		exit_hook(game);
	}
	else
	{
	}
}

void	find_enemy(t_game_map *game)
{
	game->map[game->player_position] = '0';
	game->steps++;
	exit_hook(game);
}

void	find_items(t_game_map *game, int x)
{
	game->map[x] = '0';
	game->game_score = game->game_score + 1;
}
