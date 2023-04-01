#include "parser.h"

void	parse_error(t_errors code, char *component, t_map **map);

t_map	*get_map(char **file)
{
	t_map		*map;
	t_errors	exit_code;

	exit_code = SUCCESS;
	map = malloc(sizeof(t_map));
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
	if (code == SUCCESS)
		return ;
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(component, 2);
	if (code == FATAL)
		ft_putendl_fd("fatal", 2);
	if (code == ARG_NUM)
		ft_putendl_fd("wrong number of arguments", 2);
	if (code == VAL_RANGE)
		ft_putendl_fd("wrong range of values", 2);
	if (code == NO_NUMBER)
		ft_putendl_fd("invalid number", 2);
	if (code == VAL_NUM)
		ft_putendl_fd("wrong number of values", 2);
	if (code == DUP_ENTITY)
		ft_putendl_fd("duplicate occurance of entity", 2);
	if (code == NOT_FOUND)
		ft_putendl_fd("non existent", 2);
	free_map(*map);
	*map = NULL;
	exit(EXIT_FAILURE);
}
