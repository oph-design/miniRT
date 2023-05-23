/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:34:19 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:20 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	print_stuff(t_map *map);

int	main(int argc, char **argv)
{
	char	**file;
	int		fd;
	t_map	*map;

	if (check_input(argc, argv))
		return (EXIT_FAILURE);
	fd = open(argv[1], 0);
	if (fd == -1)
		return (ft_putendl_fd("Error: file: not accessable", 2), 1);
	file = get_file(fd);
	map = get_map(file);
	setup_window(map);
	free_map(map);
	return (EXIT_SUCCESS);
}

void	print_stuff(t_map *map)
{
	int	i;

	i = -1;
	while (++i < (int)map->light_count)
	{
		printf("\nLight POS	 : %f	%f	%f\n\n", map->lighting[i].pos.x,
			map->lighting[i].pos.y, map->lighting[i].pos.z);
	}
	i = -1;
	while (++i < (int)map->obj_count)
	{
		printf("Object POS %d: %f	%f	%f\n", i + 1, map->objects[i].pos.x,
			map->objects[i].pos.y, map->objects[i].pos.z);
		printf("Color		%d: %f	%f	%f\n\n", i + 1, map->objects[i].color.x,
			map->objects[i].color.y, map->objects[i].color.z);
	}
}
