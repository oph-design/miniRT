/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:30:45 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:30:46 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_in_front(t_vector light_dir, t_ray light_ray, double t)
{
	double	source_length;
	double	hit_length;

	source_length = vec_length_squared(light_dir);
	hit_length = vec_length_squared(sub_vec(light_ray.origin,
				at(light_ray, t)));
	if (source_length > hit_length)
		return (1);
	return (0);
}

static int	intercept_obj(t_map *map, t_hit hit, size_t i, t_vector light_dir)
{
	t_ray		light_ray;
	double		t;

	t = INFINITY;
	light_ray = new_ray(add_vec(mult_double_vec(ZERO, hit.normal),
				hit.hitpoint), light_dir);
	if (map->objects[i].type == SPHERE)
		hit_sphere(map->objects[i], light_ray, NULL, &t);
	if (map->objects[i].type == CYLINDER)
		cylinder_helper(map->objects[i], light_ray, NULL, &t);
	if (map->objects[i].type == CONE)
		cone_helper(map->objects[i], light_ray, NULL, &t);
	if (map->objects[i].type == PLANE)
		hit_plane(map->objects[i], light_ray, NULL, &t);
	if (t < INFINITY && t + ZERO > ZERO
		&& is_in_front(light_dir, light_ray, t))
		return (1);
	return (0);
}

int	is_shaded(t_map *map, t_hit hit, size_t i)
{
	size_t		j;
	t_vector	light_dir;

	j = 0;
	light_dir = sub_vec(map->lighting[i].pos, hit.hitpoint);
	while (map->obj_count > j && !intercept_obj(map, hit, j, light_dir))
		j++;
	if (j != map->obj_count)
		return (1);
	return (0);
}
