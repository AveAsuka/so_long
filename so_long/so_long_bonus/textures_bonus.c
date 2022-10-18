/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:45:20 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:35 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_image(t_game_map *game)
{
	int	pos[2];

	if (game->flag < 50)
		game->player = mlx_xpm_file_to_image(game->mlx,
				"../sprites/player_01.xpm", &pos[0], &pos[1]);
	else
		game->player = mlx_xpm_file_to_image(game->mlx,
				"../sprites/player_02.xpm", &pos[0], &pos[1]);
}

static void	items_image(t_game_map *game)
{
	int	pos[2];

	if (game->flag < 50)
		game->items = mlx_xpm_file_to_image(game->mlx,
				"../sprites/enemy_01.xpm", &pos[0], &pos[1]);
	else
		game->items = mlx_xpm_file_to_image(game->mlx,
				"../sprites/enemy_02.xpm", &pos[0], &pos[1]);
}

static void	enemy_image(t_game_map *game)
{
	int	pos[2];

	if (game->flag < 50)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"../sprites/plant_03.xpm", &pos[0], &pos[1]);
	else
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"../sprites/plant_04.xpm", &pos[0], &pos[1]);
}

void	textures(t_game_map *game)
{
	textures_two(game);
	player_image(game);
	items_image(game);
	enemy_image(game);
}
