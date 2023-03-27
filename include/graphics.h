#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42.h"
# include "objects.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vector	t_vector;
typedef struct s_ray	t_ray;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_camera	*camera;
	int			width;
	int			height;
}	t_window;

void		draw(t_window *window);
void		draw_pixel(t_window *window, int x, int y, uint32_t color);
void		setup_window(void);
uint32_t	color(double r, double g, double b, double a);

#endif
