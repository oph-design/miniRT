#include "parser.h"

static t_errors	get_lighting(char **file, t_lighting *light);
static t_errors	get_amlight(char **file, t_lighting *light);

t_errors	set_lighting(char **file, t_map *map)
{
	t_lighting	*light;
	t_errors	ecode;

	ecode = SUCCESS;
	light = malloc(sizeof(t_lighting));
	ecode = get_amlight(file, light);
	if (ecode)
		return (free(light), ecode);
	ecode = get_lighting(file, light);
	if (ecode)
		return (free(light), ecode);
	map->lighting = light;
	return (SUCCESS);
}

static t_errors	get_lighting(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	t_errors	ecode;

	ecode = SUCCESS;
	input = stra_iteri(file, "L", 1);
	if (!input)
		return (NOT_FOUND);
	args = ft_split_whitespcs(input);
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), ARG_NUM);
	set_light(light, get_ratio(args[2], &ecode), get_color(args[3], &ecode),
		get_vector(args[1], &ecode, 1));
	ft_free_stra(args);
	if (light->l_ratio < 0.0 || light->l_ratio > 1.0)
		return (VAL_RANGE);
	if (ecode)
		return (ecode);
	input = stra_iteri(file, "L", 1);
	if (input != NULL)
		return (DUP_ENTITY);
	return (SUCCESS);
}

static t_errors	get_amlight(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	t_errors	ecode;

	ecode = SUCCESS;
	input = stra_iteri(file, "A", 0);
	if (!input)
		return (NOT_FOUND);
	args = ft_split_whitespcs(input);
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), ARG_NUM);
	set_amblight(light, get_ratio(args[1], &ecode), get_color(args[2], &ecode));
	ft_free_stra(args);
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (VAL_RANGE);
	if (ecode)
		return (ecode);
	input = stra_iteri(file, "A", 0);
	if (input != NULL)
		return (DUP_ENTITY);
	return (SUCCESS);
}

t_errors	set_camera(char **file, t_map *map)
{
	char		**args;
	char		*input;
	t_errors	ecode;

	ecode = SUCCESS;
	input = stra_iteri(file, "C", 2);
	if (!input)
		return (NOT_FOUND);
	args = ft_split_whitespcs(input);
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), ARG_NUM);
	if (ft_atoi(args[3]) > 180 || ft_atoi(args[3]) < 0)
		return (ft_free_stra(args), VAL_RANGE);
	map->camera = new_cam(get_vector(args[1], &ecode, 1),
			get_vector(args[2], &ecode, 0), ft_atoi(args[3]));
	ft_free_stra(args);
	if (ecode)
		return (ecode);
	input = stra_iteri(file, "C", 2);
	if (input != NULL)
		return (DUP_ENTITY);
	return (SUCCESS);
}

t_errors	get_obj_arr(char **file, t_map *map)
{
	t_object	*objects;
	t_errors	ecode;
	size_t		size;
	size_t		prev;

	size = 0;
	ecode = SUCCESS;
	objects = NULL;
	ecode = get_objects(&map->objects, file, "sp", &size);
	if (ecode)
		return (ecode);
	prev = size;
	ecode = get_objects(&objects, file, "cy", &size);
	if (ecode)
		return (ecode);
	map->objects = join_objs(map->objects, objects, prev, size);
	prev = size;
	ecode = get_objects(&objects, file, "pl", &size);
	if (ecode)
		return (ecode);
	map->objects = join_objs(map->objects, objects, prev, size);
	if (map->objects == NULL)
		return (NOT_FOUND);
	map->obj_count = size;
	return (SUCCESS);
}
