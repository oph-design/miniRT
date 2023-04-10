#include "minirt.h"

t_vector	add_clamp_d(double d, t_vector color, double min, double max)
{
	t_vector	res;

	res = add_double_vec(d, color);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}

t_vector	sub_clamp_d(double d, t_vector color, double min, double max)
{
	t_vector	res;

	res = sub_double_vec(d, color);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}

t_vector	mult_clamp_d(double d, t_vector color, double min, double max)
{
	t_vector	res;

	res = mult_double_vec(d, color);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}

t_vector	div_clamp_d(double d, t_vector color, double min, double max)
{
	t_vector	res;

	res = div_double_vec(d, color);
	res.x = clamp(res.x, min, max);
	res.y = clamp(res.y, min, max);
	res.z = clamp(res.z, min, max);
	return (res);
}
