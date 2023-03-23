#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

typedef enum e_type
{
	sphere,
	plain,
	zylinder
}			t_type;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

typedef struct s_lighting
{
	double		a_ratio;
	u_int32_t	a_color;
	double		l_ratio;
	u_int32_t	l_color;
	int			x;
	int			y;
	int			z;
}				t_lighting;

typedef struct s_camera
{
	unsigned int	range;
	t_vector		*vector;
	int				x;
	int				y;
	int				z;
}					t_camera;

typedef struct s_object
{
	t_type			type;
	t_vector		*vector;
	unsigned int	color;
	double			diameter;
	double			height;
	int				x;
	int				y;
	int				z;
}					t_object;

typedef struct s_map
{
	t_lighting	*lighting;
	t_camera	*camera;
	t_object	*objects;
}				t_map;

char	*stra_iteri(char **arr, char *set);
size_t	ft_stra_len(char **arr);
double	ft_strtod(char *str);

#endif
