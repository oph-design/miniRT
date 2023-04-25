#include "minirt.h"

static double	check_root_cn(double *t, t_vector var)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(var.y * var.y - var.x * var.z);
	to = (-var.y + disc) / var.x;
	tl = (-var.y - disc) / var.x;
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
	double		d1;
	double		d2;

	m = pow(cn.radius, 2) / pow(cn.height, 2);
	w = sub_vec(ray.origin, cn.pos);
	d1 = dot(ray.direct, cn.direct);
	d2 = dot(w, cn.direct);
	var.x = pow(d1, 2);
	var.x = dot(ray.direct, ray.direct) - m * var.x - var.x;
	var.y = (dot(ray.direct, w) - m * d1 * d2 - d1 * d2);
	var.z = dot(w, w) - m * pow(d2, 2) - pow (d2, 2);
	return (var);
}

static int	hit_cone(t_object cn, t_ray ray, size_t *pos, double *t)
{
	t_vector	var;
	t_vector	x;
	double		tmp;

	tmp = *t;
	var = calc_var(ray, cn);
	if (var.y * var.y - var.x * var.z < 0)
		return (0);
	else
	{
		*t = check_root_cn(t, var);
		if (*t != tmp)
		{
			x = add_vec(ray.origin, mult_double_vec(*t, ray.direct));
			if (dot(sub_vec(x, cn.pos), cn.direct) < cn.height
				&& dot(sub_vec(x, cn.pos), cn.direct) >= 0)
			{
				if (pos)
					pos[INDEX_HIT] = pos[INDEX];
				return (1);
			}
			*t = tmp;
		}
	}
	return (0);
}

static void	check_for_negative(double *t, double *tmp)
{
	if (*t + ZERO < ZERO)
		*t = *tmp;
	*tmp = *t;
}

void	cone_helper(t_object cn, t_ray ray, size_t *pos, double *t)
{
	t_object	pl;
	double		tmp;

	hit_cone(cn, ray, pos, t);
	if (pos == NULL)
		check_for_negative(t, &tmp);
	pl = new_plane(add_vec(cn.pos,
				mult_double_vec(cn.height, cn.direct)),
			cn.direct, cn.color);
	pl.radius = cn.radius;
	hit_disk(pl, ray, pos, t);
	if (pos == NULL)
		check_for_negative(t, &tmp);
}
