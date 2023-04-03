#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"

typedef enum e_type
{
	sphere,
	cylinder,
	plane
}	t_type;

typedef enum e_errors
{
	SUCCESS,
	FATAL,
	ARG_NUM,
	VAL_RANGE,
	NO_NUMBER,
	VAL_NUM,
	DUP_ENTITY,
	NOT_FOUND
}	t_errors;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_lighting
{
	double		a_ratio;
	t_vector	a_color;
	double		l_ratio;
	t_vector	l_color;
	t_vector	pos;
}				t_lighting;

typedef struct s_camera
{
	t_vector	pos;
	t_vector	horizontal;
	t_vector	orientation;
	t_vector	vertical;
	int			fov;
}	t_camera;

typedef struct s_object
{
	t_type		type;
	t_vector	pos;
	t_vector	orientation;
	double		radius;
	double		height;
	t_vector	color;
}	t_object;

typedef struct s_map
{
	t_lighting	*lighting;
	t_camera	*camera;
	t_object	*objects;
	size_t		obj_count;
}				t_map;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

void		free_object_arr(t_object *obj, size_t size);
t_camera	*new_camera(t_vector pos);
t_vector	new_vec(double x, double y, double z);
t_object	new_sphere(t_vector pos, double r, t_vector color);
t_camera	*new_cam(t_vector vec, t_vector pos, int fov);
t_object	new_plane(t_vector pos, t_vector orientation, t_vector color);
t_object	new_cylinder(t_vector pos, t_vector orientation,
				double *size, t_vector color);
void		set_amblight(t_lighting *light, double ratio, t_vector color);
void		set_light(t_lighting *light, double ratio,	t_vector color,
				t_vector cords);

#endif
