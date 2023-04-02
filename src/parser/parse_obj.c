#include "parser.h"

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
