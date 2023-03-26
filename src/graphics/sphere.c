#include "minirt.h"
#include <stdio.h>

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

t_sphere	*new_sphere(t_vector *pos, double r)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	new->center = pos;
	new->radius = r;
	return (new);
}

void	free_sphere(t_sphere *sp)
{
	free(sp->center);
	free(sp);
}
