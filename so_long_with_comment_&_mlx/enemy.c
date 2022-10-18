// Тут я распишу врагов
// По идеи я их сделаю двух - вертикального и горизонтального, которые будут 
// появляться в двух пустях клетках, если они есть
// Надо как-то проработать момент с появлением НЕ рядом с персонажем
// 
// Я принимаю решение появление врагов делать так:
// перебирать данный массив с начала и конца до встречи '0'
// с начала появиться вертикальный, с конца горизонтальный 
// Можно конечно привязать к игроку и или двери, но не думаю что это важно.

#include "so_long.h"

// Когда что-то находим у вертикального и горизонтального
void enemy_floor_g(t_game_map *game, int z)
{
    game->map[z] = 'V';
    game->map[game->enemy_pos_g] = '0';
    game->enemy_pos_g = z;
}

void enemy_player_g(t_game_map *game, int z)
{
    game->map[z] = 'V';
    game->map[game->enemy_pos_g] = '0';
    exit_hook(game);
}

void enemy_floor_v(t_game_map *game, int z)
{
    game->map[z] = 'V';
    game->map[game->enemy_pos_v] = '0';
    game->enemy_pos_v = z;
}

void enemy_player_v(t_game_map *game, int z)
{
    game->map[z] = 'V';
    game->map[game->enemy_pos_v] = '0';
    exit_hook(game);
}

// Прописываем смену координат у горизонтального патруля
void    move_enemy_g(t_game_map *game)
{
    int x;
    int y;

    x = game->enemy_pos_g + 1;
    y = game->enemy_pos_g - 1;

// Если есть куда двигаться справа-налево
    if (game->flag_enemy_g == 0 && game->map[x] == '0') 
        enemy_floor_g(game, x);
    else if(game->flag_enemy_g == 0 && game->map[x] == 'P')
        enemy_player_g(game, x);
    else if (game->flag_enemy_g == 0 && (game->map[x] == '1' || game->map[x] == 'E' || game->map[x] == 'C'))
        game->flag_enemy_g = 1;
// Если нет, то надо иницировать движение слева-направо
    else if (game->flag_enemy_g == 1 && game->map[y] == '0')
        enemy_floor_g(game, y);
    else if(game->flag_enemy_g == 1 && game->map[y] == 'P')
        enemy_player_g(game, y);
    else if (game->flag_enemy_g == 1 && (game->map[y] == '1' || game->map[y] == 'E' || game->map[y] == 'C'))
        game->flag_enemy_g = 0;
}

// Прописываем смену координат у вертикального патруля
void    move_enemy_v(t_game_map *game)
{
    int x;
    int y;

    x = game->enemy_pos_v + (game->map_length / 64);
    y = game->enemy_pos_v - (game->map_length / 64);

// Если есть куда двигаться сверху-вниз
    if (game->flag_enemy_v == 0 && game->map[x] == '0' )
        enemy_floor_v(game, x);
    else if(game->flag_enemy_v == 0 && game->map[x] == 'P')
        enemy_player_v(game, x);
    else if (game->flag_enemy_v == 0 && (game->map[x] == '1' || game->map[x] == 'E' || game->map[x] == 'C'))
        game->flag_enemy_v = 1;
// Если нет, то надо иницировать движение снизу-вверх
    else if (game->flag_enemy_v == 1 && game->map[y] == '0' )
        enemy_floor_v(game, y);
    else if(game->flag_enemy_v == 1 && game->map[y] == 'P')
        enemy_player_v(game, y);
    else if (game->flag_enemy_v == 1 && (game->map[y] == '1' || game->map[y] == 'E' || game->map[y] == 'C'))
        game->flag_enemy_v = 0;
}

// Высчитываем и прописываем место появления
static void enemy_gor(t_game_map *game)
{
    int i;

    i = ft_strlen(game->map);
    while (game->map[i] != '0') // ищем для спавна пустую клетку в конце массива
        i--;

    if (game->map[i] == '0')
    {
        game->enemy_pos_g = i; // привязываем координату со обозначением
        game->map[i] = 'V';
    }

    printf("pos_g = %d, %c\n", game->enemy_pos_g, game->map[i]);
}

static void enemy_ver(t_game_map *game)
{
    int i;

    i = 0;
    while (game->map[i] != '0')
        i++; 
    
    if (game->map[i] == '0')
    {
        game->enemy_pos_v = i;
        game->map[i] = 'V';
    }

    printf("pos_v = %d, %c\n", game->enemy_pos_v, game->map[i]);
}

// Просто объявлем два патруля
void enemy(t_game_map *game) 
{
    enemy_gor(game);
    enemy_ver(game);
}
