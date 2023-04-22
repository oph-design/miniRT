#include "minirt.h"

static double	diffuse(void)
{
	double	random;

	random = (double)rand() / 100000000;
	if (random > 5)
		random = 5;
	return (random);
}

static t_vector	specular(t_map *map, t_hit hit, t_vector light_dir)
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
	return (mult_clamp_d(rad, map->lighting->l_color, 0, 255));
}

t_vector	cast_light(t_map *map, t_hit hit)
{
	t_vector	ambient;
	t_vector	light;
	t_vector	light_dir;
	double		radiant;
	t_vector	color;

	light_dir = normalize(sub_vec(map->lighting->pos, hit.hitpoint));
	radiant = dot(normalize(light_dir), hit.normal);
	if (radiant < 0.0)
		radiant = 0;
	ambient = mult_double_vec(map->lighting->a_ratio, map->lighting->a_color);
	if (is_shaded(map, hit))
		return (add_double_vec(diffuse(), add_vec(ambient, new_vec(0, 0, 0))));
	light = mult_double_vec(map->lighting->l_ratio, map->lighting->l_color);
	light = mult_double_vec(radiant, light);
	color = color_to_ratio(add_vec(add_vec(light, ambient),
				specular(map, hit, light_dir)));
	color = mult_clamp(color, hit.obj.color, 0, 255);
	color = add_clamp_d(diffuse(), color, 0, 255);
	return (color);
}
