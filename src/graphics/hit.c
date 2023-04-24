#include "minirt.h"
#include <stdio.h>

static t_hit	new_hit(t_object obj, t_ray ray, double t, int index)
{
	t_hit	new;

	new.obj = obj;
	new.cam_ray = ray;
	new.hitpoint = at(ray, t - ZERO);
	new.normal = get_object_normal(obj, new.hitpoint, ray, t);
	new.index = index;
	return (new);
}

// static void	hit_light(t_map *map, t_ray ray, double *t, size_t *pos)
// {
// 	while (pos[INDEX] < map->light_count)
// 	{
// 		hit_sphere(map->lighting[pos[INDEX]].obj, ray, pos, &t[LIGHT]);
// 		pos[INDEX]++;
// 	}
// 	pos[INDEX] = 0;
// 	pos[INDEX_HIT_LIGHT] = pos[INDEX_HIT];
// 	pos[INDEX_HIT] = 0;
// }

void	loop_objects(t_map *map, t_ray ray, double *t, size_t *pos)
{
	t_object	pl;
	t_object	cy;

	while (map->obj_count > pos[INDEX])
	{
		if (map->objects[pos[INDEX]].type == SPHERE)
			hit_sphere(map->objects[pos[INDEX]], ray, pos, t);
		else if (map->objects[pos[INDEX]].type == PLANE)
			hit_plane(map->objects[pos[INDEX]], ray, pos, t);
		if (map->objects[pos[INDEX]].type == CYLINDER)
		{
			cy = map->objects[pos[INDEX]];
			hit_cylinder(cy, ray, pos, t);
			pl = new_plane(cy.pos, cy.direct, cy.color);
			pl.radius = cy.radius;
			hit_disk(pl, ray, pos, t);
			pl = new_plane(add_vec(cy.pos,
						mult_double_vec(cy.height, cy.direct)),
					cy.direct, cy.color);
			pl.radius = cy.radius;
			hit_disk(pl, ray, pos, t);
		}
		pos[INDEX]++;
	}
}

t_vector	get_object_normal(t_object obj, t_vector hit, t_ray ray, double t)
{
	double	offset;

	if (obj.type == PLANE)
	{
		if (dot(obj.direct, mult_double_vec(-1, ray.direct)) < 0)
			return (normalize(mult_double_vec(-1, obj.direct)));
		return (normalize(obj.direct));
	}
	else if (obj.type == SPHERE)
		return (normalize(sub_vec(hit, obj.pos)));
	else if (obj.type == CYLINDER)
	{
		offset = dot(sub_vec(add_vec(ray.origin,
						mult_double_vec(t, ray.direct)), obj.pos), obj.direct);
		if (offset < ZERO && offset > -ZERO)
			return (normalize(mult_double_vec(-1, obj.direct)));
		if (offset + ZERO >= obj.height)
			return (normalize(obj.direct));
		return (normalize(sub_vec(sub_vec(hit, obj.pos),
					mult_double_vec(dot(sub_vec(hit, obj.pos),
							obj.direct), obj.direct))));
	}
	return (new_vec(0, 0, 0));
}

void	hit(t_map *map, int j, int i)
{
	double	x;
	double	y;
	size_t	pos[2];
	double	t;
	t_hit	hit;

	pos[INDEX] = 0;
	pos[INDEX_HIT] = 0;
	t = INFINITY;
	x = j / map->window->width;
	y = i / map->window->height;
	loop_objects(map, get_ray(map->camera, x, y), &t, pos);
	hit = new_hit(map->objects[pos[INDEX_HIT]], get_ray(map->camera, x, y),
			t, pos[INDEX_HIT]);
	if (t < INFINITY && t > ZERO)
		draw_pixel(map->window, j, i, vec_to_color(cast_light(map, hit)));
	else
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
}
