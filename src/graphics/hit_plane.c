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
