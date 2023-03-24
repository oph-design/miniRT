#include "minirt.h"

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		mlx_put_pixel(window->image, x, y, color);
}

uint32_t	pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_vector	mult_double_vec(double d, t_vector vec)
{
	vec.x *= d;
	vec.y *= d;
	vec.z *= d;
	return (vec);
}

void	draw(t_window *window)
{
	int			i;
	int			j;
	double		x;
	double		y;
	uint32_t	color;
	// t_ray		*ray;

	i = 0;
	j = 0;
	ft_bzero(window->image->pixels, WIDTH * HEIGHT * sizeof(int));
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			x = (double)i / (WIDTH - 1);
			y = (double)j / (HEIGHT - 1);
			color = pixel(i / 8 % 0xFF, j / 8 % 0xFF, 0x3B, 0xFF);
			// ray = new_ray(*window->camera->pos, subtract_vec(add_to_vec(add_to_vec(*window->camera->orientation, mult_double_vec(x, *window->camera->horizontal)), mult_double_vec(y, *window->camera->vertical)), *window->camera->pos));
			// color = ray_color(ray);
			draw_pixel(window, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
}
