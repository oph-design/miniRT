#include "minirt.h"

int	hit_cone(t_object cn, t_ray ray, size_t *pos, double *t)
{
	t_vector	vals;
	t_vector	p;
	t_vector	d_proj;
	double		k;
	double		tmp[3];

	p = sub_vec(ray.origin, cn.pos);
	d_proj = sub_vec(ray.direct, mult_double_vec(dot(cn.direct, ray.direct), cn.direct));
	k = pow(atan(cn.radius / cn.height) / 2, 2);
	vals.x = 	dot(d_proj, d_proj)
				- (1 + k * pow(dot(ray.direct, cn.direct), 2));
	vals.y = 	dot(d_proj, sub_vec(p, mult_double_vec(dot(p, cn.direct), cn.direct)))
				- (1 + k * dot(ray.direct, cn.direct) * dot(sub_vec(p, cn.pos), cn.direct));
	vals.z = 	dot(sub_vec(p, cn.pos), sub_vec(p, sub_vec(cn.pos, sub_double_vec(tan(atan(cn.radius / cn.height) / 2) * cn.height, cn.direct))))
				- (1 + k * pow(dot(sub_vec(p, cn.pos), cn.direct), 2));
	if (vals.y * vals.y - vals.x * vals.z < 0)
		return (0);
	tmp[0] = (-vals.y - sqrt(vals.y * vals.y - vals.x * vals.z) / (vals.x));
	tmp[1] = (-vals.y + sqrt(vals.y * vals.y - vals.x * vals.z) / (vals.x));
	tmp[2] = tmp[0];
	if (tmp[2] < 0 || tmp[2] > tmp[1])
		tmp[2] = tmp[1];
	if (tmp[2] < 0 || tmp[2] > *t)
		return (0);
	*t = tmp[2];
	if (pos)
		pos[INDEX_HIT] = pos[INDEX];
	return (1);
}

// q = p - c
// d_proj = d - dot(d, a) * a
// k = tan(theta/2) * h
// A = dot(d_proj, d_proj) - (1 + tan(theta/2) * tan(theta/2)) * dot(d, a) * dot(d, a)
// B = 2 * (dot(d_proj, q - dot(q, a) * a) - (1 + tan(theta/2) * tan(theta/2)) * dot(d, a) * dot(q - c, a))
// C = dot(q - c, q - c - k * a) - (1 + tan(theta/2) * tan(theta/2)) * dot(q - c, a) * dot(q - c, a)
