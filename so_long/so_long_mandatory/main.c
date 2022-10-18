/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:43:26 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:01:04 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_map	game;

	if (argc == 1 || argc > 2)
		return (alert("False data submission!", 0));
	game.map = NULL;
	if (map_checker_name(argv[1]) != 1)
		return (alert("The program name is incorrect!", 0));
	if (map_checker(argv[1], &game) != 1)
		return (alert("Incorrect termination of the program!", &game));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			game.map_length, game.map_height, "So_long");
	game.flag = 0;
	textures(&game);
	paint(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
