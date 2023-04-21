#include "parser.h"

t_object	parse_sphere(char *str, int *ecode)
{
	char		**args;
	t_object	sphere;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 4)
		return (*ecode = ARG_NUM, ft_free_stra(args),
			new_sphere(new_vec(0, 0, 0), 0, new_vec(0, 0, 0)));
	sphere = new_sphere(get_vector(args[1], ecode, 1),
			get_ratio(args[2], ecode), get_color(args[3], ecode));
	return (ft_free_stra(args), sphere);
}

t_object	parse_cylinder(char *str, int *ecode)
{
	char		**args;
	double		size[2];
	t_object	cylinder;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 6)
		return (*ecode = ARG_NUM, ft_free_stra(args),
			new_cylinder(new_vec(0, 0, 0), new_vec(0, 0, 0),
				size, new_vec(0, 0, 0)));
	size[0] = get_ratio(args[3], ecode);
	size[1] = get_ratio(args[4], ecode);
	cylinder = new_cylinder(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), size, get_color(args[5], ecode));
	return (ft_free_stra(args), cylinder);
}

t_object	parse_plane(char *str, int *ecode)
{
	char		**args;
	t_object	plane;

	args = ft_split_whitespcs(str);
	if (ft_stra_len(args) != 4)
		return (*ecode = 2, ft_free_stra(args), new_plane(new_vec(0, 0, 0),
				new_vec(0, 0, 0), new_vec(0, 0, 0)));
	plane = new_plane(get_vector(args[1], ecode, 1),
			get_vector(args[2], ecode, 0), get_color(args[3], ecode));
	return (ft_free_stra(args), plane);
}

t_object	parse(char *str, int *ecode)
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
