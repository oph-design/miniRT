#include "minirt.h"

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		mlx_put_pixel(window->image, x, y, color);
}

uint32_t	write_color(double r, double g, double b, double a)
{
	int	ir;
	int	ig;
	int	ib;
	int	ia;

	ir = r * 0.999;
	ig = g * 0.999;
	ib = b * 0.999;
	ia = a * 0.999;
	return (ir << 24 | ig << 16 | ib << 8 | ia);
}

uint32_t	vec_to_color(t_vector vec)
{
	return (write_color(vec.x, vec.y, vec.z, 255.0));
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
