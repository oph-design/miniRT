#include "minirt.h"

double	sq_vec(t_vector vec)
{
	return (dot(vec, vec));
}
int	hit_cone(t_object cn, t_ray ray, size_t *pos, double *t)
{
	// t_vector	vals;
	// t_vector	p;
	// t_vector	B;

	(void)cn;
	(void)ray;
	(void)pos;
	(void)t;
	// p = sub_vec(cn.pos, ray.origin);
	// vals.x = ;
	// vals.y = ;
	// vals.z = ;
	// if (vals.y * vals.y - vals.x * vals.z < 0)
	// 	return (0);
	// tmp[0] = (-vals.y - sqrt(vals.y * vals.y - vals.x * vals.z) / (vals.x));
	// tmp[1] = (-vals.y + sqrt(vals.y * vals.y - vals.x * vals.z) / (vals.x));
	// tmp[2] = tmp[0];
	// if (tmp[2] < 0 || tmp[2] > tmp[1])
	// 	tmp[2] = tmp[1];
	// if (tmp[2] < 0 || tmp[2] > *t)
	// 	return (0);
	// *t = tmp[2];
	// if (pos)
	// 	pos[INDEX_HIT] = pos[INDEX];
	return (1);
}
