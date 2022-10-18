#include "so_long.h"

void find_zero(t_game_map *game, int x)
{ // на пустое место
    game->map[x] = 'P';                         // 1. Клеточку соседнюю 'красим' игроком
    game->map[game->player_position] = '0';     // 2. Клеточку игрока обнуляем
    game->player_position = x;                  // 3. Даем игроку новые координаты
    game->steps++;
}

void find_door(t_game_map *game)
{ // Тут надо прописать что делаем когда заходим в дверь
    
    if (game->game_score == game->max_score)
    {
        game->map[game->player_position] = '0';
        game->steps++;
       	exit_hook(game);
    }
    else
        {}
}

void find_enemy(t_game_map *game)
{
    game->map[game->player_position] = '0';
    game->steps++;
    exit_hook(game);
}

void find_items(t_game_map *game, int x)
{
    game->map[x] = '0';
    game->game_score = game->game_score + 1;
}
