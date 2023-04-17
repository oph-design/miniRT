#include "minirt.h"

t_vector	color_to_ratio(t_vector color)
{
	color.x /= 255.0;
	color.y /= 255.0;
	color.z /= 255.0;
	return (color);
}

double	radian(t_vector nrml, t_vector light_dir)
{
	double		tmp;
	double		tmp2;
	double		tmp3;

	tmp = dot(nrml, light_dir);
	tmp2 = sqrt(vec_length_squared(nrml));
	tmp3 = sqrt(vec_length_squared(light_dir));
	return (tmp / (tmp2 * tmp3));
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
	return (new_vec(0, 0, 0));
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
	light = mult_double_vec(map->lighting->l_ratio, map->lighting->l_color);
	light = color_to_ratio(light);
	light_dir = normalize(sub_vec(map->lighting->pos, hit.hitpoint));
	radiant = radian(normalize(light_dir),
			get_object_normal(hit.obj, hit.hitpoint));
	light = mult_vec(light,
			mult_double_vec(radiant, hit.obj.color));
	return (add_clamp(light, ambient, 0, 255));
}
