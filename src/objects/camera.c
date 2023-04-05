#include "objects.h"
#include <stdio.h>

t_camera	*new_cam(t_vector pos, t_vector orientation, int fov)
{
	t_camera	*new;
	t_vector	vup;
	t_vector	w;
	t_vector	u;
	t_vector	v;

	printf("Camera:\npos: %f, %f, %f\norientation: %f, %f, %f\n",
		pos.x, pos.y, pos.z, orientation.x, orientation.y, orientation.z);
	new = malloc(sizeof(t_camera));
	vup = new_vec(0.0, 1.0, 0.0);
	new->fov = tan((fov * (M_PI / 180)) / 2);
	new->ratio = (16.0 / 9.0);
	new->vph = 2.0 * new->fov;
	new->vpw = new->ratio * new->vph;
	w = normalize(subtract_vec(pos, orientation));
	u = normalize(cross_product(vup, w));
	v = cross_product(w, u);
	new->pos = pos;
	new->horizontal = mult_double_vec(new->vpw, u);
	new->vertical = mult_double_vec(new->vph, v);
	new->orientation = subtract_vec(subtract_vec(subtract_vec(pos,
					div_double_vec(2, new->horizontal)),
				div_double_vec(2, new->vertical)), w);
	return (new);
}
