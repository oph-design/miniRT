#include "minirt.h"

int	hit_sphere(t_sphere *sp, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = subtract_vec(*ray->origin, *sp->center);
	a = vec_length_squared(p);
	b = 2 * p.x * (ray->origin->x - sp->center->x)
		+ 2 * p.y *(ray->origin->y - sp->center->y)
		+ 2 * p.z *(ray->origin->z - sp->center->z);
	c = vec_length_squared(*sp->center) + vec_length_squared(*ray->origin)
		+ -2 * (sp->center->x * ray->origin->x + sp->center->y * ray->origin->y
			+ sp->center->z * ray->origin->z)
		- (sp->radius * sp->radius);
	disc = b * 2 - 4 * a * c;
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
