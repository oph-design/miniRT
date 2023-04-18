#include "minirt.h"

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		mlx_put_pixel(window->image, x, y, color);
}

void	draw(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_bzero(map->window->image->pixels, WIDTH * HEIGHT * sizeof(int));
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			hit(map, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}
