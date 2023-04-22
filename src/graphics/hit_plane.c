#include "minirt.h"

int	hit_plane(t_object pl, t_ray ray, size_t *pos, double *t)
{
	double		div;
	double		tt;

	div = dot(ray.direct, pl.direct);
	if (div == 0)
		return (0);
	tt = dot(sub_vec(pl.pos, ray.origin), pl.direct) / div;
	if (tt <= 0)
		return (0);
	else if (!t || *t > tt)
	{
		if (t)
			*t = tt;
		if (pos)
			pos[INDEX_HIT] = pos[INDEX];
		return (1);
	}
	return (0);
}

int	check_radius(double t, t_ray ray, t_object pl)
{
	t_vector	pos;
	double		len;

	pos = add_vec(ray.origin, mult_double_vec(t, ray.direct));
	len = sqrt(vec_length_squared(sub_vec(pl.pos, pos)));
	if (len >= (pl.radius))
		return (0);
	return (1);
}

int	hit_disk(t_object pl, t_ray ray, size_t *pos, double *t)
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
