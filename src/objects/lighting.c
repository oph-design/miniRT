#include "objects.h"

void	set_amblight(t_lighting *light, double ratio, t_vector color)
{
	light->a_ratio = ratio;
	light->a_color = color;
}

void	set_light(t_lighting *light, double ratio, t_vector color, t_vector c)
{
	light->l_ratio = ratio;
	light->l_color = color;
	light->pos = c;
}
