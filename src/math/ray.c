#include "minirt.h"

t_ray	*new_ray(t_vector origin, t_vector direction)
{
	t_ray	*new;

	new = malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->origin = &origin;
	new->direction = &direction;
	return (new);
}

uint32_t	ray_color(t_ray	*ray)
{
	double		t;
	t_vector	*co1;
	t_vector	*co2;
	t_vector	color;

	co1 = new_vec(1.0, 1.0, 1.0);
	co2 = new_vec(0.5, 0.7, 1.0);
	t = 0.5 * ray->direction->y + 1.0;
	color = add_to_vec(mult_double_vec(1.0 - t, *co1),
			mult_double_vec(t, *co2));
	return (pixel(color.x, color.y, color.z, 0xFF));
}
