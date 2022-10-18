/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_two_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:25:31 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:37 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	wall_image(t_game_map *game)
{
	int	pos[2];

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/wall_01.xpm", &pos[0], &pos[1]);
}

static void	door_image(t_game_map *game)
{
	int	pos[2];

	if (game->game_score == game->max_score)
		game->end_img = mlx_xpm_file_to_image(game->mlx,
				"../sprites/door_02.xpm", &pos[0], &pos[1]);
	else
		game->end_img = mlx_xpm_file_to_image(game->mlx,
				"../sprites/door_01.xpm", &pos[0], &pos[1]);
}

void	textures_two(t_game_map *game)
{
	wall_image(game);
	door_image(game);
}
