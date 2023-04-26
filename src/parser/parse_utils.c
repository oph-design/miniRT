#include "minirt.h"

int	get_err_num(int ecode, char *str, t_count count)
{
	if (!ft_strncmp(str, "sp", 2))
		ecode = ecode + count.sp * 100;
	if (!ft_strncmp(str, "pl", 2))
		ecode = ecode + count.pl * 100;
	if (!ft_strncmp(str, "cy", 2))
		ecode = ecode + count.cy * 100;
	return (ecode);
}

char	*stra_iteri(char **arr, char *set, int id)
{
	size_t			j;
	static size_t	i[3] = {0, 0, 0};

	j = 0;
	while (arr[i[id]] != NULL)
	{
		if (!ft_strncmp(arr[i[id]] + j, set, ft_strlen(set))
			&& ft_iswhitespcs(arr[i[id]][j + ft_strlen(set)]))
			return (arr[(i[id])++]);
		j = 0;
		(i[id])++;
	}
	return (NULL);
}

int	is_object(char *str)
{
	return (!ft_strncmp(str, "A", 1) || !ft_strncmp(str, "C", 1)
		|| !ft_strncmp(str, "L", 1));
}

int	check_overflow(int ecode)
{
	if (ecode == 0)
		return (NOT_FOUND);
	return (ecode);
}
