#ifndef MATHEMATIC_H
# define MATHEMATIC_H

# include "objects.h"
# include <math.h>
# include "MLX42.h"

# define ZERO 0.001

typedef struct s_vector	t_vector;
typedef struct s_object	t_object;
typedef struct s_ray	t_ray;

double			dot(t_vector a, t_vector b);
double			vec_length_squared(t_vector vec);
t_vector		normalize(t_vector	vec);
double			magnitude(t_vector vec);
t_vector		cross_product(t_vector vec, t_vector cross);

t_vector		add_vec(t_vector vec, t_vector add);
t_vector		sub_vec(t_vector vec, t_vector sub);
t_vector		mult_vec(t_vector vec, t_vector m);
t_vector		div_vec(t_vector vec, t_vector div);

t_vector		add_clamp(t_vector a, t_vector b, double min, double max);
t_vector		sub_clamp(t_vector a, t_vector b, double min, double max);
t_vector		mult_clamp(t_vector a, t_vector b, double min, double max);
t_vector		div_clamp(t_vector a, t_vector b, double min, double max);

t_vector		add_double_vec(double d, t_vector vec);
t_vector		sub_double_vec(double d, t_vector vec);
t_vector		mult_double_vec(double d, t_vector vec);
t_vector		div_double_vec(double d, t_vector vec);

t_vector		add_clamp_d(double d, t_vector vec, double min, double max);
t_vector		sub_clamp_d(double d, t_vector vec, double min, double max);
t_vector		mult_clamp_d(double d, t_vector vec, double min, double max);
t_vector		div_clamp_d(double d, t_vector vec, double min, double max);

t_ray			new_ray(t_vector origin, t_vector direction);
uint32_t		ray_color(t_ray	ray);
t_vector		at(t_ray ray, double t);

double			clamp(double x, double min, double max);
double			degrees(t_vector a, t_vector b);

#endif
