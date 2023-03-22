#include "graphics.h"

static void	window_panic(mlx_t *mlx)
{
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

void	setup_window(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		window_panic(mlx);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		window_panic(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
