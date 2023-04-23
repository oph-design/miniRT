#include "objects.h"

void	set_amblight(t_lighting *light, double ratio, t_vector color)
{
	light->a_ratio = ratio;
	light->a_color = color;
}

t_lighting	get_light(double ratio, t_vector color, t_vector c)
{
	t_lighting	light;

	light.l_ratio = ratio;
	light.l_color = color;
	light.pos = c;
	light.obj = new_light(light.pos, 0.5, light.l_color);
	return(light);
}
