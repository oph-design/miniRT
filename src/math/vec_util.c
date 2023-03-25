#include "minirt.h"

double	dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.x * a.y);
}

t_vector	normalize(t_vector vec)
{
	double	length;

	length = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	vec.x = vec.x / length;
	vec.y = vec.y / length;
	vec.z = vec.z / length;
	return (vec);
}

t_vector	*cross_product(t_vector *vec, t_vector *cross)
{
	t_vector	*new;

	new = new_vec(vec->y * cross->z - vec->z * cross->y,
			vec->z * cross->x - vec->x * cross->z,
			vec->x * cross->y - vec->y * cross->z);
	return (new);
}