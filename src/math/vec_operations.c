/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:54 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:32:56 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	add_vec(t_vector vec, t_vector add)
{
	vec.x += add.x;
	vec.y += add.y;
	vec.z += add.z;
	return (vec);
}

t_vector	sub_vec(t_vector vec, t_vector sub)
{
	vec.x -= sub.x;
	vec.y -= sub.y;
	vec.z -= sub.z;
	return (vec);
}

t_vector	mult_vec(t_vector vec, t_vector m)
{
	vec.x *= m.x;
	vec.y *= m.y;
	vec.z *= m.z;
	return (vec);
}

t_vector	div_vec(t_vector vec, t_vector div)
{
	vec.x /= div.x;
	vec.y /= div.y;
	vec.z /= div.z;
	return (vec);
}
