#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"

typedef enum e_type
{
	sphere,
	zylinder,
	plane
}	t_type;

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
	t_vector	*horizontal;
	t_vector	*orientation;
	t_vector	*vertical;
	int			fov;
}	t_camera;

typedef struct s_object
{
	t_type		type;
	t_vector	*pos;
	t_vector	*orientation;
	double		radius;
	double		height;
	u_int32_t	color;
}	t_object;

typedef struct s_map
{
	t_lighting	*lighting;
	t_camera	*camera;
	t_object	*objects;
	size_t		obj_count;
}				t_map;

t_camera	*new_camera(t_vector *pos);
void		set_light(t_lighting *l, double r, u_int32_t color, t_vector *c);
void		set_amblight(t_lighting *light, double ratio, u_int32_t color);
t_object	new_sphere(t_vector *pos, double r, u_int32_t color);
void		free_object(t_object *sp);
t_vector	*new_vec(double x, double y, double z);
double		get_ratio(char *str, int *exit_code);
t_camera	*new_cam(t_vector *vec, t_vector *pos, int fov);

#endif
