#include "parser.h"

t_object	*realloc_arr(size_t size, t_object *src)
{
	size_t		i;
	t_object	*res;

	i = 0;
	res = malloc(size * sizeof(t_object));
	while (i < size)
	{
		res[i] = src[i];
		i++;
	}
	free(src);
	return (res);
}

size_t	get_size(char **file, char *set)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (file[i])
	{
		if (ft_strncmp(file[i], set, ft_strlen(set)))
			size++;
		i++;
	}
	return (size);
}

t_object	parse_sphere(char *str, int *ecode)
{
	char		**args;
	t_object	sphere;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 4)
		return (*ecode = 1, new_sphere(NULL, 0, 0));
	sphere = new_sphere(get_vector(args[1], ecode),
			get_ratio(args[2], ecode), get_color(args[3], ecode));
	return (sphere);
}

t_object	parse_cylinder(char *str, int *ecode)
{
	char		**args;
	double		size[2];
	t_object	cylinder;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 6)
		return (*ecode = 1, new_cylinder(NULL, NULL, size, 0));
	size[0] = get_ratio(args[3], ecode);
	size[1] = get_ratio(args[4], ecode);
	cylinder = new_cylinder(get_vector(args[1], ecode),
			get_vector(args[2], ecode), size, get_color(args[5], ecode));
	return (cylinder);
}

t_object	parse_plane(char *str, int *ecode)
{
	char		**args;
	t_object	plane;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 4)
		return (*ecode = 1, new_plane(NULL, NULL, 0));
	plane = new_plane(get_vector(args[1], ecode),
			get_vector(args[2], ecode), get_color(args[3], ecode));
	return (plane);
}
