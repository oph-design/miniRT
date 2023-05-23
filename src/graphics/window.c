/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:18 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:32:19 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_panic(t_map *map)
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
	mlx_resize_hook(map->window->mlx, resizing, map);
	mlx_loop(map->window->mlx);
	mlx_delete_image(map->window->mlx, map->window->image);
	mlx_terminate(map->window->mlx);
	free(map->window);
}
