#include "objects.h"

t_camera	*new_cam(t_vector pos, t_vector orientation, int fov)
{
	t_camera	*new;

	new = malloc(sizeof(t_camera));
	new->ratio = (16.0 / 9.0);
	new->orientation = orientation;
	new->pos = pos;
	new->fov = tan((fov / 2 * M_PI / 180) / 2);
	return (new);
}
