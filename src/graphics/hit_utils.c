/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:31:55 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:31:56 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	cylinder_normal(t_object obj, t_vector hit, t_ray ray, double t)
{
	double	offset;

	offset = dot(sub_vec(add_vec(ray.origin,
					mult_double_vec(t, ray.direct)), obj.pos), obj.direct);
	if (offset < ZERO && offset > -ZERO)
		return (normalize(mult_double_vec(-1, obj.direct)));
	if (offset + ZERO >= obj.height)
		return (normalize(obj.direct));
	return (normalize(sub_vec(sub_vec(hit, obj.pos),
				mult_double_vec(dot(sub_vec(hit, obj.pos),
						obj.direct), obj.direct))));
}

t_vector	cone_normal(t_object obj, t_ray ray, double t)
{
	double	offset;

	offset = dot(sub_vec(add_vec(ray.origin,
					mult_double_vec(t, ray.direct)), obj.pos), obj.direct);
	if (offset < ZERO && offset > -ZERO)
		return (normalize(mult_double_vec(-1, obj.direct)));
	if (offset + ZERO >= obj.height)
		return (normalize(obj.direct));
	return (normalize(cross_product(cross_product(obj.direct,
					sub_vec(at(ray, t), obj.pos)),
				sub_vec(at(ray, t), obj.pos))));
}
