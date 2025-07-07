// mlx_test.c
#include "minilinux/mlx.h"

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 300, "MiniLibX Test");
    mlx_loop(mlx);
    return (0);
}
