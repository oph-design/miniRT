#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include <fcntl.h>
# include <stdio.h>
# include "objects.h"

# define SUCCESS	0
# define EMPTY		1
# define IDENTIFIER	2
# define ARG_NUM	3
# define VAL_RANGE	4
# define NO_NUMBER	5
# define VAL_NUM	6
# define DUP_ENTITY	7
# define NOT_FOUND	8
# define SP_ERROR	10
# define PL_ERROR	20
# define CY_ERROR	30
# define CN_ERROR	40

char		*stra_iteri(char **arr, char *set, int id);
double		get_ratio(char *str, int *exit_code);
t_vector	get_color(char *str, int *exit_code);
t_vector	get_vector(char *str, int *exit_code, int pos);
t_object	parse_obj(char *str, int *ecode);
int			set_camera(char **file, t_map *map);
int			get_obj_arr(char **file, t_map *map);
int			set_lighting(char **file, t_map *map);
int			find_invalid_ids(char **file);
int			is_object(char *str);

#endif
