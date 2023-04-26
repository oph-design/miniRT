/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:00 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:01 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_length_squared(t_vector vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

double	magnitude(t_vector vec)
{
	return (sqrt(vec_length_squared(vec)));
}

t_vector	normalize(t_vector vec)
{
	double	length;

	length = sqrt(vec_length_squared(vec));
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}

t_vector	cross_product(t_vector vec, t_vector cross)
{
	return (new_vec(vec.y * cross.z - vec.z * cross.y,
			vec.z * cross.x - vec.x * cross.z,
			vec.x * cross.y - vec.y * cross.x));
}
