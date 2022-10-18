
#include "so_long.h"

int update(t_game_map *game)
{
    if (game->flag < 50)
    {   
        textures(game);
        paint(game);
    }
    if (game->flag >= 50)
    {   
        textures(game);
        paint(game);
    }
    if (game->flag == 100)
        game->flag = 0;
    
    game->flag++;
    return(1);
}

void	draw_text(t_game_map *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 24, 24, -1, str);
	free(str);
}

