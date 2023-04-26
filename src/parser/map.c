/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:29 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:30 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_error(int code, char *component, t_map *map, char **file);
static void	check_for_objects(int exit_code, t_map *map, char **file);

t_map	*get_map(char **file)
{
	t_map	*map;
	int		exit_code;

	if (file == NULL)
		parse_error(EMPTY, "file: ", NULL, file);
	if (!find_invalid_ids(file))
		parse_error(IDENTIFIER, "file: ", NULL, file);
	exit_code = SUCCESS;
	map = malloc(sizeof(t_map));
	map->lighting = NULL;
	map->camera = NULL;
	map->objects = NULL;
	exit_code = set_lighting(file, map);
	check_for_objects(exit_code, map, file);
	exit_code = set_camera(file, map);
	parse_error(exit_code, "camera: ", map, file);
	exit_code = get_obj_arr(file, map);
	check_for_objects(exit_code, map, file);
	return (ft_free_stra(file), map);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free(map->lighting);
	free(map->camera);
	free(map->objects);
	free(map);
}

static void	check_for_objects(int exit_code, t_map *map, char **file)
{
	if (exit_code % 100 < 10)
		parse_error(exit_code, "object: ", map, file);
	if (exit_code % 100 > 10 && exit_code % 100 < 20)
		parse_error(exit_code, "sphere: ", map, file);
	if (exit_code % 100 > 20 && exit_code % 100 < 30)
		parse_error(exit_code, "plane: ", map, file);
	if (exit_code % 100 > 30 && exit_code % 100 < 40)
		parse_error(exit_code, "cylinder: ", map, file);
	if (exit_code % 100 > 40 && exit_code % 100 < 50)
		parse_error(exit_code, "cone: ", map, file);
	if (exit_code % 100 > 50 && exit_code % 100 < 60)
		parse_error(exit_code, "lightsource: ", map, file);
	if (exit_code % 100 > 60 && exit_code % 100 < 70)
		parse_error(exit_code, "ambient: ", map, file);
}

static void	print_id(int id)
{
	char	*str;

	if (id == 0)
		return ;
	str = ft_itoa(id);
	ft_putstr_fd("#", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" ", 2);
	free(str);
}

static void	parse_error(int code, char *component, t_map *map, char **file)
{
	if (code == SUCCESS)
		return ;
	ft_putstr_fd("Error: ", 2);
	print_id(code / 100);
	ft_putstr_fd(component, 2);
	if (code % 10 == EMPTY)
		ft_putendl_fd("empty file", 2);
	if (code % 10 == IDENTIFIER)
		ft_putendl_fd("invalid Identifier", 2);
	if (code % 10 == ARG_NUM)
		ft_putendl_fd("wrong number of arguments", 2);
	if (code % 10 == VAL_RANGE)
		ft_putendl_fd("wrong range of values", 2);
	if (code % 10 == NO_NUMBER)
		ft_putendl_fd("invalid number", 2);
	if (code % 10 == VAL_NUM)
		ft_putendl_fd("wrong number of values", 2);
	if (code % 10 == DUP_ENTITY)
		ft_putendl_fd("duplicate occurance of entity", 2);
	if (code % 10 == NOT_FOUND)
		ft_putendl_fd("non existent", 2);
	free_map(map);
	if (file != NULL)
		ft_free_stra(file);
	exit(EXIT_FAILURE);
}
