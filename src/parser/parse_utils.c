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
	size_t	i;
	double	n;
	double	c;

	n = 0;
	c = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	i = ft_strlen(str) - 1;
	while (ft_isdigit(str[i]))
	{
		c = c * (0.1) + ((str[i] - '0') * 0.1);
		i--;
	}
	return (n + c);
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
