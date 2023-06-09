/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:34:08 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 13:25:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_lighting	get_lighting(char *line, int *ecode);
static void			get_amlight(char **file, t_map *map, int *ecode);

int	set_lighting(char **file, t_map *map)
{
	int			ecode;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	map->light_count = 0;
	ecode = SUCCESS;
	while (stra_iteri(file, "l", 1))
		map->light_count += 1;
	if (map->light_count < 1)
		return (NOT_FOUND + L_ERROR);
	map->lighting = malloc(sizeof(t_lighting) * map->light_count);
	while (file[j] != NULL)
	{
		if (!ft_strncmp(file[j], "l", 1))
			map->lighting[i++] = get_lighting(file[j], &ecode);
		if (ecode)
			return (check_overflow(ecode + i * 100 + L_ERROR));
		j++;
	}
	get_amlight(file, map, &ecode);
	return (ecode);
}

static t_lighting	get_lighting(char *line, int *ecode)
{
	t_lighting	res;
	char		**args;

	args = ft_split_whitespcs(line);
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), *ecode = ARG_NUM,
			get_light(0, new_vec(0, 0, 0), new_vec(0, 0, 0)));
	res = get_light(get_ratio(args[2], ecode), get_color(args[3], ecode),
			get_vector(args[1], ecode, 1));
	ft_free_stra(args);
	if (res.l_ratio < 0.0 || res.l_ratio > 1.0)
		*ecode = VAL_RANGE;
	return (res);
}

static void	get_amlight(char **file, t_map *map, int *ecode)
{
	t_vector	color;
	double		ratio;
	char		*input;
	char		**args;
	size_t		i;

	i = 0;
	input = stra_iteri(file, "A", 0);
	if (!input)
		return ((void)(*ecode = NOT_FOUND + A_ERROR));
	args = ft_split_whitespcs(input);
	if (ft_stra_len(args) != 3)
		return ((void)(ft_free_stra(args), *ecode = ARG_NUM + A_ERROR));
	color = get_color(args[2], ecode);
	ratio = get_ratio(args[1], ecode);
	ft_free_stra(args);
	if (*ecode)
		*ecode = *ecode + A_ERROR;
	if (ratio < 0.0 || ratio > 1.0)
		return ((void)(*ecode = VAL_RANGE + A_ERROR));
	while (i < map->light_count)
		set_amblight(&map->lighting[i++], ratio, color);
	if (stra_iteri(file, "A", 0) != NULL)
		*ecode = DUP_ENTITY + A_ERROR;
}

int	set_camera(char **file, t_map *map)
{
	char			**args;
	char			*input;
	int				ecode;
	const double	wh[2] = {(double)WIDTH, (double)HEIGHT};

	ecode = SUCCESS;
	input = stra_iteri(file, "C", 2);
	if (!input)
		return (NOT_FOUND);
	args = ft_split_whitespcs(input);
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), ARG_NUM);
	if (is_number(args[3]))
		return (ft_free_stra(args), NO_NUMBER);
	if (ft_strtod(args[3]) > 180 || ft_atoi(args[3]) < 0)
		return (ft_free_stra(args), VAL_RANGE);
	map->camera = new_cam(get_vector(args[1], &ecode, 1),
			get_vector(args[2], &ecode, 0), ft_atoi(args[3]), wh);
	ft_free_stra(args);
	if (ecode)
		return (ecode);
	input = stra_iteri(file, "C", 2);
	if (input != NULL)
		return (DUP_ENTITY);
	return (SUCCESS);
}

int	get_obj_arr(char **file, t_map *map)
{
	int		ecode;
	t_count	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = (t_count){0, 0, 0, 0};
	ecode = SUCCESS;
	map->obj_count = ft_stra_len(file) - map->light_count - 2;
	if (map->obj_count < 1)
		return (NOT_FOUND);
	map->objects = malloc(map->obj_count * sizeof(t_object));
	while (file[j] != NULL)
	{
		if (!is_object(file[j]))
			map->objects[i++] = parse_obj(file[j], &ecode, &count);
		if (ecode)
			return (check_overflow(get_err_num(ecode, file[j], count)));
		j++;
	}
	return (SUCCESS);
}
