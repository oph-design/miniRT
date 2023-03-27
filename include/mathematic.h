#ifndef MATHEMATIC_H
# define MATHEMATIC_H

# include <math.h>
# include "MLX42.h"

typedef struct s_sphere	t_sphere;
typedef struct s_camera	t_camera;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_ray
{
	t_vector	*origin;
	t_vector	*direction;
}	t_ray;

typedef struct s_hitp
{
	t_vector	p;
	t_vector	normal;
	double		t;
}	t_hitp;

double			dot(t_vector a, t_vector b);
double			vec_length_squared(t_vector vec);
t_vector		normalize(t_vector	vec);
double			magnitude(t_vector vec);

t_vector		add_to_vec(t_vector vec, t_vector add);
t_vector		subtract_vec(t_vector vec, t_vector sub);
t_vector		multiply_vec(t_vector vec, t_vector m);

t_vector		mult_double_vec(double d, t_vector vec);
t_vector		add_double_vec(double d, t_vector vec);
t_vector		sub_double_vec(double d, t_vector vec);

t_vector		new_vec_stack(double x, double y, double z);
t_vector		*new_vec(double x, double y, double z);
void			print_vec(t_vector vec);

t_ray			*new_ray(t_vector origin, t_vector direction);
uint32_t		ray_color(t_ray	*ray, t_sphere *sp);
t_ray			*get_ray(t_camera *camera, double x, double y);

#endif
