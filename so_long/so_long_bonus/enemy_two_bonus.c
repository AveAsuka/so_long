/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:58:03 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:08 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_floor_g(t_game_map *game, int z)
{
	game->map[z] = 'V';
	game->map[game->enemy_pos_g] = '0';
	game->enemy_pos_g = z;
}

void	enemy_player_g(t_game_map *game, int z)
{
	game->map[z] = 'V';
	game->map[game->enemy_pos_g] = '0';
	exit_hook(game);
}

void	enemy_floor_v(t_game_map *game, int z)
{
	game->map[z] = 'V';
	game->map[game->enemy_pos_v] = '0';
	game->enemy_pos_v = z;
}

void	enemy_player_v(t_game_map *game, int z)
{
	game->map[z] = 'V';
	game->map[game->enemy_pos_v] = '0';
	exit_hook(game);
}
