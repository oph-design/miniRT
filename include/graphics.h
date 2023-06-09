/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:34:35 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:37 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42.h"
# include "objects.h"

# define WIDTH 800
# define HEIGHT	500

typedef struct s_vector	t_vector;
typedef struct s_ray	t_ray;
typedef struct s_hit	t_hit;
typedef struct s_camera	t_camera;
typedef struct s_window	t_window;
typedef struct s_map	t_map;

typedef enum e_pos_index
{
	INDEX_HIT,
	INDEX,
	INDEX_HIT_LIGHT
}	t_pos_index;

typedef enum e_hit_index
{
	OBJECT,
	LIGHTS
}	t_hit_index;

void		draw(t_map *map);
void		draw_pixel(t_window *window, int x, int y, uint32_t color);
void		window_panic(t_map *map);
void		setup_window(t_map *map);

uint32_t	write_color(double r, double g, double b, double a);
uint32_t	vec_to_color(t_vector vec);
t_vector	color_to_ratio(t_vector color);

void		cylinder_helper(t_object cy, t_ray ray, size_t *pos, double *t);
void		cone_helper(t_object cn, t_ray ray, size_t *pos, double *t);
int			hit_disk(t_object pl, t_ray ray, size_t *pos, double *t);

double		check_root(double *t, t_vector h, size_t *pos);
int			hit_sphere(t_object sp, t_ray ray, size_t *pos, double *t);
int			hit_plane(t_object pl, t_ray ray, size_t *pos, double *t);
t_vector	cone_normal(t_object obj, t_ray ray, double t);
t_vector	cylinder_normal(t_object obj, t_vector hit, t_ray ray, double t);
void		hit(t_map *map, int j, int i);

t_vector	get_object_normal(t_object obj, t_vector hit, t_ray ray, double t);
void		loop_objects(t_map *map, t_ray ray, double *t, size_t *pos);

t_ray		get_ray(t_camera *camera, double x, double y);
void		light_movement(t_map *map);

t_vector	cast_light(t_map *map, t_hit hit);

int			is_shaded(t_map *map, t_hit hit, size_t i);

#endif
