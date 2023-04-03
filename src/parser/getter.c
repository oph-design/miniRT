#include "parser.h"

double	get_ratio(char *str, t_errors *exit_code)
{
	size_t	i;

	i = 0;
	(void)(exit_code);
	while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (*exit_code = NO_NUMBER, 0);
	return (ft_strtod(str));
}

t_vector	get_color(char *str, t_errors *exit_code)
{
	char			**args;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	args = ft_split(str, ',');
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), *exit_code = VAL_NUM, new_vec(0, 0, 0));
	if (is_number(args[0]) || is_number(args[1]) || is_number(args[2]))
		*exit_code = NO_NUMBER;
	r = ft_atoi(args[0]);
	g = ft_atoi(args[1]);
	b = ft_atoi(args[2]);
	ft_free_stra(args);
	if (r > 255 || g > 255 || b > 255)
		return (*exit_code = VAL_RANGE, new_vec(0, 0, 0));
	return (new_vec((double)r, (double)g, (double)b));
}

t_vector	get_vector(char *str, t_errors *exit_code, int pos)
{
	char	**args;
	double	x;
	double	y;
	double	z;

	args = ft_split(str, ',');
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), *exit_code = VAL_NUM, new_vec(0, 0, 0));
	x = get_ratio(args[0], exit_code);
	y = get_ratio(args[1], exit_code);
	z = get_ratio(args[2], exit_code);
	ft_free_stra(args);
	if (!pos)
		if (x > 1.0 || x < -1.0 || y > 1.0 || y < -1.0 || z > 1.0 || z < -1.0)
			return (*exit_code = VAL_RANGE, new_vec(0, 0, 0));
	return (new_vec(x, y, z));
}

t_errors	get_objects(t_object **obj, char **file, char *set, size_t *size)
{
	char		*check;
	size_t		i;
	static int	id = 3;
	t_errors	ecode;

	i = 0;
	*obj = NULL;
	ecode = SUCCESS;
	check = stra_iteri(file, set, id);
	if (check != NULL)
		*obj = malloc(sizeof(t_object) * get_size(file, set));
	while (check != NULL)
	{
		obj[0][i++] = parse(check, set, &ecode);
		if (ecode)
			return (free(*obj), *obj = NULL, ecode);
		check = stra_iteri(file, set, id);
	}
	*obj = realloc_arr(i, *obj);
	*size += i;
	id++;
	return (ecode);
}
