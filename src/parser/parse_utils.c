#include "parser.h"

char	*stra_iteri(char **arr, char *set, int id)
{
	size_t			j;
	static size_t	i[5] = {0, 0, 0, 0, 0};

	j = 0;
	while (arr[i[id]] != NULL)
	{
		while (arr[i[id]][j] == 32 || (arr[i[id]][j] > 9 && arr[i[id]][j] < 13))
			j++;
		if (!ft_strncmp(arr[i[id]] + j, set, ft_strlen(set)))
			return (arr[(i[id])++]);
		j = 0;
		(i[id])++;
	}
	return (NULL);
}

size_t	ft_stra_len(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}

double	ft_strtod(char *str)
{
	char	**split;
	double	pre;
	double	post;
	double	res;

	if (!ft_strchr(str, '.'))
		return ((double)ft_atoi(str));
	split = ft_split(str, '.');
	pre = (double)ft_atoi(split[0]);
	post = (double)ft_atoi(split[1]);
	res = pre + ((double)(1 / (10 * (ft_strlen(split[1])))) *post);
	return (res);
}

int	is_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_stra(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	str = NULL;
}
