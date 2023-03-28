#include "objects.h"

t_object	new_sphere(t_vector *pos, double r, u_int32_t color)
{
	t_object	new;

	new.type = sphere;
	new.pos = pos;
	new.radius = r;
	new.height = 0;
	new.orientation = NULL;
	new.color = color;
	return (new);
}