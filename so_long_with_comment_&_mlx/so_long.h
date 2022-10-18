#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>     // для open, как я понял
# include <stdlib.h>    // для malloc
# include <unistd.h>    // для write

#include "./gnl/get_next_line_bonus.h"
#include "./libft/libft.h"

# include <stdio.h>     // Не забыть удалить

// Первая основная структура - через неё проходят всё игровое
typedef struct s_game_map
{   // пиксель 64
    int     map_length; // длина карты - 'x'
    int     map_height; // высота карты (высчитываем через поданную .ber) - 'y'
    
    int     player_position; // у меня одномерный массив, я буду использовать
                             // положение игрока в нём

    int     game_score;      // сколько собрано
    int     max_score;       // сколько надо собрать

    char    *map;       // здесь сидит моя спарсенная карта в формате
                        // одномерного массива
    int     steps;      // сколько сделано шагов

    // Мои текстуры
    void    *end_img; // door  - выход с карты
    void    *wall;
    void    *player;  // стартовая позиция
    void    *floor;
    void    *items;
    void    *enemy;

    int     flag;        // флаг для смены анимации

// Врага обозначим как 'V'
    int     enemy_pos_v; // координата вертикального врага
    int     flag_enemy_v;
    int     enemy_pos_g; // координата горизонтального врага
    int     flag_enemy_g;

    void    *mlx; 
    void    *win;
}   t_game_map;

// Mandatory
int     map_checker(int argc, char *file, t_game_map *game);
void	textures(t_game_map *game);
void    paint(t_game_map *game);
int     key_hook(int keycode, t_game_map *game); // ?

void    find_zero(t_game_map *game, int x);
void    find_items(t_game_map *game, int x);
void    find_door(t_game_map *game);
void    find_enemy(t_game_map *game);

// Utils
int     exit_hook(t_game_map *game);
int     alert(char *text);
int     map_checker_name(char *file);

// Bonus
int     update(t_game_map *game);
void    enemy(t_game_map *game);
void    draw_text(t_game_map *game);
void    move_enemy_g(t_game_map *game);
void    move_enemy_v(t_game_map *game);

#endif
