#include "minirt.h"
#include <stdio.h>

static double	check_root(double *t, t_vector h, int *pos)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(h.y * h.y - 4 * h.x * h.z);
	to = (-h.y + disc) / 2;
	tl = (-h.y - disc) / 2;
	if (to < tl && *t > to)
	{
		pos[INDEX_HIT] = pos[INDEX];
		return (to);
	}
	else if (*t > tl)
	{
		pos[INDEX_HIT] = pos[INDEX];
		return (tl);
	}
	return (*t);
}

int	hit_sphere(t_object sp, t_ray ray, int *pos, double *t)
{
	t_vector	h;
	double		disc;
	t_vector	p;

	p = sub_vec(ray.origin, sp.pos);
	h.x = vec_length_squared(ray.direction);
	h.y = 2 * dot(p, ray.direction);
	h.z = vec_length_squared(p) - (sp.radius * sp.radius);
	disc = (h.y * h.y) - 4 * h.x * h.z;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0 && *t > (-h.y / 2 * h.x))
		{
			*t = -h.y / 2 * h.x;
			pos[INDEX_HIT] = pos[INDEX];
		}
		else
			*t = check_root(t, h, pos);
		return (1);
	}
}

int	is_in_cylinder(t_object cy, t_ray ray, double t)
{
	t_vector	a;
	t_vector	b;
	t_vector	hit;
	double		r;

	hit = add_vec(ray.origin, mult_double_vec(t, ray.direction));
	a = mult_double_vec(-1, mult_vec(cy.pos, cy.orientation));
	a = add_vec(a, mult_vec(hit, cy.orientation));
	b = mult_vec(cy.orientation, cy.orientation);
	r = (a.x + a.y + a.z) / (b.x + b.y + b.z);
	if (r > (cy.height / 2))
		return (printf("r = %f\n", r), 0);
	return (1);
}

int	hit_cylinder(t_object cy, t_ray ray, int *pos, double *t)
{
	t_vector	h;
	double		disc;
	t_vector	p;
	t_vector	base;

	base = add_vec(cy.pos, add_double_vec(cy.height / 2, cy.orientation));
	if (!is_in_cylinder(cy, ray, *t))
		return (*t = INFINITY, 0);
	p = sub_vec(ray.origin, base);
	h.x = dot(ray.direction, ray.direction) - pow(dot(ray.direction, cy.orientation), 2);
	h.y = (dot(ray.direction, p) - (dot(ray.direction, cy.orientation) * dot(p, cy.orientation))) * 2;
	h.z = dot(p, p) - pow(dot(p, cy.orientation), 2) - pow(cy.radius, 2);
	disc = (h.y * h.y) - 4 * h.x * h.z;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0 && *t > (-h.y / 2 * h.x))
		{
			*t = -h.y / 2 * h.x;
			pos[INDEX_HIT] = pos[INDEX];
		}
		else
			*t = check_root(t, h, pos);
		return (1);
	}
}
