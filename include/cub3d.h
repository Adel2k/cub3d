#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

typedef struct s_texture{
	char	*north;
	char	*west;
	char	*south;
	char	*east;
}	t_texture;

typedef struct s_color{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_cub3d
{
	t_texture	*texture;
	int			F_color;
	int			C_color;
	char		*position;
	char		**map;
}	t_cub3d;

///////////////utils///////////////////
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
char	*trim(char *line);
int		is_space(char c);
char	*ft_strdup(char *s);
void	malloc_check(char *str);
void	error(char *msg);

///////////////validation///////////////////
void	init_cub(t_cub3d *cub);

///////////////validation///////////////////
int		check_filename(char *filename);

///////////////color///////////////////
int		r(int color);
int		g(int color);
int		b(int color);
int		rgb(int red, int green, int blue);

//////////////split////////////////////////
char	**ft_split(char *s, char c);


#endif