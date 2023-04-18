#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	return (x);
}

double	degrees(t_vector nrml, t_vector light_dir)
{
	double		tmp;
	double		tmp2;
	double		tmp3;

	tmp = dot(nrml, light_dir);
	tmp2 = sqrt(vec_length_squared(nrml));
	tmp3 = sqrt(vec_length_squared(light_dir));
	return (acos(tmp / (tmp2 * tmp3)) * 180.0 / M_PI);
}
