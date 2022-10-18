/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:46:13 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:07 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_g(t_game_map *game)
{
	int	x;
	int	y;

	x = game->enemy_pos_g + 1;
	y = game->enemy_pos_g - 1;
	if (game->flag_enemy_g == 0 && game->map[x] == '0')
		enemy_floor_g(game, x);
	else if (game->flag_enemy_g == 0 && game->map[x] == 'P')
		enemy_player_g(game, x);
	else if (game->flag_enemy_g == 0 && (game->map[x] == '1'
			|| game->map[x] == 'E' || game->map[x] == 'C'))
		game->flag_enemy_g = 1;
	else if (game->flag_enemy_g == 1 && game->map[y] == '0')
		enemy_floor_g(game, y);
	else if (game->flag_enemy_g == 1 && game->map[y] == 'P')
		enemy_player_g(game, y);
	else if (game->flag_enemy_g == 1 && (game->map[y] == '1'
			|| game->map[y] == 'E' || game->map[y] == 'C'))
		game->flag_enemy_g = 0;
}

void	move_enemy_v(t_game_map *game)
{
	int	x;
	int	y;

	x = game->enemy_pos_v + (game->map_length / 64);
	y = game->enemy_pos_v - (game->map_length / 64);
	if (game->flag_enemy_v == 0 && game->map[x] == '0')
		enemy_floor_v(game, x);
	else if (game->flag_enemy_v == 0 && game->map[x] == 'P')
		enemy_player_v(game, x);
	else if (game->flag_enemy_v == 0 && (game->map[x] == '1'
			|| game->map[x] == 'E' || game->map[x] == 'C'))
		game->flag_enemy_v = 1;
	else if (game->flag_enemy_v == 1 && game->map[y] == '0' )
		enemy_floor_v(game, y);
	else if (game->flag_enemy_v == 1 && game->map[y] == 'P')
		enemy_player_v(game, y);
	else if (game->flag_enemy_v == 1 && (game->map[y] == '1'
			|| game->map[y] == 'E' || game->map[y] == 'C'))
		game->flag_enemy_v = 0;
}

static void	enemy_gor(t_game_map *game)
{
	int	i;

	i = ft_strlen(game->map);
	while (game->map[i] != '0')
		i--;
	if (game->map[i] == '0')
	{
		game->enemy_pos_g = i;
		game->map[i] = 'V';
	}
}

static void	enemy_ver(t_game_map *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '0')
		i++;
	if (game->map[i] == '0')
	{
		game->enemy_pos_v = i;
		game->map[i] = 'V';
	}
}

void	enemy(t_game_map *game)
{
	enemy_gor(game);
	enemy_ver(game);
}
