#include "minirt.h"

int	hit_cone(t_object cn, t_ray ray, size_t *pos, double *t)
{
	t_vector	vals;
	t_vector	q;
	t_vector	d;
	double		a;
	double		tmp[3];

	d = normalize(ray.direct);
	q = sub_vec(ray.origin, cn.pos);
	a = pow(cn.radius / cn.height, 2);
	vals.x = dot(d, ray.direct) - pow(dot(cn.direct, d) / cn.height, 2) * a;
	vals.y = dot(q, d) - dot(q, cn.direct) * a;
	vals.z = dot(q, q) - pow(dot(q, cn.direct) / cn.height, 2) * a;
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

// a = atan(r / h)
// q = o - p
// x = p_x + t * v_x
// y = p_y + t * v_y
// z = p_z + t * v_z
// (x - p_x)^2 + (y - p_y)^2 = (z - p_z)^2 * (r / h)^2
// Substitute the parametric equation of the ray into the equation of the cone:

// b = 2 * (q . d) - 2 * (q . v) * (r / h)^2
// c = (q . q) - ((q . v) / h)^2 * r^2
// a = (d . d) - ((v . d) / h)^2 * r^2
// t1, t2 = (-b +/- sqrt(b^2 - 4ac)) / 2a
