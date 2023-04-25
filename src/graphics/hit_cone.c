#include "minirt.h"

static double	check_root_cn(double *t, t_vector var)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(var.y * var.y - 4 * var.x * var.z);
	to = (-var.y + disc) / 2 * var.x;
	tl = (-var.y - disc) / 2 * var.x;
	if (to < tl && *t > to)
		return (to);
	else if (*t > tl)
		return (tl);
	return (*t);
}

static t_vector	calc_var(t_ray ray, t_object cn)
{
	double		m;
	t_vector	w;
	t_vector	var;
	t_vector	theta;
	double		d1;
	double		d2;

	theta = normalize(cn.direct);
	m = pow(cn.radius, 2) / pow(cn.height, 2);
	w = sub_vec(ray.origin, cn.pos);
	d1 = dot(ray.direct, theta);
	d2 = dot(w, theta);
	var.x = pow(d1, 2);
	var.x = dot(ray.direct, ray.direct) - m * var.x - var.x;
	var.y = 2 * (dot(ray.direct, w) - m * d1 * d2 - d1 * d2);
	var.z = dot(w, w) - m * pow(d2, 2) - pow (d2, 2);
	return (var);
}

int	hit_cone(t_object cn, t_ray ray, size_t *pos, double *t)
{
	t_vector	var;
	var = calc_var(ray, cn);
	if (var.y * var.y - 4 * var.x * var.z < 0)
		return (0);
	else
	{
		*t = check_root_cn(t, var);
		if (*t > ZERO && *t < INFINITY)
			pos[INDEX_HIT] = pos[INDEX];
	}
	return (0);
}
