#ifndef MATHEMATIC_H
# define MATHEMATIC_H

# include "objects.h"
# include <math.h>
# include "MLX42.h"

typedef struct s_vector	t_vector;
typedef struct s_object	t_object;
typedef struct s_ray	t_ray;

double			dot(t_vector a, t_vector b);
double			vec_length_squared(t_vector vec);
t_vector		normalize(t_vector	vec);
double			magnitude(t_vector vec);
t_vector		cross_product(t_vector vec, t_vector cross);

t_vector		add_to_vec(t_vector vec, t_vector add);
t_vector		subtract_vec(t_vector vec, t_vector sub);
t_vector		multiply_vec(t_vector vec, t_vector m);
t_vector		div_vec(t_vector vec, t_vector div);

t_vector		mult_double_vec(double d, t_vector vec);
t_vector		add_double_vec(double d, t_vector vec);
t_vector		sub_double_vec(double d, t_vector vec);
t_vector		div_double_vec(double d, t_vector vec);

t_ray			new_ray(t_vector origin, t_vector direction);
uint32_t		ray_color(t_ray	ray);

double			clamp(double x, double min, double max);
uint32_t		sample_color(t_vector color, int sample_per_pixel);

#endif
