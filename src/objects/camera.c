#include "objects.h"

double	degrees_to_radians(double fov)
{
	return (fov * M_PI / 180);
}

t_camera	*new_cam(t_vector pos, t_vector orientation, int fov)
{
	t_camera	*new;
	t_vector	vup;
	t_vector	u;
	t_vector	v;

	orientation = mult_double_vec(-1, orientation);
	new = malloc(sizeof(t_camera));
	vup = new_vec(0.0, -1.0, 0.0);
	new->fov = fov;
	new->ratio = ((double)WIDTH / (double)HEIGHT);
	new->vph = 2.0 * tan(degrees_to_radians(fov) / 2);
	new->vpw = new->ratio * new->vph;
	u = normalize(cross_product(vup, orientation));
	v = cross_product(orientation, u);
	new->pos = pos;
	new->dir = mult_double_vec(-1, orientation);
	new->horizontal = mult_double_vec(new->vpw, u);
	new->vertical = mult_double_vec(new->vph, v);
	new->orientation = sub_vec(pos, mult_double_vec(0.5, new->horizontal));
	new->orientation = sub_vec(new->orientation,
			mult_double_vec(0.5, new->vertical));
	new->orientation = sub_vec(new->orientation, orientation);
	return (new);
}
