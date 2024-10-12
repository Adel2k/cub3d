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


///////////////utils///////////////////
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
char	*trim(char *line);
int		is_space(char c);
char	*ft_strdup(char *s);


///////////////validation///////////////////
int		check_filename(char *filename);

//////////////split////////////////////////
char	**ft_split(char *s);


#endif