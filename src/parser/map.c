#include "parser.h"

t_map	*get_map(char **file)
{
	t_map	*map;

	map = malloc(sizeof(map));
	if (set_lighting(file, map))
		return (free(map), ft_free_stra(file), NULL);
	if (set_camera(file, map))
		return (free(map), ft_free_stra(file), NULL);
	if (get_obj_arr(file, map))
		return (free(map), ft_free_stra(file), NULL);
	return (ft_free_stra(file), map);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free(map->camera);
	free(map->objects);
	free(map);
}
