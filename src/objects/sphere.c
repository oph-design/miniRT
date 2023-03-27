#include "objects.h"

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
