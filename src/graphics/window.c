#include "minirt.h"

static void	window_panic(t_map *map)
{
	mlx_terminate(map->window->mlx);
	free(map->window);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	setup_window(t_map *map)
{
	map->window = malloc(sizeof(t_window));
	map->window->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	map->window->width = WIDTH;
	map->window->height = HEIGHT;
	if (!map->window->mlx)
		window_panic(map);
	map->window->image = mlx_new_image(map->window->mlx, WIDTH, HEIGHT);
	if (!map->window->image)
		window_panic(map);
	if (mlx_image_to_window(map->window->mlx, map->window->image, 0, 0) == -1)
		window_panic(map);
	draw(map);
	mlx_loop_hook(map->window->mlx, input, map);
	mlx_loop(map->window->mlx);
	mlx_delete_image(map->window->mlx, map->window->image);
	mlx_terminate(map->window->mlx);
	free(map->window);
}
