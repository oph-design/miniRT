#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include <fcntl.h>
# include "objects.h"

char		*stra_iteri(char **arr, char *set, int id);
size_t		ft_stra_len(char **arr);
void		ft_free_stra(char **str);
double		ft_strtod(char *str);
int			is_number(char *str);
double		get_ratio(char *str, int *exit_code);
u_int32_t	get_color(char *str, int *exit_code);
t_vector	*get_vector(char *src, int *exit_code);
t_object	*get_objects(char **file, size_t *size, char *set,
	t_object (parse)(char *, int *));
t_object	parse_sphere(char *str, int *ecode);
t_object	parse_zylinder(char *str, int *ecode);
t_object	parse_plane(char *str, int *ecode);
t_object	*join_objs(t_object *dst, t_object *src, size_t prev, size_t len);

#endif
