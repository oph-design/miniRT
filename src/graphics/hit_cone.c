#include "minirt.h"

static int	check_radius(double t, t_ray ray, t_object pl)
{
	t_vector	i_pos;
	double		len;

	i_pos = add_vec(ray.origin, mult_double_vec(t, ray.direct));
	//pl_dir = cross_product(pl.direct, (t_vector){0, 1, 0});
	len = sqrt(vec_length_squared(sub_vec(pl.pos, i_pos)));
	if (i_pos.x > pl.pos.x + pl.radius || i_pos.x < pl.pos.x - pl.radius)
		return (0);
	if (i_pos.y > pl.pos.y + pl.radius || i_pos.y < pl.pos.y - pl.radius)
		return (0);
	if (i_pos.z > pl.pos.z + pl.radius || i_pos.z < pl.pos.z - pl.radius)
		return (0);
	return (1);
}

int	hit_cube(t_object pl, t_ray ray, size_t *pos, double *t)
{
	double		div;
	double		tt;

	div = dot(ray.direct, pl.direct);
	if (div == 0)
		return (0);
	tt = dot(sub_vec(pl.pos, ray.origin), pl.direct) / div;
	if (tt <= 0)
		return (0);
	else if ((!t || *t > tt) && check_radius(tt, ray, pl))
	{
		if (t)
			*t = tt;
		if (pos)
			pos[INDEX_HIT] = pos[INDEX];
		return (1);
	}
	return (0);
}
