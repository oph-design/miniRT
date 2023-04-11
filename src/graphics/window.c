#include "minirt.h"

static void	free_window(t_window *window)
{
	free(window);
}

static void	window_panic(t_window *window)
{
	mlx_terminate(window->mlx);
	free_window(window);
	exit(EXIT_FAILURE);
}

static void	input(void *param)
{
	t_window	*window;

	window = param;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(window->mlx, window->image);
		mlx_terminate(window->mlx);
		free_window(window);
		exit(EXIT_SUCCESS);
	}
}

void	setup_window(t_map *map)
{
	map->window = malloc(sizeof(t_window));
	map->window->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	map->window->width = WIDTH;
	map->window->height = HEIGHT;
	if (!map->window->mlx)
		window_panic(map->window);
	map->window->image = mlx_new_image(map->window->mlx, WIDTH, HEIGHT);
	if (!map->window->image)
		window_panic(map->window);
	if (mlx_image_to_window(map->window->mlx, map->window->image, 0, 0) == -1)
		window_panic(map->window);
	draw(map);
	mlx_loop_hook(map->window->mlx, input, map->window);
	mlx_loop(map->window->mlx);
	mlx_delete_image(map->window->mlx, map->window->image);
	mlx_terminate(map->window->mlx);
	free(map->window);
}
