#include "objects.h"

t_object	new_light(t_vector pos, double r, t_vector color)
{
	t_object	new;

	new.type = LIGHT;
	new.pos = pos;
	new.radius = r / 2.0;
	new.height = 0;
	new.color = color;
	return (new);
}

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

t_object	new_cylinder(t_vector pos, t_vector direct,
			double *size, t_vector color)
{
	t_object	new;

	new.type = CYLINDER;
	new.pos = pos;
	new.radius = size[0] / 2.0;
	new.height = size[1];
	new.direct = normalize(direct);
	new.pos = sub_vec(new.pos,
			mult_double_vec(new.height / 2.0, new.direct));
	new.color = color;
	return (new);
}

t_object	new_cube(t_vector pos, t_vector direct,
			double size, t_vector color)
{
	t_object	cone;

	cone = new_plane(pos, direct, color);
	cone.radius = size / 2;
	cone.type = CUBE;
	return (cone);
}

t_object	new_plane(t_vector pos, t_vector direct, t_vector color)
{
	t_object	new;

	new.type = PLANE;
	new.pos = pos;
	new.radius = 0;
	new.height = 0;
	new.direct = direct;
	new.color = color;
	return (new);
}
