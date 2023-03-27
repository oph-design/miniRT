#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "MLX42.h"
# include "mathematic.h"
# include "graphics.h"

typedef struct s_map	t_map;

char	**get_file(char	*name);
int		check_input(int argc, char **argv);
t_map	*get_map(char **file);

#endif
