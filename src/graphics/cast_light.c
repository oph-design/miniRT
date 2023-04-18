#include "minirt.h"

static double	radian(t_vector nrml, t_vector light_dir)
{
	return (dot(nrml, light_dir) / (sqrt(vec_length_squared(nrml))
			* sqrt(vec_length_squared(light_dir))));
}

t_vector	cast_light(t_map *map, t_hit hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	light_dir;
	double		radiant;

	ambient = mult_double_vec(map->lighting->a_ratio, map->lighting->a_color);
	ambient = color_to_ratio(ambient);
	ambient = mult_vec(ambient, hit.obj.color);
	if (is_shaded(map, hit))
		return (add_vec(ambient, new_vec(0, 0, 0)));
	light = mult_double_vec(map->lighting->l_ratio, map->lighting->l_color);
	light = color_to_ratio(light);
	light_dir = normalize(sub_vec(map->lighting->pos, hit.hitpoint));
	radiant = radian(normalize(light_dir),
			get_object_normal(hit.obj, hit.hitpoint));
	light = mult_vec(light,
			mult_double_vec(radiant, hit.obj.color));
	return (add_clamp(light, ambient, 0, 255));
}
