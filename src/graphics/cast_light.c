#include "minirt.h"

static t_vector	specular(t_vector l_color, t_hit hit, t_vector light_dir)
{
	t_vector	r;
	double		rad;

	r = sub_vec(mult_double_vec(dot(mult_double_vec(2.0, hit.normal),
					light_dir), hit.normal), light_dir);
	rad = dot(r, sub_vec(hit.cam_ray.origin, hit.hitpoint))
		/ (magnitude(r) * magnitude(sub_vec(hit.cam_ray.origin, hit.hitpoint)));
	if (rad < 0.0)
		rad = 0;
	rad = pow(rad, 16);
	rad *= 0.5;
	return (mult_clamp_d(rad, l_color, 0, 255));
}

t_vector	cast_light(t_map *map, t_hit hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	light_dir;
	t_vector	color;
	size_t		i;

	i = 0;
	while (i < map->light_count)
	{
		light_dir = normalize(sub_vec(map->lighting[i].pos, hit.hitpoint));
		ambient = mult_double_vec(map->lighting[i].a_ratio,
				map->lighting[i].a_color);
		if (is_shaded(map, hit, light_dir))
			return (mult_vec(color_to_ratio(ambient), hit.obj.color));
		light = mult_double_vec(map->lighting[i].l_ratio,
				map->lighting[i].l_color);
		light = mult_double_vec(dot(normalize(light_dir), hit.normal), light);
		color = color_to_ratio(add_vec(add_vec(light, ambient),
					specular(map->lighting[i].l_color, hit, light_dir)));
		color = mult_clamp(color, hit.obj.color, 0, 255);
		i++;
	}
	return (color);
}
