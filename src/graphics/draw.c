#include "minirt.h"

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		mlx_put_pixel(window->image, x, y, color);
}

uint32_t	color(int r, int g, int b, int a)
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

void	draw(t_window *window)
{
	int			i;
	int			j;
	double		x;
	double		y;
	t_sphere	*sp;

	i = 0;
	j = 0;
	sp = new_sphere(new_vec(0.0, 0.0, -3.0), 0.5);
	ft_bzero(window->image->pixels, WIDTH * HEIGHT * sizeof(int));
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			x = (double)i / (WIDTH - 1);
			y = (double)j / (HEIGHT - 1);
			draw_pixel(window, i, j,
				ray_color(get_ray(window->camera, x, y), sp));
			j++;
		}
		j = 0;
		i++;
	}
	free_sphere(sp);
}
