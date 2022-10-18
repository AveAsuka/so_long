#include "so_long.h"

int	exit_hook(t_game_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
    free(game->map);
	game->map = NULL;

	exit(0);
	return(0);
}

int	alert(char *text)
{
	int	i;

	i = 0;
	while (text[i])
		i++;
	write(1, text, i);
	write(1, "\n", 1);

	return (0);
}

int map_checker_name(char *file)
{
	int i;

	i = ft_strlen(file);

	i--;
	if (file[i] != 'r')
		return(0);
	i--;
	if (file[i] != 'e')
		return(0);
	i--;
	if (file[i] != 'b')
		return(0);
	i--;
	if (file[i] != '.')
		return(0);
	
	return(1);
}
