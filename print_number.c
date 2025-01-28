#include "so_long.h"

void print(char c)
{
    write(1, &c, 1);
}
void md_put_number(int nb)
{
    if (nb > 9)
    {
        md_put_number(nb / 10);
        md_put_number(nb % 10);
    }
    else
        print(nb + 48);
}
int close_window(t_game *game)
{
    free_resources(game);
    ft_free(game->map);
    write(1, "\nMap is Closed. Do you feel boring !!", 37);
    exit(0);
}