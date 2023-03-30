#include "parser.h"

void	parse_error(t_errors code, char *component, t_map **map);

t_map	*get_map(char **file)
{
	t_map		*map;
	t_errors	exit_code;

	exit_code = success;
	map = malloc(sizeof(map));
	map->lighting = NULL;
	map->camera = NULL;
	map->objects = NULL;
	exit_code = set_lighting(file, map);
	parse_error(exit_code, "lighting: ", &map);
	exit_code = set_camera(file, map);
	parse_error(exit_code, "camera: ", &map);
	exit_code = get_obj_arr(file, map);
	parse_error(exit_code, "objects: ", &map);
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

void	parse_error(t_errors code, char *component, t_map **map)
{
	if (code == success)
		return ;
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(component, 2);
	if (code == fatal)
		ft_putendl_fd("fatal", 2);
	if (code == arg_num)
		ft_putendl_fd("wrong number of arguments", 2);
	if (code == val_range)
		ft_putendl_fd("wrong range of values", 2);
	if (code == no_number)
		ft_putendl_fd("invalid number", 2);
	if (code == val_num)
		ft_putendl_fd("wrong number of values", 2);
	if (code == dup_entity)
		ft_putendl_fd("duplicate occurance of entity", 2);
	if (code == not_found)
		ft_putendl_fd("non existent", 2);
	free_map(*map);
	*map = NULL;
	exit(1);
}
