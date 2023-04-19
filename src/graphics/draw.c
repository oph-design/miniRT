#include "minirt.h"

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < window->width && x >= 0 && y < window->height && y >= 0)
		mlx_put_pixel(window->image, x, y, color);
}

void	draw(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_bzero(map->window->image->pixels,
			map->window->width * map->window->height * sizeof(int));
	while (i < map->window->height)
	{
		while (j < map->window->width)
		{
			hit(map, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}
