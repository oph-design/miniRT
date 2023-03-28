#include "minirt.h"

int	hit_sphere(t_sphere *sp, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = subtract_vec(*ray->origin, *sp->center);
	a = dot(*ray->direction, *ray->direction);
	b = 2 * dot(p, *ray->direction);
	c = dot(p, p) - (sp->radius * sp->radius);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (0);
	else
		return (1);
}
// disc = -b - sqrt(b * b - 4 * a * c) / (2 * a);

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
