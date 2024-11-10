#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

# define ESC 53
# define M 46
# define E 14
# define W 13
# define A 0
# define S 1
# define D 2
# define LARROW 123
# define RARROW 124

# define AROTATE 0.07
# define MROTATE 0.03
# define WSPEED 0.15
# define SSPEED 0.1
# define ADSPEED 0.12

# define MAP_WIDTH 36
# define MAP_HEIGHT 11
# define TILE_SIZE 10

typedef struct s_player
{
	int		x;
	int		y;
	char	pos;
	bool	flag;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		height;
	int		width;
}	t_mlx;

typedef struct s_map
{
	char			*line;
	int				index;
	int				len;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_img
{
	int		wd;
	int		ht;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	char	*addr;
	void	*img;
}	t_img;

typedef struct s_raycasting
{
	int		hit;
	int		side;
	double	ray_x;
	double	ray_y;
	double	camera_x;
	double	sdist_x;
	double	sdist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perp_wall_dist;
}	t_raycasting;

typedef struct s_cub3d
{
	int			F_color;
	int			C_color;
	int			hiding_map;
	int			texture_flag;
	char		*position;
	bool		first_last_line;
	int			height;
	t_raycasting	ray;
	t_img		img;
	t_img		*gun;
	t_img		*wall;
	t_img		cdoor;
	t_img		odoor;
	t_mlx		mlx;
	t_texture	*texture;
	t_map		**map;
	t_player	player;
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


//////////////move_keys////////////////////////
int		mouse_move(int x, int y, t_cub3d *cub);
int		key_press(int key, t_cub3d *cub);

//////////////game////////////////////////
void	start_game(t_cub3d cub);

//////////////starting_game////////////////////////
int		re_draw(t_cub3d *cub);
void	init_img_info(t_cub3d *cub);

//////////////exiting////////////////////////
int		press(t_cub3d *cub);

//////////////drawing////////////////////////
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	my_mlx_color_taker(t_img *data, int j, int i);

#endif