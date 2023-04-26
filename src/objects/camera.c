/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:06 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:07 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

double	degrees_to_radians(double fov)
{
	return (fov * M_PI / 180);
}

t_camera	*new_cam(t_vector pos, t_vector direct, int fov, const double wh[2])
{
	t_camera	*new;
	t_vector	vup;
	t_vector	u;
	t_vector	v;

	direct = mult_double_vec(-1, normalize(direct));
	new = malloc(sizeof(t_camera));
	vup = new_vec(0.0, -1.0, 0.0);
	new->fov = fov;
	new->ratio = (wh[0] / wh[1]);
	new->vph = 2.0 * tan(degrees_to_radians(fov) / 2);
	new->vpw = new->ratio * new->vph;
	u = normalize(cross_product(vup, direct));
	v = cross_product(direct, u);
	new->pos = pos;
	new->dir = mult_double_vec(-1, direct);
	new->horizontal = mult_double_vec(new->vpw, u);
	new->vertical = mult_double_vec(new->vph, v);
	new->direct = sub_vec(pos, mult_double_vec(0.5, new->horizontal));
	new->direct = sub_vec(new->direct,
			mult_double_vec(0.5, new->vertical));
	new->direct = sub_vec(new->direct, direct);
	return (new);
}
