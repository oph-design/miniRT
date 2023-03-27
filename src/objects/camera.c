#include "objects.h"

t_camera	*new_camera(t_vector *pos)
{
	double		viewport_height;
	double		viewport_width;
	double		focal_length;
	t_camera	*new;

	viewport_height = 2.0;
	viewport_width = (16.0 / 9.0) * viewport_height;
	focal_length = 1.0;
	new = malloc(sizeof(t_camera));
	new->pos = pos;
	new->horizontal = new_vec(viewport_width, 0.0, 0.0);
	new->vertical = new_vec(0.0, viewport_height, 0.0);
	new->orientation = new_vec(0.0 - (viewport_width / 2),
			0.0 - (viewport_height / 2), 0.0 - focal_length);
	return (new);
}
