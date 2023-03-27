#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_lighting
{
	double		a_ratio;
	u_int32_t	a_color;
	double		l_ratio;
	u_int32_t	l_color;
	t_vector	*cords;
}				t_lighting;

typedef struct s_camera
{
	t_vector	*pos;
	t_vector	*orientation;
	t_vector	*horizontal;
	t_vector	*vertical;
	int			fov;
}	t_camera;

typedef struct s_sphere
{
	t_vector	*center;
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

typedef struct s_map
{
	t_lighting	*lighting;
	t_camera	*camera;
	t_list		*objects;
}				t_map;

t_camera	*new_camera(t_vector *pos);
void		set_light(t_lighting *l, double r, u_int32_t color, t_vector *c);
void		set_amblight(t_lighting *light, double ratio, u_int32_t color);
t_sphere	*new_sphere(t_vector *pos, double r);
t_sphere	*new_sphere(t_vector *pos, double r);
void		free_sphere(t_sphere *sp);
t_vector	*new_vec(double x, double y, double z);
double		get_ratio(char *str, int *exit_code);
t_camera	*new_cam(t_vector *vec, t_vector *pos, int fov);

#endif
