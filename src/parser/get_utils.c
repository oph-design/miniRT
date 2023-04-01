#include "parser.h"

size_t	get_size(char **file, char *set)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	while (file[i])
	{
		while (file[i][j] && ft_iswhitespcs(file[i][j]))
			j++;
		if (ft_strncmp(file[i] + j, set, ft_strlen(set)))
			size++;
		j = 0;
		i++;
	}
	return (size);
}

t_object	parse_sphere(char *str, t_errors *ecode)
{
	char		**args;
	t_object	sphere;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 4)
		return (*ecode = 1, new_sphere(new_vec(0, 0, 0), 0, new_vec(0, 0, 0)));
	sphere = new_sphere(get_vector(args[1], ecode, 1),
			get_ratio(args[2], ecode), get_color(args[3], ecode));
	return (sphere);
}

t_object	parse_cylinder(char *str, t_errors *ecode)
{
	char		**args;
	double		size[2];
	t_object	cylinder;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 6)
		return (*ecode = 1, new_cylinder(new_vec(0, 0, 0), new_vec(0, 0, 0),
				size, new_vec(0, 0, 0)));
	size[0] = get_ratio(args[3], ecode);
	size[1] = get_ratio(args[4], ecode);
	cylinder = new_cylinder(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), size, get_color(args[5], ecode));
	return (cylinder);
}

t_object	parse_plane(char *str, t_errors *ecode)
{
	char		**args;
	t_object	plane;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 4)
		return (*ecode = 1, new_plane(new_vec(0, 0, 0),
				new_vec(0, 0, 0), new_vec(0, 0, 0)));
	plane = new_plane(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), get_color(args[3], ecode));
	return (plane);
}

t_object	*join_objs(t_object *dst, t_object *src, size_t prev, size_t len)
{
	size_t		i;
	t_object	*res;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == NULL && src)
		return (src);
	if (dst && src == NULL)
		return (dst);
	res = malloc(sizeof(t_object) * len);
	while (i < prev)
	{
		res[i] = dst[i];
		i++;
	}
	while (i < len)
	{
		res[i] = src[i - prev];
		i++;
	}
	free(dst);
	free(src);
	return (res);
}
