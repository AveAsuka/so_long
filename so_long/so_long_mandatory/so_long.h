/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:52:33 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:00:51 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include <mlx.h>
# include "../gnl/get_next_line_bonus.h"
# include "../libft/libft.h"

typedef struct s_game_map
{
	int		map_length;
	int		map_height;

	int		player_position;
	int		game_score;
	int		max_score;
	char	*map;
	int		steps;

	void	*end_img;
	void	*wall;
	void	*player;
	void	*floor;
	void	*items;
	int		flag;

	void	*mlx;
	void	*win;

	int		i;
	int		b;
	int		l;
	int		a;
	char	*buf;
}	t_game_map;

int		map_checker(char *file, t_game_map *game);
int		map_checker_three(t_game_map *game);
void	map_checker_four(t_game_map *game);
void	textures(t_game_map *game);
void	textures_two(t_game_map *game);
void	paint(t_game_map *game);
int		key_hook(int keycode, t_game_map *game);
int		key_hook_two(int keycode, t_game_map *game);
void	find_something(t_game_map *game, int x);

void	find_zero(t_game_map *game, int x);
void	find_items(t_game_map *game, int x);
void	find_door(t_game_map *game);

int		exit_hook(t_game_map *game);
int		alert(char *text, t_game_map *game);
int		map_checker_name(char *file);

#endif
