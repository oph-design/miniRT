#include "minirt.h"

void	uv_plane(t_hit hit, double *uv)
{
	(void)hit;
	(void)uv;
}

void	uv_sphere(t_hit hit, double *uv)
{
	uv[0] = atan((pow(hit.hitpoint.x, 2) + pow(hit.hitpoint.y, 2))
			/ hit.hitpoint.z);
	uv[1] = atan(hit.hitpoint.y / hit.hitpoint.x);
	uv[0] /= M_PI;
	uv[1] /= M_PI;
}

double	*uv_space(t_hit hit)
{
	double	*uv;

	uv = malloc(sizeof(double) * 2);
	if (!uv)
		return (NULL);
	uv[2] = 0;
	if (hit.obj.type == SPHERE)
		uv_sphere(hit, uv);
	if (hit.obj.type == PLANE)
		uv_plane(hit, uv);
	return (uv);
}

// t_vector	checkeboard_plane(t_hit hit)
// {
// 	if (dot(hit.normal, new_vec(0, 0, 1)))
// 		if ((int)(floor(hit.hitpoint.x) + floor(hit.hitpoint.y)) % 2)
// 			return (new_vec(255, 255, 255));
// 	if (dot(hit.normal, new_vec(1, 0, 0)))
// 		if ((int)(floor(hit.hitpoint.z) + floor(hit.hitpoint.y)) % 2)
// 			return (new_vec(255, 255, 255));
// 	if (dot(hit.normal, new_vec(0, 1, 0)))
// 		if ((int)(floor(hit.hitpoint.x) + floor(hit.hitpoint.z)) % 2)
// 			return (new_vec(255, 255, 255));
// 	return (hit.obj.color);
// }
