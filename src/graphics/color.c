#include "minirt.h"

uint32_t	write_color(double r, double g, double b, double a)
{
	int	ir;
	int	ig;
	int	ib;
	int	ia;

	ir = r * 0.999;
	ig = g * 0.999;
	ib = b * 0.999;
	ia = a * 0.999;
	return (ir << 24 | ig << 16 | ib << 8 | ia);
}

uint32_t	vec_to_color(t_vector vec)
{
	return (write_color(vec.x, vec.y, vec.z, 255.0));
}

t_vector	color_to_ratio(t_vector color)
{
	color.x /= 255.0;
	color.y /= 255.0;
	color.z /= 255.0;
	return (color);
}
