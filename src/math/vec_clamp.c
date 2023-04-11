#include "minirt.h"

t_vector	mult_clamp(t_vector a, t_vector b, double min, double max)
{
	t_vector	res;

	res = mult_vec(a, b);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}

t_vector	div_clamp(t_vector a, t_vector b, double min, double max)
{
	t_vector	res;

	res = div_vec(a, b);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}

t_vector	add_clamp(t_vector a, t_vector b, double min, double max)
{
	t_vector	res;

	res = add_vec(a, b);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}

t_vector	sub_clamp(t_vector a, t_vector b, double min, double max)
{
	t_vector	res;

	res = sub_vec(a, b);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}
