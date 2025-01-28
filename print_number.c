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