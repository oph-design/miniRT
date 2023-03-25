#include "minirt.h"

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		mlx_put_pixel(window->image, x, y, color);
}

uint32_t	color(double r, double g, double b, double a)
{
	int	ir;
	int	ig;
	int	ib;
	int	ia;

	ir = r * 255.999;
	ig = g * 255.999;
	ib = b * 255.999;
	ia = a * 255.999;
	return (ir << 24 | ig << 16 | ib << 8 | ia);
}

t_ray	*background(t_camera *camera, double x, double y)
{
	t_vector	dest;

	dest = subtract_vec(add_to_vec(
				add_to_vec(*camera->orientation, mult_double_vec(
						x, *camera->horizontal)),
				mult_double_vec(y, *camera->vertical)), *camera->pos);
	return (new_ray(*camera->pos, dest));
}

void	draw(t_window *window)
{
	int			i;
	int			j;
	double		x;
	double		y;
	t_ray		*ray;

	i = 0;
	j = 0;
	ft_bzero(window->image->pixels, WIDTH * HEIGHT * sizeof(int));
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			x = (double)i / (WIDTH - 1);
			y = (double)j / (HEIGHT - 1);
			ray = background(window->camera, x, y);
			draw_pixel(window, i, j, ray_color(ray));
			free(ray);
			j++;
		}
		j = 0;
		i++;
	}
}
