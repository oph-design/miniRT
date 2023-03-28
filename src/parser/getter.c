#include "parser.h"
#include <stdio.h>

size_t	get_size(char **file, char *set);
t_object	*realloc_arr(size_t size, t_object *src);

double	get_ratio(char *str, int *exit_code)
{
	size_t	i;

	i = 0;
	(void)(exit_code);
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	// if (str[i] && !ft_isdigit(str[i]))
	// 	return (*exit_code = 1, 0);
	return (ft_strtod(str));
}

u_int32_t	get_color(char *str, int *exit_code)
{
	char			**split;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	u_int32_t		res;

	split = ft_split(str, ',');
	if (ft_stra_len(split) != 3)
		return (*exit_code = 1, 0);
	if (is_number(split[0]) || is_number(split[1]) || is_number(split[2]))
		*exit_code = 1;
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r > 255 || g > 255 || b > 255)
		return (*exit_code = 1, 0);
	res = r << 24;
	res += g << 16;
	res += b << 8;
	res += 255;
	ft_free_stra(split);
	return (res);
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
	return (new_vec(x, y, z));
}

t_object	*get_sphere(char **file, size_t *size)
{
	char		*check;
	t_object	*res;
	size_t		i;
	int			ecode;

	i = 0;
	ecode = 0;
	res = malloc(sizeof(t_object) * get_size(file, "sp"));
	check = stra_iteri(file, "sp", 2);
	while (check != NULL)
	{
		res[i] = parse_sphere(check, &ecode);
		if (ecode)
		{
			free(res[i].orientation);
			free(res[i].pos);
		}
		else
			i++;
		check = stra_iteri(file, "sp", 2);
	}
	*size += i;
	return (realloc_arr(i, res));
}
