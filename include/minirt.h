/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:34:59 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:59 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
