// Карта отрисована, теперь надо реализовать механику "движения".
// Для этого надо наш исходный массив "подвязать" с нажатием на клавишу.
// 
// 
// 

#include "so_long.h"

static void find_something(t_game_map *game, int x)
{
// пиксель 64
// map_length; // длина карты - 'x'
// map_height; // высота карты (высчитываем через поданную .ber) - 'y'
//  char *map; 
//  player_position;

    move_enemy_g(game); // они двигаются уже ПОСЛЕ игрока
    move_enemy_v(game);

    if (game->map[x] == '1')
    {}
    if (game->map[x] == 'E')
        find_door(game);
    else if (game->map[x] == '0')
        find_zero(game, x);
    else if (game->map[x] == 'C')
        find_items(game, x);
    else if(game->map[x] == 'V')
        find_enemy(game);

    mlx_clear_window(game->mlx, game->win);

    // if (game->flag == 0)
    // {   
    //     game->flag = 1;
    //     textures(game);
    // }
    // else if (game->flag == 1)
    // {   
    //     game->flag = 0;
    //     textures(game);
    // }

    draw_text(game);
    paint(game); // После совершенного движения мы сразу новый результат кидаем на отрисовку
}

static void move_up(t_game_map *game)
{
    int x;

    x = game->player_position - (game->map_length / 64); // было +1

    // printf("x = %d.", x);
    // printf("\n 3) %d, %c",game->player_position, game->map[game->player_position]);
    // printf("\n 4) %d, %c\n",game->player_position - x, game->map[game->player_position - x]);

    find_something(game, x);
}

static void move_down(t_game_map *game)
{
    int x;

    x = game->player_position + (game->map_length / 64); // было +1, но из-за доп полоски убрал
    find_something(game, x);
}

static void move_left(t_game_map *game)
{
    int x;

    x = game->player_position - 1; // есть разница между --, не забываем!
    find_something(game, x);
}

static void move_right(t_game_map *game)
{
    int x;

    x = game->player_position + 1;
    find_something(game, x);
}

// почему int?
int	key_hook(int keycode, t_game_map *game) // только одна структура!
{ // первый параметр - коды клавиш, второй и третий - зависимая структура

// ну короче происходит движение
// значит надо иницировать изменения в массиве, потом его переотрисовку
    if (keycode == 13)     // W - вверх
        move_up(game); // игрок при движении сталкивется с: стеной(1), дверью(E)
                       // предметами(C), врагами(?)
    if (keycode == 1)      // S - низ
        move_down(game);
    if (keycode == 0)      // A - лево
        move_left(game);
    if (keycode == 2)      // D - право
        move_right(game);
    if (keycode == 53)     // ECS
        exit_hook(game);

    return (0);
}
