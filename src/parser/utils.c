#include "parser.h"

char	*stra_iteri(char **arr, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
	{
		while (arr[i][j] == 32 || (arr[i][j] > 9 && arr[i][j] < 13))
			j++;
		if (!strncmp(arr[i] + j, set, ft_strlen(set) + 1))
			return (arr[i]);
		j = 0;
		i++;
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
	printf("%f\n", c);
	return (n + c);
}
