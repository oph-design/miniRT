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
	t_lighting	*light;
	char		*input;
	char		**args;

	input = stra_iteri(file, "A");
	if (!input)
		return (EXIT_FAILURE);
	args = ft_split(input, ' ');
	if (ft_stra_len != 3)
		return (EXIT_FAILURE);
	light = malloc(sizeof(t_lighting));
	light->a_ratio = normilized(input[0]);
	light->a_color =

}

double	normilized(char *str)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	if (!ft_digit(str[i]) || str[i + 1])
		return (2.0);
	return (ft_strtod(str));
}

u_int32_t	get_color(char *str)
{
	char			**split;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	u_int32_t		res;

	split = ft_split(str, ',');
	if (ft_stra_len(split) != 3)
		return (0);
	if (is_number(str[0]) || is_number(str[1]) || is_number(str[2]))
		return (0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r > 255 || g > 255 || b > 255)
		return (0);
	res = r << 16;
	res += g << 8;
	res += b;
	ft_free_stra(split);
	return (res);
}
