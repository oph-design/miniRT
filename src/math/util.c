/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:32 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:32:33 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	return (x);
}

double	degrees(t_vector a, t_vector b)
{
	return (acos(dot(a, b) / (sqrt(vec_length_squared(a))
				* sqrt(vec_length_squared(b)))) * 180.0 / M_PI);
}
