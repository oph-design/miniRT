#include "parser.h"

static t_object	*realloc_arr(size_t size, t_object *src);

double	get_ratio(char *str, int *exit_code)
{
	size_t	i;

	i = 0;
	(void)(exit_code);
	while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (*exit_code = 1, 0);
	return (ft_strtod(str));
}

t_vector	*get_color(char *str, int *exit_code)
{
	char			**split;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	split = ft_split(str, ',');
	if (ft_stra_len(split) != 3)
		return (*exit_code = 1, NULL);
	if (is_number(split[0]) || is_number(split[1]) || is_number(split[2]))
		*exit_code = 1;
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r > 255 || g > 255 || b > 255)
		return (*exit_code = 1, NULL);
	ft_free_stra(split);
	return (new_vec((double)r, (double)g, (double)b));
}

t_vector	*get_vector(char *str, int *exit_code)
{
	char	**split;
	double	x;
	double	y;
	double	z;

	split = ft_split(str, ',');
	if (ft_stra_len(split) != 3)
		return (*exit_code = 1, NULL);
	x = get_ratio(split[0], exit_code);
	y = get_ratio(split[1], exit_code);
	z = get_ratio(split[2], exit_code);
	return (ft_free_stra(split), new_vec(x, y, z));
}

t_object	*get_objects(char **file, size_t *size, char *set,
	t_object (parse)(char *, int *))
{
	char			*check;
	t_object		*res;
	size_t			i;
	static int		id = 3;
	int				ecode;

	i = 0;
	ecode = 0;
	res = malloc(sizeof(t_object) * get_size(file, set));
	check = stra_iteri(file, set, id);
	while (check != NULL)
	{
		res[i] = parse(check, &ecode);
		if (ecode)
		{
			free(res[i].orientation);
			free(res[i].pos);
		}
		else
			i++;
		check = stra_iteri(file, set, id);
	}
	*size += i;
	id++;
	return (realloc_arr(i, res));
}

static t_object	*realloc_arr(size_t size, t_object *src)
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
