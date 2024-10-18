#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_player
{
	int		x;
	int		y;
	char	pos;
	bool	flag;
}	t_player;

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

typedef struct s_map
{
	char			*line;
	int				index;
	int				len;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_cub3d
{
	int			F_color;
	int			C_color;
	int			texture_flag;
	char		*position;
	bool		first_last_line;
	int			height;
	t_texture	*texture;
	t_map		**map;
	t_player	*player;
}	t_cub3d;

///////////////utils///////////////////
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
char	*trim(char *line);
int		ft_min(int num1, int num2);

///////////////utils2///////////////////
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

///////////////validation///////////////////
void	parsing(t_cub3d *cub, int fd);
void	parsing_map(char *line, t_cub3d *cub);
int		validating_color(t_cub3d *cub, char **args);
int		validating_texture(t_cub3d *cub, char **args);
void	reading_map(t_cub3d *cub, int fd);

///////////////draw_utils///////////////////
int		rgb(int red, int green, int blue);

//////////////split////////////////////////
char	**ft_split(char *s, char c);

//////////////list_utils////////////////////////
t_map	*lstlast(t_map *node);
void	add_node(char *line, t_cub3d *cub);
int		count_nodes(t_map **map);

//////////////checkings////////////////////////
int		check_walls(t_cub3d *cub, char *line, int j);
int		check_filename(char *filename);
int		is_space(char c);
int		find_player(t_cub3d *cub, int i);

//////////////error&free////////////////////////
void	malloc_check(char *str);
void	error(char *msg);

//////////////init////////////////////////
void	init_cub(t_cub3d *cub);




#endif