# include "../include/cub3d.h"

int	r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	b(int color)
{
	return (color & 0xFF);
}

int	rgb(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}
