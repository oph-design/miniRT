#include "minirt.h"

static void	intersect_cylinder(t_object cy, t_ray ray, double *t)
{
	t_object	pl;

	hit_cylinder(cy, ray, NULL, t);
	pl = new_plane(cy.pos, cy.direct, cy.color);
	pl.radius = cy.radius;
	hit_disk(pl, ray, NULL, t);
	pl = new_plane(add_vec(cy.pos,
				mult_double_vec(cy.height, cy.direct)),
			cy.direct, cy.color);
	pl.radius = cy.radius;
	hit_disk(pl, ray, NULL, t);
}
static int	intercept_obj(t_map *map, t_hit hit, size_t i)
{
	t_vector	light_dir;
	t_ray	ray;
	double		t;

	t = INFINITY;
	light_dir = normalize(sub_vec(map->lighting->pos, hit.hitpoint));
	ray = new_ray(add_vec(mult_double_vec(ZERO, hit.normal),
					hit.hitpoint), light_dir);
	if (map->objects[i].type == SPHERE)
		hit_sphere(map->objects[i], ray, NULL, &t);
	if (map->objects[i].type == CYLINDER)
		intersect_cylinder(map->objects[i], ray, &t);
	if (t < INFINITY && t + ZERO > ZERO)
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
