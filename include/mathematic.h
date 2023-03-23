#ifndef MATHEMATIC_H
# define MATHEMATIC_H

# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector		normalize(t_vector	vec);
t_vector		*new_vec(double x, double y, double z);
void			print_vec(t_vector vec);

#endif
