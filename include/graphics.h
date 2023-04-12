#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42.h"
# include "objects.h"

# define WIDTH 800
# define HEIGHT	500

typedef struct s_vector	t_vector;
typedef struct s_ray	t_ray;
typedef struct s_camera	t_camera;
typedef struct s_window	t_window;
typedef struct s_map	t_map;

typedef enum e_hit_index
{
	INDEX_HIT,
	INDEX
}	t_hit_index;

void		draw(t_map *map);
void		draw_pixel(t_window *window, int x, int y, uint32_t color);
void		setup_window(t_map *map);
uint32_t	write_color(double r, double g, double b, double a);
uint32_t	vec_to_color(t_vector vec);

int			hit_cylinder(t_object cy, t_ray ray, int *pos, double *t);
int			hit_sphere(t_object sp, t_ray ray, int *pos, double *t);
void		hit(t_map *map, int j, int i);

t_ray		get_ray(t_camera *camera, double x, double y);

t_vector	cast_light(t_map *map, int pos, t_vector hit);

int			is_shaded(t_map *map, int pos, t_vector hit);

#endif
