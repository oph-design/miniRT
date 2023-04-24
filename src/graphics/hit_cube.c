#include "minirt.h"

static int	check_radius(double t, t_ray ray, t_object pl)
{
	t_vector	pos;

	pos = add_vec(ray.origin, mult_double_vec(t, ray.direct));
	if (pos.x > pl.pos.x + pl.radius / 2 || pos.x < pl.pos.x - pl.radius / 2)
		return (0);
	if (pos.y > pl.pos.y + pl.radius / 2 || pos.y < pl.pos.y - pl.radius / 2)
		return (0);
	if (pos.z > pl.pos.z + pl.radius / 2 || pos.z < pl.pos.z - pl.radius / 2)
		return (0);
	return (1);
}

int	hit_square(t_object pl, t_ray ray, size_t *pos, double *t)
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

t_object	calc_side(t_vector dir, t_object pl, int sign)
{
	t_vector	side_pos;
	t_vector	len_vec;
	double		len;

	if (sign == -1)
		dir = mult_double_vec(-1, dir);
	len = sqrt(pow(pl.radius / 2, 2) + pow(pl.radius / 2, 2));
	len_vec = normalize(add_vec(pl.direct, dir));
	side_pos = add_vec(pl.pos, mult_double_vec(len, len_vec));
	return (new_cube(side_pos, dir, pl.radius, pl.color));
}

int hit_cube(t_object pl, t_ray ray, size_t *pos, double *t)
{
	t_object	side;
	t_vector	dir_x;
	t_vector	dir_y;

	dir_x = cross_product(pl.direct, (t_vector){0, 1, 0});
	dir_y = cross_product(pl.direct, (t_vector){1, 0, 0});
	hit_square(pl, ray, pos, t);
	side = calc_side(dir_x, pl, 1);
	hit_square(side, ray, pos, t);
	side = calc_side(dir_x, pl, -1);
	hit_square(side, ray, pos, t);
	side = calc_side(dir_y, pl, 1);
	hit_square(side, ray, pos, t);
	side = calc_side(dir_y, pl, -1);
	hit_square(side, ray, pos, t);
	side = new_cube(add_vec(pl.pos, mult_double_vec(pl.radius, pl.direct)),
				pl.direct, pl.radius, pl.color);
	hit_square(side, ray, pos, t);
	return (1);
}
