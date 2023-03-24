#include "minirt.h"

t_vector	add_to_vec(t_vector vec, t_vector add)
{
	vec.x += add.x;
	vec.y += add.y;
	vec.z += add.z;
	return (vec);
}

t_vector	subtract_vec(t_vector vec, t_vector sub)
{
	vec.x -= sub.x;
	vec.y -= sub.y;
	vec.z -= sub.z;
	return (vec);
}

t_vector	*multiply_vec(t_vector *vec, t_vector *m)
{
	vec->x *= m->x;
	vec->y *= m->y;
	vec->z *= m->z;
	return (vec);
}
