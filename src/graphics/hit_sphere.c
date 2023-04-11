#include "minirt.h"

static void	check_root(double *t, double a, double b, double c)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(b * b - 4 * a * c);
	to = (-b + disc) / 2;
	tl = (-b - disc) / 2;
	if (to < tl && *t > to)
		*t = to;
	else if (*t > tl)
		*t = tl;
}

int	hit_sphere(t_object sp, t_ray ray, int *pos, double *t)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = sub_vec(ray.origin, sp.pos);
	a = vec_length_squared(ray.direction);
	b = 2 * dot(p, ray.direction);
	c = vec_length_squared(p) - (sp.radius * sp.radius);
	disc = (b * b) - 4 * a * c;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0 && *t > (-b / 2 * a))
			*t = -b / 2 * a;
		else
			check_root(t, a, b, c);
		pos[0] = pos[1];
		return (1);
	}
}
