#include "graphics.h"

double	g_light[3] = {30, 30, -50};

void	draw_pixel(t_window *window, int x, int y, uint32_t color)
{
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
		mlx_put_pixel(window->image, x, y, color);
}

void	draw(t_window *window)
{
	(void)window;
}
