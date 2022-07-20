#include <stdio.h>
#include "./minilibx_mms/mlx.h"

int press_esc_key(int key, void *p)
{
    if (key == 0xFF1B)
        exit(0);
    return(0);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1600, 1200, "MyFirst");
    mlx_key_hook(win, press_esc_key, win);
    mlx_loop(mlx); 

    return (0);
}
// cc -I /minilibx_mms/mlx.h main.c -L /minilibx_mms/libmlx.dylib -lmlx -framework OpenGL -framework AppKit
