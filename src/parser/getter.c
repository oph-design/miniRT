#include "parser.h"
#include <stdio.h>

double	get_ratio(char *str, int *exit_code)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (*exit_code = 1, 0);
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
		return (printf("hello2\n"), *exit_code = 1, NULL);
	x = get_ratio(split[0], exit_code);
	y = get_ratio(split[1], exit_code);
	z = get_ratio(split[2], exit_code);
	return (new_vec(x, y, z));
}

void	get_object(t_list *new, char **f, char *s, void *(*get)(char *, int *))
{
	char		*check;
	int			ecode;
	static int	i = 3;

	check = stra_iteri(f, s, i);
	while (check != NULL)
	{
		ft_lstadd_back(&new, get(check, &ecode));
		if (ecode)
			ft_lstdelone(ft_lstlast(new), free);
		check = stra_iteri(f, s, i);
	}
	i++;
}
