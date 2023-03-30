#include "objects.h"

t_vector	new_vec_stack(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector	*new_vec(double x, double y, double z)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
