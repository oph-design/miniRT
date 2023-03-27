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

t_ray	*ray_cast(t_camera *camera, double x, double y)
{
	t_vector	dest;
	t_vector	nx;
	t_vector	ny;

	nx = mult_double_vec(x, *camera->horizontal);
	ny = mult_double_vec(y, *camera->vertical);
	dest = subtract_vec(add_to_vec(add_to_vec(*camera->orientation, nx), ny),
			*camera->pos);
	return (new_ray(*camera->pos, dest));
}

double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = subtract_vec(*ray->origin, *sp->center);
	a = dot(*ray->direction, *ray->direction);
	b = 2.0 * dot(p, *ray->direction);
	c = dot(p, p) - (sp->radius * sp->radius);
	disc = (b * b) - (4 * a * c);
	if (disc > 0)
		return (-1.0);
	else
		return (((-1 * b) - sqrt(disc)) / (2.0 * a));
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
	sp = new_sphere(new_vec(0.0, 0.0, -1.0), 0.5);
	ft_bzero(window->image->pixels, WIDTH * HEIGHT * sizeof(int));
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			x = (double)i / (WIDTH - 1);
			y = (double)j / (HEIGHT - 1);
			draw_pixel(window, i, j,
				ray_color(ray_cast(window->camera, x, y), sp));
			j++;
		}
		j = 0;
		i++;
	}
	free_sphere(sp);
}
