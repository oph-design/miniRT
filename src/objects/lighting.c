#include "objects.h"

void	set_amblight(t_lighting *light, double ratio, u_int32_t color)
{
	light->a_ratio = ratio;
	light->a_color = color;
}

void	set_light(t_lighting *light, double ratio, u_int32_t color, t_vector *c)
{
	light->l_ratio = ratio;
	light->l_color = color;
	light->cords = c;
}
