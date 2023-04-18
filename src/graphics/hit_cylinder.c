#include "minirt.h"

double	check_root_cy(double *t, t_vector var)
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

t_vector	calc_var(t_ray ray, t_object cy)
{
	t_vector	var;
	t_vector	q;
	t_vector	d_proj;

	q = sub_vec(ray.origin, cy.pos);
	d_proj = sub_vec(ray.direction,
			mult_double_vec(dot(ray.direction, cy.orientation),
				cy.orientation));
	q = sub_vec(q, mult_double_vec(dot(q, cy.orientation), cy.orientation));
	var.x = vec_length_squared(d_proj);
	var.y = dot(d_proj, q);
	var.z = vec_length_squared(q) - pow(cy.radius, 2);
	return (var);
}

int	hit_cylinder(t_object cy, t_ray ray, size_t *pos, double *t)
{
	t_vector	var;
	double		tmp;
	t_vector	x;

	tmp = *t;
	var = calc_var(ray, cy);
	if (var.y * var.y - var.x * var.z < 0)
		return (0);
	else
	{
		*t = check_root_cy(t, var);
		if (*t != tmp)
		{
			x = add_vec(ray.origin, mult_double_vec(*t, ray.direction));
			if (dot(sub_vec(x, cy.pos), cy.orientation) < cy.height
				&& dot(sub_vec(x, cy.pos), cy.orientation) > 0)
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

int	check_radius(double t, t_ray ray, t_object pl)
{
	t_vector	pos;
	double		len;

	pos = add_vec(ray.origin, mult_double_vec(t, ray.direction));
	len = sqrt(vec_length_squared(sub_vec(pl.pos, pos)));
	if (len >= (pl.radius))
		return (0);
	return (1);
}

int	hit_disk(t_object pl, t_ray ray, size_t *pos, double *t)
{
	double		div;
	double		tt;

	div = dot(ray.direction, pl.orientation);
	if (div == 0)
		return (0);
	tt = dot(sub_vec(pl.pos, ray.origin), pl.orientation) / div;
	if (tt <= 0)
		return (0);
	else if ((!t || *t > tt) && check_radius(tt, ray, pl))
	{
		if (t)
			*t = tt;
		if (pos)
			pos[INDEX_HIT] = pos[INDEX];
		return (1);
	}
	return (0);
}
