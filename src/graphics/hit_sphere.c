#include "minirt.h"

static double	check_root(double *t, t_vector var, int *pos)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(var.y * var.y - 4 * var.x * var.z);
	to = (-var.y + disc) / 2;
	tl = (-var.y - disc) / 2;
	if (to < tl && *t + ZERO > to)
	{
		pos[INDEX_HIT] = pos[INDEX];
		return (to);
	}
	else if (*t + ZERO > tl)
	{
		pos[INDEX_HIT] = pos[INDEX];
		return (tl);
	}
	return (*t);
}

int	hit_sphere(t_object sp, t_ray ray, int *pos, double *t)
{
	t_vector	var;
	double		disc;
	t_vector	p;

	p = sub_vec(ray.origin, sp.pos);
	var.x = vec_length_squared(ray.direction);
	var.y = 2 * dot(p, ray.direction);
	var.z = vec_length_squared(p) - (sp.radius * sp.radius);
	disc = (var.y * var.y) - 4 * var.x * var.z;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0 && *t + ZERO > (-var.y / 2 * var.x))
		{
			*t = -var.y / 2 * var.x;
			pos[INDEX_HIT] = pos[INDEX];
		}
		else
			*t = check_root(t, var, pos);
		return (1);
	}
}

int	check_t(double to, double tl)
{
	if (to > ZERO || tl > ZERO)
		return (1);
	if (to > tl && tl > ZERO)
		return (1);
	if (tl > to && to > ZERO)
		return (1);
	return (0);
}

int	intercept_sphere(t_object sp, t_ray ray)
{
	t_vector	var;
	double		disc;
	t_vector	p;
	double		to;
	double		tl;

	p = sub_vec(ray.origin, sp.pos);
	var.x = vec_length_squared(ray.direction);
	var.y = 2 * dot(p, ray.direction);
	var.z = vec_length_squared(p) - (sp.radius * sp.radius);
	disc = (var.y * var.y) - 4 * var.x * var.z;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0)
			return (1);
		to = (-var.y + disc) / 2;
		tl = (-var.y - disc) / 2;
		return (check_t(to, tl));
	}
	return (0);
}
