#include "minirt.h"

static double	check_root_cy(double *t, t_vector var)
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
	t_vector	var;
	t_vector	q;
	double		d;

	q = sub_vec(ray.origin, cn.pos);
	d = pow(cos(atan(cn.radius / cn.height)), 2);
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
			x = add_vec(ray.origin, mult_double_vec(*t, ray.direct));
			if (dot(sub_vec(x, cy.pos), cy.direct) < cy.height
				&& dot(sub_vec(x, cy.pos), cy.direct) > 0)
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
