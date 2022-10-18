// Тут имеющийся одно/двумерный массив с картой, проверенный
// (и сепараторами) теперь надо конвертировать в карту на дисплее.

// На основе массива твоего 
// 1. Идешь по массиву 
// 2.Если там стена, то выводишь картинку стены, сдвигаешься на размер картинки,
// 3. опять проверяешь что в этой координате, 
// 4. выводишь соответствующую картинку
//----------------------------------------

#include "so_long.h"

void paint(t_game_map *game)
{   
    int x;
    int y;
    int i;

    x = 64;     // у нас отвечат за длину 
    y = 0;      // за ширину
    i = 0;      // 64 - длина и ширина текстурки
   
    while (game->map[i])
    {
        if (game->map[i] == '1') // 1 - стена
        {
            mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
            x = x + 64;
        }
        else if (game->map[i] == 'E') // 2 - выход с карты - door
        {
            mlx_put_image_to_window(game->mlx, game->win, game->end_img, x, y);
            x = x + 64;
        }
        else if (game->map[i] == 'C') // 3 - предмет коллекционирования
        {
            mlx_put_image_to_window(game->mlx, game->win, game->items, x, y);
            x = x + 64;
        }
        else if (game->map[i] == 'P') // 4 - стартовая позиция
        {
            mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
            x = x + 64;
        }
        else if (game->map[i] == '|') // 5 - новая строка
        {
            x = 64;
            y = y + 64;  
        }
        else if (game->map[i] == '0') // 6 - пол 
        {
            mlx_put_image_to_window(game->mlx, game->win, game->floor, x, y);
            x = x + 64;
        }
        else if (game->map[i] == 'V') // 7 - враги 
        {
            mlx_put_image_to_window(game->mlx, game->win, game->enemy, x, y);
            x = x + 64;
        }
        
        i++;
    }
}
