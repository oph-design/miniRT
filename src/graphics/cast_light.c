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

static double	get_shadow(t_map *map, t_hit hit)
{
	size_t	i;
	double	shadow;

	i = 0;
	shadow = 1.0;
	if (map->light_count > 1)
	{
		while (i < map->light_count)
		{
			if (is_shaded(map, hit, i))
				shadow *= (map->lighting[i].l_ratio);
			i++;
		}
	}
	else
		if (is_shaded(map, hit, i))
			shadow *= map->lighting[i].a_ratio;
	return (shadow);
}

static t_vector	sum_lights(t_vector color, t_vector light, t_vector ambient,
		t_vector specular)
{
	t_vector	l_color;

	l_color = add_vec(light, ambient);
	l_color = add_vec(l_color, specular);
	l_color = color_to_ratio(l_color);
	return (add_vec(color, l_color));
}

t_vector	cast_light(t_map *map, t_hit hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	color;
	t_vector	light_dir;
	size_t		i;

	i = 0;
	color = new_vec(0, 0, 0);
	while (i < map->light_count)
	{
		light_dir = normalize(sub_vec(map->lighting[i].pos, hit.hitpoint));
		ambient = mult_double_vec(map->lighting[i].a_ratio,
				map->lighting[i].a_color);
		light = mult_double_vec(map->lighting[i].l_ratio,
				map->lighting[i].l_color);
		light = mult_double_vec(dot(light_dir, hit.normal), light);
		color = sum_lights(color, light, ambient,
				specular(map->lighting[i].l_color, hit, light_dir));
		if (map->light_count > 1)
			color = mult_double_vec(map->lighting[i].l_ratio, color);
		i++;
	}
	color = mult_double_vec(get_shadow(map, hit), color);
	return (mult_clamp(color, hit.obj.color, 0, 255));
}
