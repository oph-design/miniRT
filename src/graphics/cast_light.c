#include "minirt.h"

t_vector	cast_light(t_map *map, int pos, t_vector hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	dir;
	t_vector	light_dir;
	double		radiant;

	ambient = mult_double_vec(map->lighting->a_ratio, map->lighting->a_color);
	light = mult_double_vec(map->lighting->l_ratio, map->lighting->l_color);
	light_dir = normalize(sub_vec(map->lighting->pos, hit));
	dir = normalize(sub_vec(hit, map->objects[pos].pos));
	radiant = dot(light_dir, dir);
	ambient = mult_clamp_d(map->lighting->a_ratio, map->objects[pos].color,
			0, 255);
	light = mult_clamp_d(map->lighting->l_ratio,
			mult_clamp_d(radiant, map->objects[pos].color,
				0, 255), 0, 255);
	return (add_clamp(light, ambient, 0, 255));
}
