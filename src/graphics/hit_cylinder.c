#include "minirt.h"

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
		return (0);
	if (r < 0)
		return (0);
	return (1);
}

t_vector	calculate_h(t_ray ray, t_vector base, t_object cy)
{
	t_vector	h;
	t_vector	p;

	p = sub_vec(ray.origin, base);
	h.x = dot(ray.direction, ray.direction)
		- pow(dot(ray.direction, cy.orientation), 2);
	h.y = (dot(ray.direction, p) - (dot(ray.direction, cy.orientation)
				* dot(p, cy.orientation))) * 2;
	h.z = dot(p, p) - pow(dot(p, cy.orientation), 2) - pow(cy.radius, 2);
	return (h);
}

int	hit_cylinder(t_object cy, t_ray ray, size_t *pos, double *t)
{
	t_vector	h;
	double		disc;

	h = calculate_h(ray, add_vec(cy.pos,
				add_double_vec(cy.height / 2, cy.orientation)), cy);
	disc = (h.y * h.y) - 4 * h.x * h.z;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0 && *t > (-h.y / 2 * h.x)
			&& is_in_cylinder(cy, ray, -h.y / 2 * h.x))
		{
			*t = -h.y / 2 * h.x;
			pos[INDEX_HIT] = pos[INDEX];
		}
		else
		{
			if (!is_in_cylinder(cy, ray, check_root(t, h, pos)))
				return (1);
			*t = check_root(t, h, pos);
		}
		return (1);
	}
}
