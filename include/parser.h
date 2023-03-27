#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "objects.h"

char		*stra_iteri(char **arr, char *set);
size_t		ft_stra_len(char **arr);
double		ft_strtod(char *str);
int			is_number(char *str);
void		set_light(t_lighting *l, double ratio, u_int32_t color, t_vector *c);
void		set_amblight(t_lighting *light, double ratio, u_int32_t color);
t_vector	*get_vector(char *src, int *exit_code);
u_int32_t	get_color(char *str, int *exit_code);

#endif
