/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:38:45 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/26 16:54:26 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker_three(t_game_map *game)
{
	if (game->b == 1 && game->buf[game->l] != '1'
		&& game->buf[game->l] != '\n')
		return (0);
	game->i++;
	game->l++;
	return (1);
}

void	map_checker_four(t_game_map *game)
{
	game->map = malloc((game->i + 1) * sizeof(char) * game->l);
	game->i = 0;
	game->b = 1;
}
