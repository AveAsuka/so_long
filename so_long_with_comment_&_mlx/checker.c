// Тут задача - написать чекер, который будет анализировать 
// входящую карту .ber на валидность.

// То есть у нас есть по сути одинарный/двойной массив символов, который надо
// проанализировать строка за строкой. Если в конце анализа что-то не по 
// правилам, то делаем fail.
// Подумаем за чекер. Надо использовать гнл. 
// Если надо использовать гнл, то его надо как-то врубить в makefile.
// ------------------------------------------------------------------

#include "so_long.h"


// Файл считан в одномерный массив, теперь надо его
// проверить на валидность по условиям из сабжекта:
// 1. прямоугольник +
// 2. окружен стенами (1) - сверху+ снизу+ и по бокам +
// 3. есть минимум один: выход (E), предмет коллекционирования (C) и начальная позицию (P). +
// 4. нету посторонних символов (0 - пустое место, 1 - стена). +
static int valid_map(t_game_map *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    game->max_score = 0;
    game->game_score = 0;
    game->steps = 0;
    
    if (!ft_strchr(game->map, 'E') || !ft_strchr(game->map, 'C'))
        return(-1); // Проверяем условие 3.

    while(game->map[j])
    {
        if (game->map[j] == 'P')
        {
            i++;
            game->player_position = j; // тут мы сохраняем значение, где стоит
                                       // наш игрок
            printf("\nСhecker: j = %d, game->player_position = %d\n", j, game->player_position);
        }
        else if (game->map[j] == 'C')
            game->max_score = game->max_score + 1;
        j++;
    }

    if (i != 1)     // ограничиваем количество стартовых площадок до 1
        return(-1);

    return(1);
}

static int how_many_bite_in(char *file)
{
    int fd; 
    int count;
    char a;

    fd = open(file, O_RDONLY);
    if(!fd)
        return(-1);

    count = 1;
    while(read(fd, &a, 1)) // Когда чтение завершено, данная  функция
    {  // увеличивает  указатель  файла  на число   считанных   байт.
        if (a == 0)
            break ;
        if (a == -1)
            return(-1);
        if (a == '\n')
            count++;
    }

    close(fd);
    return (count);
}

// static int	ft_strcmp_m(char s1, const char *s2) // Немного модернизировал
// {
// 	int	i;

// 	i = 0;
// 	while (s2[i] != '\0' && s1 == s2[i])
// 		i++;
//     if (s2[i] == '\0')
//         return 0;
// 	return (1);
// }

int map_checker(int argc, char *file, t_game_map *game)
{
    int fd;
    int i;
    int l;

    int a; // Кол-во символов в строке
    int b; // Кол-во строк в карте

    char *buf;

    if (argc == 1)
		return(alert("no args"));
	if (argc > 2)
		return(alert("only the first file would be used"));

    i = how_many_bite_in(file);
    fd = open(file, O_RDONLY);

    buf = get_next_line(fd); //Надо спарсить файл в массив, делаем это через гнл.
    l = ft_strlen(buf);
    game->map = malloc((i + 1) * sizeof(char) * l);

    i = 0;
    b = 1;
    while (buf)
    {
        l = 0;
        while (buf[l])
        {
            if (buf[l] != '0' && buf[l] != '1' && buf[l] != 'E' 
                && buf[l] != 'C' && buf[l] != 'P' && buf[l] != '\n')
                return(alert("Посторонний символ!"));

            if (buf[l] == '\n')
                game->map[i] = '|'; // Наш сепаратор.
            else
                game->map[i] = buf[l];

            if (b == 1 && buf[l] != '1' && buf[l] != '\n')
                return(alert("Отсутствует верхняя стенка!")); // Проверяем условие 2.
            i++;
            l++;
        }

        if (b == 1)
            a = l;

        printf("i = %d, b = %d, a = %d. l = %d\n%s", i, b, a, l, buf);

        free(buf);
        buf = get_next_line(fd); 
    
        // Проверяем условие 1.
        if ( (!buf && ((i + 1) != a * b)) || (buf && (i != a * b)) )
            return(alert("Не прямоугольник!"));
    
         // Проверяем условие 2.
        // if (!buf && ( ft_strcmp_m('1', &game->map[i - l]) != 0) ) // Возможная лажа с адресом?
        //     return(alert("Отсутствует нижняя стенка!"));

        // Проверяем условие 2.
        if (buf && (buf[0] != '1' || buf[l - 2] != '1'))
            return(alert("Отсутствует боковая стенка!"));
        
        b++;
    }
    game->map[i] = '\0';

    i--;
    while(game->map[i] != '|')
    {
        printf("%c %d\n", game->map[i], i);
        if(game->map[i] != '1')
            return(alert("Отсутствует нижняя стенка!"));
        i--;
    }

    if (valid_map(game) < 0)
        return(alert("Нету нужного предмета или их слишком много!"));

    game->map_length = ((a-1) * 64) + 64; // длина/ширина карты // ???
    game->map_height = (b-1) * 64; // высота карты 
    printf("\n1. map_length = %d, map_height = %d\n", game->map_length, game->map_height);
   
    close(fd);
    return(1);
}


// int main()
// {
//     char *map;

//     map = map_checker("example.ber", map);

//     if (valid_map(map) > 0)
//         printf ("\nВсё ок.\n");
//     else
//         printf ("\nНету нужного предмета!\n");

//     printf("%s", map);
//     free(map);
//     return 0;
// }
