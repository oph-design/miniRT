#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "minirt.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
}	t_window;

typedef struct s_sphere
{
	int		x;
	int		y;
	int		z;
	int		radius;
}	t_sphere;

typedef struct s_plane
{
	int		x;
	int		y;
	int		z;
}	t_plane;

void		draw(t_window *window);
void		setup_widnow(void);

#endif
