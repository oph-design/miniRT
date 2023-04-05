#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42.h"
# include "objects.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vector	t_vector;
typedef struct s_ray	t_ray;
typedef struct s_camera	t_camera;
typedef struct s_window	t_window;
typedef struct s_map	t_map;

void		draw(t_map *map);
void		draw_pixel(t_window *window, int x, int y, uint32_t color);
void		setup_window(t_map *map);
uint32_t	color(double r, double g, double b, double a);
int			hit_sphere(t_object sp, t_ray ray);

t_ray		get_ray(t_camera *camera, double x, double y);

#endif
