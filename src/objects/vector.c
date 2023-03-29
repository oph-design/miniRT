#include "objects.h"

t_vector	*new_vec(double x, double y, double z)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
