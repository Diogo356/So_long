/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:06 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/06 15:12:49 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

//gnl
# define BUFFER_SIZE 1

//images 50x50 pixels
# define IMG_SIZE 50

//defaut to X11
# define KEYPRESS 2
# define ON_DESTROY 17

//hexa code keys 
# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b

// code arrow keys
# define AW_L 65361
# define AW_UP 65362
# define AW_R 65363
# define AW_DN 65364

// mlx
typedef struct s_mlx_pointer
{
	void	*mlx;
	void	*mlx_window;
}	t_mlx_p;

//coord space
typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

// struct images mlx 
typedef struct s_images_datas
{
	void	*img;
}	t_img;

//pt to images
typedef struct s_draw_objs
{
	t_img	wall;
	t_img	exit;
	t_img	collect;
	t_img	player;
	t_img	empty;
}	t_draw;

// objects maps
typedef struct s_validmap
{
	int	c;
	int	p;
	int	e;
}	t_valmp;

// elements maps
typedef struct s_map
{
	char	**map;
	char	**b_map;
	t_pos	position_pl;
	int		line;
	int		col;
	int		item;
}	t_map;

// big struct os structs
typedef struct so_long
{
	t_mlx_p	pt_mlx;
	t_map	map;
	t_draw	image;
	t_valmp	vmap;
	int		steps;
	int		collect;
	int		exit;
	int		w_width;
	int		w_heigth;
	int		end_game;
}	t_long;

// utils
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_strstr(const char *s1, const char *s2);
void	ft_putchar(char c);
// gnl
char	*get_next_line(int fd);
// init
void	init_map(t_map *map);
void	init_validate_map(t_valmp *vmap);
// read 
char	**read_maps(char **argv);
// check
int		check_maps(char **argv, t_long *game);
int		check_arguments(int argc, char **argv);
int		validate_itens_map(t_long *game);
int		validate_caracters_map(t_long *game);
// check2
int		map_square(t_long *game);
int		check_wall(t_long *game);
// valid_way
int		valid_way(t_long *game);
// window
int		window(t_long *game);
int		destroyer_window(t_long *game);
// game 
void	game_work(t_long *game);
// move
void	move_player(t_long *game, int keycode, int col, int line);
// clear_map
void	free_matrix_map(t_long *game);

#endif
