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

	ir = r * 0.999;
	ig = g * 0.999;
	ib = b * 0.999;
	ia = a * 0.999;
	return (ir << 24 | ig << 16 | ib << 8 | ia);
}

int	hit_sphere(t_object sp, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = subtract_vec(ray.origin, sp.pos);
	a = dot(ray.direction, ray.direction);
	b = 2.0 * dot(p, ray.direction);
	c = dot(p, p) - (sp.radius * sp.radius);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (0);
	else
		return (1);
}

void	draw(t_window *window)
{
	int			i;
	int			j;
	double		x;
	double		y;
	t_object	sp;

	i = 0;
	j = 0;
	sp = new_sphere(new_vec(0.0, 0.0, 20.0), 20, new_vec(255, 200, 200));
	ft_bzero(window->image->pixels, WIDTH * HEIGHT * sizeof(int));
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			x = (double)j / (WIDTH);
			y = (double)i / (HEIGHT);
			draw_pixel(window, j, i,
				ray_color(get_ray(window->camera, x, y), sp));
			j++;
		}
		j = 0;
		i++;
	}
}
