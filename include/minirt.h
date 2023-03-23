#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "MLX42.h"
# include <fcntl.h>

void	setup_window(void);
int		check_input(int argc, char **argv);
char	**get_file(char	*name);

#endif
