#include "objects.h"

t_object	new_sphere(t_vector pos, double r, t_vector color)
{
	t_object	new;

	new.type = sphere;
	new.pos = pos;
	new.radius = r;
	new.height = 0;
	new.color = color;
	return (new);
}

t_object	new_cylinder(t_vector pos, t_vector orientation,
	double *size, t_vector color)
{
	t_object	new;

	new.type = cylinder;
	new.pos = pos;
	new.radius = size[0];
	new.height = size[1];
	new.orientation = orientation;
	new.color = color;
	return (new);
}

t_object	new_plane(t_vector pos, t_vector orientation, t_vector color)
{
	t_object	new;

	new.type = plane;
	new.pos = pos;
	new.radius = 0;
	new.height = 0;
	new.orientation = orientation;
	new.color = color;
	return (new);
}
