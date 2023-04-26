#include "minirt.h"

static void	light_move_z(t_map *map, size_t i)
{
	if (i >= map->light_count)
		return ;
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_J))
	{
		map->lighting[i].pos.z -= 1;
		map->lighting[i].obj.pos.z -= 1;
		draw(map);
	}
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_K))
	{
		map->lighting[i].pos.z += 1;
		map->lighting[i].obj.pos.z += 1;
		draw(map);
	}
}

static void	light_move_y(t_map *map, size_t i)
{
	if (i >= map->light_count)
		return ;
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_UP))
	{
		map->lighting[i].pos.y += 1.1;
		map->lighting[i].obj.pos.y += 1.1;
		draw(map);
	}
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_DOWN))
	{
		map->lighting[i].pos.y -= 1.1;
		map->lighting[i].obj.pos.y -= 1.1;
		draw(map);
	}
}

static void	light_move_x(t_map *map, size_t i)
{
	if (i >= map->light_count)
		return ;
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_LEFT))
	{
		map->lighting[i].pos.x -= 1.1;
		map->lighting[i].obj.pos.x -= 1.1;
		draw(map);
	}
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_RIGHT))
	{
		map->lighting[i].pos.x += 1.1;
		map->lighting[i].obj.pos.x += 1.1;
		draw(map);
	}
}

static void	take_input(t_map *map, size_t i)
{
	light_move_x(map, i);
	light_move_y(map, i);
	light_move_z(map, i);
}

void	light_movement(t_map *map)
{
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_1))
		take_input(map, 0);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_2))
		take_input(map, 1);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_3))
		take_input(map, 2);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_4))
		take_input(map, 3);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_5))
		take_input(map, 4);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_6))
		take_input(map, 5);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_7))
		take_input(map, 6);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_8))
		take_input(map, 7);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_9))
		take_input(map, 8);
	if (mlx_is_key_down(map->window->mlx, MLX_KEY_0))
		take_input(map, 9);
}
