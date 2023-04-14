#include "minirt.h"

int	hit_plane(t_object pl, t_ray ray, int *pos, double *t)
{
	double		div;
	double		tt;

	div = dot(ray.direction, pl.orientation);
	if (div == 0)
		return (0);
	tt = dot(sub_vec(pl.pos, ray.origin), pl.orientation) / div;
	if (tt <= 0)
		return (0);
	else if (*t > tt)
	{
		*t = tt;
		pos[INDEX_HIT] = pos[INDEX];
		return (1);
	}
	return (0);
}
