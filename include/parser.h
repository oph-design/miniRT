#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include <fcntl.h>
# include <stdio.h>
# include "objects.h"

char		*stra_iteri(char **arr, char *set, int id);
double		get_ratio(char *str, t_errors *exit_code);
t_vector	get_color(char *str, t_errors *exit_code);
t_vector	get_vector(char *str, t_errors *exit_code, int pos);
t_errors	get_objects(t_object **obj, char **file, char *set, size_t *size);
t_object	parse_sphere(char *str, t_errors *ecode);
t_object	parse_cylinder(char *str, t_errors *ecode);
t_object	parse_plane(char *str, t_errors *ecode);
t_object	*join_objs(t_object *dst, t_object *src, size_t prev, size_t len);
t_errors	set_camera(char **file, t_map *map);
t_errors	get_obj_arr(char **file, t_map *map);
t_errors	set_lighting(char **file, t_map *map);
size_t		get_size(char **file, char *set);
t_object	*realloc_arr(size_t size, t_object *src);
t_object	parse(char *str, char *set, t_errors *ecode);
int			ft_iswhitespcs(char c);

#endif
