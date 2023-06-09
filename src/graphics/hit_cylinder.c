/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:31:31 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:31:32 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	check_root_cy(double *t, t_vector var)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(var.y * var.y - var.x * var.z);
	to = (-var.y + disc) / var.x;
	tl = (-var.y - disc) / var.x;
	if (to < tl && *t > to)
		return (to);
	else if (*t > tl)
		return (tl);
	return (*t);
}

static t_vector	calc_var(t_ray ray, t_object cy)
{
	t_vector	var;
	t_vector	q;
	t_vector	d_proj;

	q = sub_vec(ray.origin, cy.pos);
	d_proj = sub_vec(ray.direct,
			mult_double_vec(dot(ray.direct, cy.direct),
				cy.direct));
	q = sub_vec(q, mult_double_vec(dot(q, cy.direct), cy.direct));
	var.x = vec_length_squared(d_proj);
	var.y = dot(d_proj, q);
	var.z = vec_length_squared(q) - pow(cy.radius, 2);
	return (var);
}

static int	hit_cylinder(t_object cy, t_ray ray, size_t *pos, double *t)
{
	t_vector	var;
	double		tmp;
	t_vector	x;

	tmp = *t;
	var = calc_var(ray, cy);
	if (var.y * var.y - var.x * var.z < 0)
		return (0);
	else
	{
		*t = check_root_cy(t, var);
		if (*t != tmp)
		{
			x = add_vec(ray.origin, mult_double_vec(*t, ray.direct));
			if (dot(sub_vec(x, cy.pos), cy.direct) < cy.height
				&& dot(sub_vec(x, cy.pos), cy.direct) > 0)
			{
				if (pos)
					pos[INDEX_HIT] = pos[INDEX];
				return (1);
			}
			*t = tmp;
		}
	}
	return (0);
}

static void	check_for_negative(double *t, double *tmp)
{
	if (*t + ZERO < ZERO)
		*t = *tmp;
	*tmp = *t;
}

void	cylinder_helper(t_object cy, t_ray ray, size_t *pos, double *t)
{
	t_object	pl;
	double		tmp;

	tmp = *t;
	hit_cylinder(cy, ray, pos, t);
	if (pos == NULL)
		check_for_negative(t, &tmp);
	pl = new_plane(cy.pos, cy.direct, cy.color);
	pl.radius = cy.radius;
	hit_disk(pl, ray, pos, t);
	if (pos == NULL)
		check_for_negative(t, &tmp);
	pl = new_plane(add_vec(cy.pos,
				mult_double_vec(cy.height, cy.direct)),
			cy.direct, cy.color);
	pl.radius = cy.radius;
	hit_disk(pl, ray, pos, t);
	if (pos == NULL)
		check_for_negative(t, &tmp);
}
