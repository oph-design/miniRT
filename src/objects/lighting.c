/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:09 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:10 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	set_amblight(t_lighting *light, double ratio, t_vector color)
{
	light->a_ratio = ratio;
	light->a_color = color;
}

t_lighting	get_light(double ratio, t_vector color, t_vector c)
{
	t_lighting	light;

	light.l_ratio = ratio;
	light.l_color = color;
	light.pos = c;
	light.obj = new_light(light.pos, 0.5, light.l_color);
	return (light);
}
