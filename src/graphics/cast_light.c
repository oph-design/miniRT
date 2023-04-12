#include "minirt.h"

t_vector	color_to_ratio(t_vector color)
{
	color.x /= 255.0;
	color.y /= 255.0;
	color.z /= 255.0;
	return (color);
}

t_vector	cast_light(t_map *map, int pos, t_vector hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	dir;
	t_vector	light_dir;
	double		radiant;

	ambient = mult_double_vec(map->lighting->a_ratio, map->lighting->a_color);
	ambient = color_to_ratio(ambient);
	light = mult_double_vec(map->lighting->l_ratio, map->lighting->l_color);
	light = color_to_ratio(light);
	light_dir = normalize(sub_vec(map->lighting->pos, hit));
	dir = normalize(sub_vec(hit, map->objects[pos].pos));
	radiant = dot(light_dir, dir);
	ambient = mult_vec(ambient, map->objects[pos].color);
	light = mult_vec(light,
			mult_double_vec(radiant, map->objects[pos].color));
	return (add_clamp(light, ambient, 0, 255));
}
