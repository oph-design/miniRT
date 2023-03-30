#include "parser.h"

static t_errors	get_lighting(char **file, t_lighting *light);
static t_errors	get_amlight(char **file, t_lighting *light);

t_errors	set_lighting(char **file, t_map *map)
{
	t_lighting	*light;
	t_errors	ecode;

	ecode = success;
	light = malloc(sizeof(t_lighting));
	if (!light)
		return (fatal);
	ecode = get_amlight(file, light);
	if (ecode)
		return (ecode);
	ecode = get_lighting(file, light);
	if (ecode)
		return (ecode);
	map->lighting = light;
	return (success);
}

static t_errors	get_lighting(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	t_errors	ecode;

	ecode = success;
	input = stra_iteri(file, "L", 1);
	if (!input)
		return (not_found);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), arg_num);
	set_light(light, get_ratio(args[2], &ecode), get_color(args[3], &ecode),
		get_vector(args[1], &ecode, 1));
	if (light->l_ratio < 0.0 || light->l_ratio > 1.0)
		return (ft_free_stra(args), val_range);
	if (ecode)
		return (ft_free_stra(args), ecode);
	input = stra_iteri(file, "L", 1);
	if (input != NULL)
		return (ft_free_stra(args), dup_entity);
	return (ft_free_stra(args), success);
}

static t_errors	get_amlight(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	t_errors	ecode;

	ecode = success;
	input = stra_iteri(file, "A", 0);
	if (!input)
		return (not_found);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), arg_num);
	set_amblight(light, get_ratio(args[1], &ecode), get_color(args[2], &ecode));
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (ft_free_stra(args), val_range);
	if (ecode)
		return (ft_free_stra(args), ecode);
	input = stra_iteri(file, "A", 0);
	if (input != NULL)
		return (ft_free_stra(args), dup_entity);
	return (ft_free_stra(args), success);
}

t_errors	set_camera(char **file, t_map *map)
{
	char		**args;
	char		*input;
	t_errors	ecode;

	ecode = success;
	input = stra_iteri(file, "C", 2);
	if (!input)
		return (not_found);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 4)
		return (ft_free_stra(args), arg_num);
	map->camera = new_cam(get_vector(args[1], &ecode, 1),
			get_vector(args[2], &ecode, 0), ft_atoi(args[3]));
	if (ecode)
		return (ft_free_stra(args), ecode);
	input = stra_iteri(file, "C", 2);
	if (input != NULL)
		return (ft_free_stra(args), dup_entity);
	return (ft_free_stra(args), success);
}

int	get_obj_arr(char **file, t_map *map)
{
	t_object	*objects;
	size_t		size;
	size_t		prev;

	size = 0;
	objects = get_objects(file, &size, "sp", parse_sphere);
	prev = size;
	objects = join_objs(objects,
			get_objects(file, &size, "pl", parse_plane), prev, size);
	prev = size;
	objects = join_objs(objects,
			get_objects(file, &size, "cy", parse_cylinder), prev, size);
	map->objects = objects;
	map->obj_count = size;
	return (EXIT_SUCCESS);
}
