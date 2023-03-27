#include "parser.h"

int	set_lighting(char **file, t_map *map);
int	get_lighting(char **file, t_lighting *light);
int	get_amlight(char **file, t_lighting *light);

t_map	*get_map(char **file)
{
	t_map	*map;

	map = malloc(sizeof(map));
	if (set_lighting(file, map))
		return (free(map), NULL);
	// if (set_camera(file, map))
	// 	return (free(map), NULL);
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

	input = stra_iteri(file, "L");
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, ' ');
	if (ft_stra_len(args) != 4)
		return (EXIT_FAILURE);
	set_light(light, get_ratio(args[2], &ecode), get_color(args[3], &ecode),
		get_vector(args[1], &ecode));
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (EXIT_FAILURE);
	input = stra_iteri(file, "L");
	if (input || ecode)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_amlight(char **file, t_lighting *light)
{
	char		*input;
	char		**args;
	int			ecode;

	input = stra_iteri(file, "A");
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, ' ');
	if (ft_stra_len(args) != 3)
		return (EXIT_FAILURE);
	set_amblight(light, get_ratio(args[1], &ecode), get_color(args[2], &ecode));
	if (light->a_ratio < 0.0 || light->a_ratio > 1.0)
		return (EXIT_FAILURE);
	input = stra_iteri(file, "A");
	if (input || ecode)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
