#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int close(int keyword, void *is_does)
{
    if(keyword == 65307)
        exit(1);
   if (keyword == 119)  // 'w' key for move up
    {
        printf("Move up\n");
    }
    if (keyword == 97)   // 'a' key for move left
    {
        printf("Move left\n");
    }
    if (keyword == 115)  // 's' key for move down
    {
        printf("Move down\n");
    }
    if (keyword == 100)  // 'd' key for move right
    {
        printf("Move right\n");
    }
    return 0;
}
int main()
{
    void *mlx,  *mlx_new;

    mlx = mlx_init();

    mlx_new =  mlx_new_window(mlx, 500, 500, "test");
    mlx_hook(mlx_new, 2, 1L<<0, close,  NULL);
    mlx_loop(mlx);
}