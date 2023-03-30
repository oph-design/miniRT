#include "parser.h"

static t_errors	get_lighting(char **file, t_lighting *light);
static t_errors	get_amlight(char **file, t_lighting *light);

t_errors	set_lighting(char **file, t_map *map)
{
	t_lighting	*light;
	t_errors	ecode;

	ecode = SUCCESS;
	light = malloc(sizeof(t_lighting));
	if (!light)
		return (FATAL);
	ecode = get_amlight(file, light);
	if (ecode)
		return (ecode);
	ecode = get_lighting(file, light);
	if (ecode)
		return (ecode);
	map->lighting = light;
	return (SUCCESS);
}

static t_errors	get_lighting(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	t_errors	ecode;

	ecode = SUCCESS;
	input = stra_iteri(file, "L\t", 1);
	if (!input)
		return (NOT_FOUND);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), ARG_NUM);
	set_light(light, get_ratio(args[2], &ecode), get_color(args[3], &ecode),
		get_vector(args[1], &ecode, 1));
	if (light->l_ratio < 0.0 || light->l_ratio > 1.0)
		return (ft_free_stra(args), VAL_RANGE);
	if (ecode)
		return (ft_free_stra(args), ecode);
	input = stra_iteri(file, "L\t", 1);
	if (input != NULL)
		return (ft_free_stra(args), DUP_ENTITY);
	return (ft_free_stra(args), SUCCESS);
}

static t_errors	get_amlight(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	t_errors	ecode;

	ecode = SUCCESS;
	input = stra_iteri(file, "A\t", 0);
	if (!input)
		return (NOT_FOUND);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), ARG_NUM);
	set_amblight(light, get_ratio(args[1], &ecode), get_color(args[2], &ecode));
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (ft_free_stra(args), VAL_RANGE);
	if (ecode)
		return (ft_free_stra(args), ecode);
	input = stra_iteri(file, "A\t", 0);
	if (input != NULL)
		return (ft_free_stra(args), DUP_ENTITY);
	return (ft_free_stra(args), SUCCESS);
}

t_errors	set_camera(char **file, t_map *map)
{
	char		**args;
	char		*input;
	t_errors	ecode;

	ecode = SUCCESS;
	input = stra_iteri(file, "C\t", 2);
	if (!input)
		return (NOT_FOUND);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), ARG_NUM);
	map->camera = new_cam(get_vector(args[1], &ecode, 1),
			get_vector(args[2], &ecode, 0), ft_atoi(args[3]));
	if (map->camera->fov > 180 || map->camera->fov < 0)
		return (VAL_RANGE);
	if (ecode)
		return (ft_free_stra(args), ecode);
	input = stra_iteri(file, "C\t", 2);
	if (input != NULL)
		return (ft_free_stra(args), DUP_ENTITY);
	return (ft_free_stra(args), SUCCESS);
}

t_errors	get_obj_arr(char **file, t_map *map)
{
	t_object	*objects;
	size_t		size;
	size_t		prev;

	size = 0;
	objects = get_objects(file, &size, "sp\t", parse_sphere);
	if (objects == NULL)
		return (size);
	prev = size;
	objects = join_objs(objects,
			get_objects(file, &size, "pl\t", parse_plane), prev, size);
	if (objects == NULL)
		return (size);
	prev = size;
	objects = join_objs(objects,
			get_objects(file, &size, "cy\t", parse_cylinder), prev, size);
	if (objects == NULL)
		return (size);
	map->objects = objects;
	map->obj_count = size;
	return (SUCCESS);
}
