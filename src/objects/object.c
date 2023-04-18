#include "objects.h"

t_object	new_sphere(t_vector pos, double r, t_vector color)
{
	t_object	new;

	new.type = SPHERE;
	new.pos = pos;
	new.radius = r / 2.0;
	new.height = 0;
	new.color = color;
	return (new);
}

t_object	new_cylinder(t_vector pos, t_vector orientation,
	double *size, t_vector color)
{
	t_object	new;

	new.type = CYLINDER;
	new.pos = pos;
	new.radius = size[0] / 2;
	new.height = size[1];
	new.orientation = orientation;
	new.pos = sub_vec(new.pos,
			mult_double_vec(new.height / 2, new.orientation));
	new.color = color;
	return (new);
}

t_object	new_plane(t_vector pos, t_vector orientation, t_vector color)
{
	t_object	new;

	new.type = PLANE;
	new.pos = pos;
	new.radius = 0;
	new.height = 0;
	new.orientation = orientation;
	new.color = color;
	return (new);
}
