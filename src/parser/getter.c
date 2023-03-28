#include "parser.h"
#include <stdio.h>

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

void	get_sphere(t_list **new, char **file)
{
	char		*check;
	int			ecode;

	ecode = 0;
	check = stra_iteri(file, "sp", 2);
	while (check != NULL)
	{
		ft_lstadd_back(new, ft_lstnew(parse_sphere(check, &ecode)));
		if (ecode)
			ft_lstdelone(ft_lstlast(*new), free);
		check = stra_iteri(file, "sp", 2);
	}
}

// void	get_plane(t_list *new, char **file)
// {
// 	char	*check;
// 	int		ecode;

// 	check = stra_iteri(file, "pl", 3);
// 	while (check != NULL)
// 	{
// 		ft_lstadd_back(&new, get(check, &ecode));
// 		if (ecode)
// 			ft_lstdelone(ft_lstlast(new), free_sphere);
// 		check = stra_iteri(file, "pl", 3);
// 	}
// 	i++;
// }

// void	get_zylinder(t_list *new, char **file)
// {
// 	char	*check;
// 	int		ecode;

// 	check = stra_iteri(file, "zy", 4);
// 	while (check != NULL)
// 	{
// 		ft_lstadd_back(&new, get(check, &ecode));
// 		if (ecode)
// 			ft_lstdelone(ft_lstlast(new), free_sphere);
// 		check = stra_iteri(file, "zy", 4);
// 	}
// 	i++;
// }

t_sphere	*parse_sphere(char *str, int *ecode)
{
	char		**args;
	t_sphere	*sphere;

	args = ft_split(str, '\t');
	if (ft_stra_len(args) != 4)
		return (*ecode = 1, new_sphere(NULL, 0, 0));
	sphere = new_sphere(get_vector(args[1], ecode),
			get_ratio(args[2], ecode), get_color(args[3], ecode));
	return (sphere);
}
