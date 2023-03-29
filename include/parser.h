#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include <fcntl.h>
# include <stdio.h>
# include "objects.h"

char		*stra_iteri(char **arr, char *set, int id);
double		get_ratio(char *str, int *exit_code);
t_vector	*get_color(char *str, int *exit_code);
t_vector	*get_vector(char *src, int *exit_code);
t_object	*get_objects(char **file, size_t *size, char *set,
				t_object (parse)(char *, int *));
t_object	parse_sphere(char *str, int *ecode);
t_object	parse_cylinder(char *str, int *ecode);
t_object	parse_plane(char *str, int *ecode);
t_object	*join_objs(t_object *dst, t_object *src, size_t prev, size_t len);
int			set_camera(char **file, t_map *map);
int			get_obj_arr(char **file, t_map *map);
int			set_lighting(char **file, t_map *map);
size_t		get_size(char **file, char *set);

#endif
