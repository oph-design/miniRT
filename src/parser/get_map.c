#include "parser.h"
#include <stdio.h>

int	set_lighting(char **file, t_map *map);
int	get_lighting(char **file, t_lighting *light);
int	get_amlight(char **file, t_lighting *light);
int	set_camera(char **file, t_map *map);

t_map	*get_map(char **file)
{
	t_map	*map;

	map = malloc(sizeof(map));
	if (set_lighting(file, map))
		return (free(map), NULL);
	if (set_camera(file, map))
		return (free(map), NULL);
	printf("%d\n", map->camera->fov);
	return (map);
}

int	set_lighting(char **file, t_map *map)
{
	t_lighting	*light;

	light = malloc(sizeof(t_lighting));
	if (!light)
		return (EXIT_FAILURE);
	if (get_amlight(file, light))
		return (EXIT_FAILURE);
	if (get_lighting(file, light))
		return (EXIT_FAILURE);
	map->lighting = light;
	return (EXIT_SUCCESS);
}

int	get_lighting(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	int			ecode;

	input = stra_iteri(file, "L", 1);
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 4)
		return (EXIT_FAILURE);
	set_light(light, get_ratio(args[2], &ecode), get_color(args[3], &ecode),
		get_vector(args[1], &ecode));
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (EXIT_FAILURE);
	if (ecode)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_amlight(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	int			ecode;

	input = stra_iteri(file, "A", 0);
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 3)
		return (EXIT_FAILURE);
	set_amblight(light, get_ratio(args[1], &ecode), get_color(args[2], &ecode));
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (EXIT_FAILURE);
	if (ecode)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	set_camera(char **file, t_map *map)
{
	char	**args;
	char	*input;
	int		ecode;

	ecode = 0;
	input = stra_iteri(file, "C", 2);
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, '\t');
	if (ft_stra_len(args) != 4)
		return (EXIT_FAILURE);
	map->camera = new_cam(get_vector(args[2], &ecode),
			get_vector(args[1], &ecode), ft_atoi(args[3]));
	if (ecode)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_objects(char **file, t_map *map)
{
	t_list	*new;
	t_list	*del;

	(void)(file);
	new = ft_lstnew(NULL);
	// get_object(new, file, "sp", new_sphere);
	// get_object(new, file, "pl", new_sphere);
	// get_object(new, file, "cy", new_sphere);
	del = new;
	new = new->next;
	ft_lstdelone(del, free);
	map->objects = new;
	return (EXIT_SUCCESS);
}
