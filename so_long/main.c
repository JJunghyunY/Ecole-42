#include "./mlx/mlx.h"

int	deal_key(int key, void *param)
{
	printf("%d\n",key);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "get_keycode_test");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);

}

//arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c