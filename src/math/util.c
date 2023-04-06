#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	return (x);
}

uint32_t	sample_color(t_vector col, int sample_per_pixel)
{
	double	r;
	double	g;
	double	b;
	double	scale;

	scale = 255.0 / sample_per_pixel;
	r = col.x * scale;
	g = col.y * scale;
	b = col.z * scale;
	return (color(clamp(r, 0.0, 255.0), clamp(g, 0.0, 255.0),
			clamp(b, 0.0, 255.0), 255.0));
}
