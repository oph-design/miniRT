#include "minirt.h"

t_vector	clamp_multiply(t_vector light, t_vector color)
{
	t_vector	diffuse;

	diffuse.x = clamp(light.x * color.x, 0.0, 255.0);
	diffuse.y = clamp(light.y * color.y, 0.0, 255.0);
	diffuse.z = clamp(light.z * color.z, 0.0, 255.0);
	return (diffuse);
}

t_vector	mult_double_clamp(double d, t_vector color)
{
	color.x = clamp(d * color.x, 0.0, 255.0);
	color.y = clamp(d * color.y, 0.0, 255.0);
	color.z = clamp(d * color.z, 0.0, 255.0);
	return (color);
}

t_vector	add_to_vec_clamp(t_vector a, t_vector b)
{
	t_vector	res;

	res = add_to_vec(a, b);
	res.x = clamp(res.x, 0.0, 255.0);
	res.y = clamp(res.y, 0.0, 255.0);
	res.z = clamp(res.z, 0.0, 255.0);
	return (res);
}

t_vector	cast_light(t_map *map, int pos, t_vector hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	dir;
	t_vector	light_dir;
	double		radiant;

	ambient = mult_double_clamp(map->lighting->a_ratio, map->lighting->a_color);
	light = mult_double_clamp(map->lighting->l_ratio, map->lighting->l_color);
	light_dir = normalize(subtract_vec(map->lighting->pos, hit));
	dir = normalize(subtract_vec(hit, map->objects[pos].pos));
	radiant = dot(light_dir, dir);
	return (mult_double_clamp(radiant, map->objects[pos].color));
}
