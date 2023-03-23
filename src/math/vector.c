#include "minirt.h"
#include <stdio.h>

//diggi spaeter loeschen
void	print_vec(t_vector vec)
{
	printf("%f, %f, %f\n", vec.x, vec.y, vec.z);
}

t_vector	*new_vec(double x, double y, double z)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}	

t_vector	normalize(t_vector	vec)
{
	double	length;

	length = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	vec.x = vec.x / length;
	vec.y = vec.y / length;
	vec.z = vec.z / length;
	return (vec);
}
