#include "minirt.h"

static t_hit	new_hit(t_object obj, t_ray ray, double t, int index)
{
	t_hit	new;

	new.obj = obj;
	new.cam_ray = ray;
	new.hitpoint = at(ray, t);
	new.normal = get_object_normal(obj, new.hitpoint);
	new.index = index;
	return (new);
}

static void	loop_objects(t_map *map, t_ray ray, double *t, size_t *pos)
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
			pl = new_plane(cy.pos, cy.orientation, cy.color);
			pl.radius = cy.radius;
			hit_disk(pl, ray, pos, t);
			pl = new_plane(add_vec(cy.pos,
				mult_double_vec(cy.height, cy.orientation)), cy.orientation, cy.color);
			pl.radius = cy.radius;
			hit_disk(pl, ray, pos, t);
		}
		pos[INDEX]++;
	}
}

t_vector	get_object_normal(t_object obj, t_vector hit)
{
	if (obj.type == PLANE)
	{
		obj.pos.x *= -1;
		obj.pos.y *= -1;
		obj.pos.z *= -1;
		return (normalize(obj.pos));
	}
	else if (obj.type == SPHERE)
		return (normalize(sub_vec(hit, obj.pos)));
	else if (obj.type == CYLINDER)
		return (normalize(sub_vec(sub_vec(hit, obj.pos),
					mult_double_vec(dot(sub_vec(hit, obj.pos),
							obj.orientation), obj.orientation))));
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
