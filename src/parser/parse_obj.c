/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:35 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:36 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_object	parse_sphere(char *str, int *ecode)
{
	char		**args;
	t_object	sphere;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 4)
		return (*ecode = (ARG_NUM + SP_ERROR), ft_free_stra(args),
			new_sphere(new_vec(0, 0, 0), 0, new_vec(0, 0, 0)));
	sphere = new_sphere(get_vector(args[1], ecode, 1),
			get_ratio(args[2], ecode), get_color(args[3], ecode));
	if (*ecode > 0)
		*ecode += SP_ERROR;
	return (ft_free_stra(args), sphere);
}

static t_object	parse_cylinder(char *str, int *ecode)
{
	char		**args;
	double		size[2];
	t_object	cylinder;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 6)
		return (*ecode = (ARG_NUM + CY_ERROR), ft_free_stra(args),
			new_cylinder(new_vec(0, 0, 0), new_vec(0, 0, 0),
				size, new_vec(0, 0, 0)));
	size[0] = get_ratio(args[3], ecode);
	size[1] = get_ratio(args[4], ecode);
	cylinder = new_cylinder(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), size, get_color(args[5], ecode));
	if (*ecode > 0)
		*ecode += CY_ERROR;
	return (ft_free_stra(args), cylinder);
}

static t_object	parse_plane(char *str, int *ecode)
{
	char		**args;
	t_object	plane;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 4)
		return (*ecode = 22, ft_free_stra(args), new_plane(new_vec(0, 0, 0),
				new_vec(0, 0, 0), new_vec(0, 0, 0)));
	plane = new_plane(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), get_color(args[3], ecode));
	if (*ecode > 0)
		*ecode += PL_ERROR;
	return (ft_free_stra(args), plane);
}

static t_object	parse_cone(char *str, int *ecode)
{
	char		**args;
	double		size[2];
	t_object	cone;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 6)
		return (*ecode = (ARG_NUM + CN_ERROR), ft_free_stra(args),
			new_cone(new_vec(0, 0, 0), new_vec(0, 0, 0),
				size, new_vec(0, 0, 0)));
	size[0] = get_ratio(args[3], ecode);
	size[1] = get_ratio(args[4], ecode);
	cone = new_cone(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), size, get_color(args[5], ecode));
	if (*ecode > 0)
		*ecode += CN_ERROR;
	return (ft_free_stra(args), cone);
}

t_object	parse_obj(char *str, int *ecode, t_count *count)
{
	char	*set;

	set = ft_substr(str, 0, 2);
	if (!ft_strncmp(set, "sp", 3))
		return (free(set), (count->sp)++, parse_sphere(str, ecode));
	if (!ft_strncmp(set, "cy", 3))
		return (free(set), (count->cy)++, parse_cylinder(str, ecode));
	if (!ft_strncmp(set, "cn", 3))
		return (free(set), (count->cn)++, parse_cone(str, ecode));
	if (!ft_strncmp(set, "pl", 3))
		return (free(set), (count->pl)++, parse_plane(str, ecode));
	return (free(set), parse_sphere(str, ecode));
}
