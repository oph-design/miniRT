#include "minirt.h"

static void	check_for_negative(double *t, double *tmp)
{
	if (*t < ZERO)
		*t = *tmp;
	*tmp = *t;
}

static void	intersect_cylinder(t_object cy, t_ray ray, double *t)
{
	t_object	pl;
	double		tmp;

	tmp = *t;
	hit_cylinder(cy, ray, NULL, t);
	check_for_negative(t, &tmp);
	pl = new_plane(cy.pos, cy.direct, cy.color);
	pl.radius = cy.radius;
	hit_disk(pl, ray, NULL, t);
	check_for_negative(t, &tmp);
	pl = new_plane(add_vec(cy.pos,
				mult_double_vec(cy.height, cy.direct)),
			cy.direct, cy.color);
	pl.radius = cy.radius;
	hit_disk(pl, ray, NULL, t);
	if (*t < ZERO)
		*t = tmp;
	check_for_negative(t, &tmp);
}

static int	is_in_front(t_vector light_dir, t_ray light_ray, double t)
{
	double	source_length;
	double	hit_length;

	source_length = vec_length_squared(light_dir);
	hit_length = vec_length_squared(sub_vec(light_ray.origin,
				at(light_ray, t)));
	if (source_length > hit_length)
		return (1);
	return (0);
}

static int	intercept_obj(t_map *map, t_hit hit, size_t i)
{
	t_vector	light_dir;
	t_ray		ray;
	t_ray		light_ray;
	double		t;

	t = INFINITY;
	light_dir = sub_vec(map->lighting->pos, hit.hitpoint);
	light_ray = new_ray(hit.hitpoint, light_dir);
	ray = new_ray(add_vec(mult_double_vec(ZERO, hit.normal),
				hit.hitpoint), light_dir);
	if (map->objects[i].type == SPHERE)
		hit_sphere(map->objects[i], ray, NULL, &t);
	if (map->objects[i].type == CYLINDER)
		intersect_cylinder(map->objects[i], ray, &t);
	if (map->objects[i].type == PLANE)
		hit_plane(map->objects[i], ray, NULL, &t);
	if (t < INFINITY && t + ZERO > ZERO
		&& is_in_front(light_dir, light_ray, t))
		return (1);
	return (0);
}

int	is_shaded(t_map *map, t_hit hit)
{
	size_t	i;

	i = 0;
	while (map->obj_count > i && !intercept_obj(map, hit, i))
		i++;
	if (i != map->obj_count)
		return (1);
	return (0);
}
