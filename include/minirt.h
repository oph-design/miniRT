#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "MLX42.h"
# include <fcntl.h>
# include "mathematic.h"
# include "graphics.h"
# include "key_input.h"

typedef struct s_map	t_map;

char	**get_file(int fd);
int		check_input(int argc, char **argv);
t_map	*get_map(char **file);
void	free_map(t_map *map);

#endif
