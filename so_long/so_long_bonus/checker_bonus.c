/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:00:10 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:03 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	valid_map(t_game_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->max_score = 0;
	game->game_score = 0;
	game->steps = 0;
	if (!ft_strchr(game->map, 'E') || !ft_strchr(game->map, 'C'))
		return (-1);
	while (game->map[j])
	{
		if (game->map[j] == 'P')
		{
			i++;
			game->player_position = j;
		}
		else if (game->map[j] == 'C')
			game->max_score = game->max_score + 1;
		j++;
	}
	if (i != 1)
		return (-1);
	return (1);
}

static int	how_many_bite_in(char *file)
{
	int		fd;
	int		count;
	char	a;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	count = 1;
	while (read(fd, &a, 1))
	{
		if (a == 0)
			break ;
		if (a == -1)
			return (-1);
		if (a == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	bottom_wall(t_game_map *game, int i)
{
	i--;
	while (game->map[i] != '|')
	{
		if (game->map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	map_checker_two(t_game_map *game, int fd)
{
	while (game->buf[game->l])
	{
		if (game->buf[game->l] != '0' && game->buf[game->l] != '1'
			&& game->buf[game->l] != 'E'
			&& game->buf[game->l] != 'C' && game->buf[game->l] != 'P'
			&& game->buf[game->l] != '\n')
			return (alert("An extraneous symbol!", game));
		if (game->buf[game->l] == '\n')
			game->map[game->i] = '|';
		else
			game->map[game->i] = game->buf[game->l];
		if (map_checker_three(game) != 1)
			return (alert("There is no upper wall!", game));
	}
	if (game->b == 1)
		game->a = game->l;
	free(game->buf);
	game->buf = get_next_line(fd);
	if ((!game->buf && ((game->i + 1) != game->a * game->b))
		|| (game->buf && (game->i != game->a * game->b)))
		return (alert("Not a rectangle!", game));
	if (game->buf && (game->buf[0] != '1' || game->buf[game->l - 2] != '1'))
		return (alert("There is no side wall!", game));
	game->b++;
	return (1);
}

int	map_checker(char *file, t_game_map *game)
{
	int		fd;

	game->i = how_many_bite_in(file);
	fd = open(file, O_RDONLY);
	game->buf = get_next_line(fd);
	game->l = ft_strlen(game->buf);
	map_checker_four(game);
	while (game->buf)
	{
		game->l = 0;
		if (map_checker_two(game, fd) != 1)
			return (alert("Error!", game));
	}
	game->map[game->i] = '\0';
	if (bottom_wall(game, game->i) != 1)
		return (alert("The bottom wall is missing!", game));
	if (valid_map(game) < 0)
		return (alert("No necessary item or there are too many of them!",
				game));
	game->map_length = ((game->a - 1) * 64) + 64;
	game->map_height = (game->b - 1) * 64;
	close(fd);
	return (1);
}
