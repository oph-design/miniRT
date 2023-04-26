/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_double_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:48 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:32:49 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	mult_double_vec(double d, t_vector vec)
{
	vec.x *= d;
	vec.y *= d;
	vec.z *= d;
	return (vec);
}

t_vector	add_double_vec(double d, t_vector vec)
{
	vec.x += d;
	vec.y += d;
	vec.z += d;
	return (vec);
}

t_vector	sub_double_vec(double d, t_vector vec)
{
	vec.x -= d;
	vec.y -= d;
	vec.z -= d;
	return (vec);
}

t_vector	div_double_vec(double d, t_vector vec)
{
	vec.x /= d;
	vec.y /= d;
	vec.z /= d;
	return (vec);
}
