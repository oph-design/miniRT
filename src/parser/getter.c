/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:33:21 by luntiet-          #+#    #+#             */
/*   Updated: 2023/04/26 10:33:22 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	get_ratio(char *str, int *exit_code)
{
	size_t	i;
	int		p;
	double	res;

	i = 0;
	p = 0;
	if ((str[0] == '-' || str[0] == '.') && ft_strlen(str) == 1)
		return (*exit_code = NO_NUMBER, 0);
	if (str[0] == '.')
		str = ft_strjoin("0", str);
	else
		str = ft_strdup(str);
	while (ft_isdigit(str[i]) || (str[i] == '-' && i == 0)
		|| (str[i] == '.' && !p++))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (free(str), *exit_code = NO_NUMBER, 0);
	res = ft_strtod(str);
	return (free(str), res);
}

t_vector	get_color(char *str, int *exit_code)
{
	char			**args;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	args = ft_split(str, ',');
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), *exit_code = VAL_NUM, new_vec(0, 0, 0));
	if (is_number(args[0]) || is_number(args[1]) || is_number(args[2]))
		*exit_code = NO_NUMBER;
	r = ft_atoi(args[0]);
	g = ft_atoi(args[1]);
	b = ft_atoi(args[2]);
	ft_free_stra(args);
	if (r > 255 || g > 255 || b > 255)
		return (*exit_code = VAL_RANGE, new_vec(0, 0, 0));
	return (new_vec((double)r, (double)g, (double)b));
}

t_vector	get_vector(char *str, int *exit_code, int pos)
{
	char	**args;
	double	x;
	double	y;
	double	z;

	args = ft_split(str, ',');
	if (ft_stra_len(args) != 3)
		return (ft_free_stra(args), *exit_code = VAL_NUM, new_vec(0, 0, 0));
	x = get_ratio(args[0], exit_code);
	y = get_ratio(args[1], exit_code);
	z = get_ratio(args[2], exit_code);
	ft_free_stra(args);
	if (((x > 1.0 || x < -1.0 || y > 1.0 || y < -1.0 || z > 1.0 || z < -1.0)
			|| (fabs(x) + fabs(y) + fabs(z) == 0.0)) && !pos)
		return (*exit_code = VAL_RANGE, new_vec(0, 0, 0));
	return (new_vec(x, y, z));
}
