/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:12 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:13 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	new_light(t_vector pos, double r, t_vector color)
{
	t_object	new;

	new.type = LIGHT;
	new.pos = pos;
	new.radius = r / 2.0;
	new.height = 0;
	new.color = color;
	return (new);
}

t_object	new_sphere(t_vector pos, double r, t_vector color)
{
	t_object	new;

	new.type = SPHERE;
	new.pos = pos;
	new.radius = r / 2.0;
	new.height = 0;
	new.color = color;
	return (new);
}

t_object	new_cylinder(t_vector pos, t_vector direct,
			double *size, t_vector color)
{
	t_object	new;

	new.type = CYLINDER;
	new.pos = pos;
	new.radius = size[0] / 2.0;
	new.height = size[1];
	new.direct = normalize(direct);
	new.pos = sub_vec(new.pos,
			mult_double_vec(new.height / 2.0, new.direct));
	new.color = color;
	return (new);
}

t_object	new_cone(t_vector pos, t_vector direct,
			double *size, t_vector color)
{
	t_object	cone;

	cone = new_cylinder(pos, direct, size, color);
	cone.type = CONE;
	cone.pos = pos;
	return (cone);
}

t_object	new_plane(t_vector pos, t_vector direct, t_vector color)
{
	t_object	new;

	new.type = PLANE;
	new.pos = pos;
	new.radius = 0;
	new.height = 0;
	new.direct = direct;
	new.color = color;
	return (new);
}
