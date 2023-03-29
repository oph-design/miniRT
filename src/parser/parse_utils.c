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
