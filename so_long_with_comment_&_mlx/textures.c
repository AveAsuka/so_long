// Тут мы просто подрубаем все текстуры предварительно для вывода

#include "so_long.h"

static void wall_image(t_game_map *game)
{
    int         pos[2]; 

    game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall_01.xpm",  &pos[0], &pos[1]);
}

static void door_image(t_game_map *game)
{
    int         pos[2]; 

    if (game->game_score == game->max_score)
        game->end_img = mlx_xpm_file_to_image(game->mlx, "sprites/door_02.xpm",  &pos[0], &pos[1]);
    else
        game->end_img = mlx_xpm_file_to_image(game->mlx, "sprites/door_01.xpm",  &pos[0], &pos[1]);
}

static void player_image(t_game_map *game)
{
    int         pos[2]; 

    if (game->flag < 50)
        game->player = mlx_xpm_file_to_image(game->mlx, "sprites/player_01.xpm",  &pos[0], &pos[1]);
    else
        game->player = mlx_xpm_file_to_image(game->mlx, "sprites/player_02.xpm",  &pos[0], &pos[1]);
}

static void items_image(t_game_map *game)
{
    int         pos[2];

    if (game->flag < 50)
        game->items = mlx_xpm_file_to_image(game->mlx, "sprites/enemy_01.xpm",  &pos[0], &pos[1]);
    else
        game->items = mlx_xpm_file_to_image(game->mlx, "sprites/enemy_02.xpm",  &pos[0], &pos[1]);
}

static void enemy_image(t_game_map *game)
{
    int         pos[2];

    if (game->flag < 50)
        game->enemy = mlx_xpm_file_to_image(game->mlx, "sprites/plant_03.xpm",  &pos[0], &pos[1]);
    else
        game->enemy = mlx_xpm_file_to_image(game->mlx, "sprites/plant_04.xpm",  &pos[0], &pos[1]);
}

void	textures(t_game_map *game)
{
    wall_image(game);   // +
	door_image(game);   // + door
    player_image(game); // + она же стартовая позиция
    items_image(game);  // +
    enemy_image(game);  // +
}
