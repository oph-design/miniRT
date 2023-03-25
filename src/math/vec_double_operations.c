#include "minirt.h"

t_vector	mult_double_vec(double d, t_vector vec)
{
	vec.x *= d;
	vec.y *= d;
	vec.z *= d;
	return (vec);
}

t_vector	add_double_vec(double d, t_vector vec)
{
	vec.x += d;
	vec.y += d;
	vec.z += d;
	return (vec);
}

t_vector	sub_double_vec(double d, t_vector vec)
{
	vec.x -= d;
	vec.y -= d;
	vec.z -= d;
	return (vec);
}
