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

t_object	*realloc_arr(size_t size, t_object *src)
{
	size_t		i;
	t_object	*res;

	i = 0;
	if (src == NULL)
		return (NULL);
	res = malloc(size * sizeof(t_object));
	while (i < size)
	{
		res[i] = src[i];
		i++;
	}
	free(src);
	printf("unehre\n");
	return (res);
}

t_object	parse(char *str, t_errors *ecode)
{
	char	*set;

	set = ft_substr(str, 0, 2);
	if (!ft_strncmp(set, "sp", 3))
		return (free(set), parse_sphere(str, ecode));
	if (!ft_strncmp(set, "cy", 3))
		return (free(set), parse_cylinder(str, ecode));
	if (!ft_strncmp(set, "pl", 3))
		return (free(set), parse_plane(str, ecode));
	return (free(set), parse_sphere(str, ecode));
}

int	is_object(char *str)
{
	return (!ft_strncmp(str, "A", 1) || !ft_strncmp(str, "C", 1)
		|| !ft_strncmp(str, "L", 1));
}
