#include "objects.h"

double	degrees_to_radians(double fov)
{
	return (fov * M_PI / 180);
}

t_camera	*new_cam(t_vector pos, t_vector orientation, int fov)
{
	t_camera	*new;
	t_vector	vup;
	t_vector	w;
	t_vector	u;
	t_vector	v;

	new = malloc(sizeof(t_camera));
	vup = new_vec(0.0, -1.0, 0.0);
	new->fov = fov;
	new->ratio = ((double)WIDTH / (double)HEIGHT);
	new->vph = 2.0 * tan(degrees_to_radians(fov) / 2);
	new->vpw = new->vph * new->ratio;
	w = normalize(sub_vec(pos, orientation));
	u = normalize(cross_product(vup, w));
	v = cross_product(w, u);
	new->pos = pos;
	new->dir = orientation;
	new->horizontal = mult_double_vec(new->vpw, u);
	new->vertical = mult_double_vec(new->vph, v);
	new->orientation = sub_vec(pos, div_double_vec(2.0, new->horizontal));
	new->orientation = sub_vec(new->orientation,
			div_double_vec(2.0, new->vertical));
	new->orientation = sub_vec(new->orientation, w);
	return (new);
}
