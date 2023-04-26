#include "minirt.h"

static void	camera_movement(t_map *map)
{
	t_vector		pos;
	t_camera		*old;
	const double	wh[2] = {map->window->width, map->window->height};

	pos = map->camera->pos;
	old = map->camera;
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_Q))
		pos.z += 0.5;
	else if (mlx_is_key_down(map->window->mlx, MLX_KEY_E))
		pos.z -= 0.5;
	else if (mlx_is_key_down(map->window->mlx, MLX_KEY_W))
		pos.y -= 0.5;
	else if (mlx_is_key_down(map->window->mlx, MLX_KEY_S))
		pos.y += 0.5;
	else if (mlx_is_key_down(map->window->mlx, MLX_KEY_A))
		pos.x += 0.5;
	else if (mlx_is_key_down(map->window->mlx, MLX_KEY_D))
		pos.x -= 0.5;
	else
		return ;
	map->camera = new_cam(pos, map->camera->dir, map->camera->fov, wh);
	free(old);
	draw(map);
}

void	resizing(int32_t width, int32_t height, void *param)
{
	t_map			*map;
	t_camera		*old;
	const double	wh[2] = {(double)width, (double)height};

	map = param;
	old = map->camera;
	map->window->height = height;
	map->window->width = width;
	mlx_delete_image(map->window->mlx, map->window->image);
	map->window->image = mlx_new_image(map->window->mlx, width, height);
	if (!map->window->image)
		window_panic(map);
	if (mlx_image_to_window(map->window->mlx, map->window->image, 0, 0) == -1)
		window_panic(map);
	map->camera = new_cam(old->pos, map->camera->dir, map->camera->fov, wh);
	free(old);
	draw(map);
}

void	input(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(map->window->mlx, map->window->image);
		mlx_terminate(map->window->mlx);
		free(map->window);
		free_map(map);
		exit(EXIT_SUCCESS);
	}
	camera_movement(map);
	light_movement(map);
}
