#include "parser.h"

t_map	*get_map(char **file)
{
	t_map	*map;

	map = malloc(sizeof(map));
	if (set_lighting(file, map))
		return (free(map), NULL);
	if (set_camera(file, map))
		return (free(map), NULL);

}

int	set_lighting(char **file, t_map *map)
{
	t_lighting	*light
	char		*input;
	char		**args;

	input = stra_iteri(arr, "A");
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, ' ');
	if (ft_stra_len != 3)
		return (EXIT_FAILURE)
}
