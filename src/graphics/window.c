#include "graphics.h"

static void	window_panic(t_window *window)
{
	mlx_terminate(window->mlx);
	free(window);
	exit(EXIT_FAILURE);
}

static void	input(void *param)
{
	t_window	*window;

	window = param;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(window->mlx);
		free(window);
		exit(EXIT_SUCCESS);
	}
}

void	setup_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!window->mlx)
		window_panic(window);
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!window->image)
		window_panic(window);
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		window_panic(window);
	mlx_loop_hook(window->mlx, input, window);
	mlx_loop(window->mlx);
	mlx_terminate(window->mlx);
	free(window);
}
