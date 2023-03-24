#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vector	t_vector;

typedef struct s_camera
{
	t_vector	*pos;
	t_vector	*orientation;
	t_vector	*horizontal;
	t_vector	*vertical;
	int			fov;
}	t_camera;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_camera	*camera;
	int			width;
	int			height;
}	t_window;

typedef struct s_sphere
{
	t_vector	*pos;
	double		radius;
}	t_sphere;

typedef struct s_plane
{
	t_vector	*pos;
	t_vector	*orientation;
	int			r;
	int			g;
	int			b;
}	t_plane;

void		draw(t_window *window);
void		draw_pixel(t_window *window, int x, int y, uint32_t color);
void		setup_window(void);
uint32_t	pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);

#endif
