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
void		set_light(t_lighting *l, double ratio, u_int32_t c, t_vector *v);
void		set_amblight(t_lighting *light, double ratio, u_int32_t color);
t_vector	*get_vector(char *src, int *exit_code);
u_int32_t	get_color(char *str, int *exit_code);
// void		get_zylinder(t_list *new, char **file);
// void		get_plane(t_list *new, char **file);
void		get_sphere(t_list **new, char **file);
t_sphere	*parse_sphere(char *str, int *ecode);

#endif
