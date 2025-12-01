/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:49:48 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 23:32:50 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  include <X11/keysym.h>
#  define M_PI_2 1.57079632679489661923
#  define M_PI 3.14159265358979323846
# endif

# include "../lib/libft/libft.h"
# include "fcntl.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

// 4096 x 2304
// 1920 x 1080
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920

# define PLAYER_LOOK 0.05
# define PLAYER_SPEED 0.1
# define PLAYER_SIZE 9
# define DEGREE_IN_RADIANS 0.0174533

# define DOF 500
# define FOV 60
# define RAYS 1920

# ifdef __APPLE__

enum
{
	ON_DESTROY = 17,
	ON_KEY_DOWN = 2,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
};
# elif __linux__

enum
{
	ON_DESTROY = 17,
	ON_KEY_DOWN = 2,
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_A = XK_a,
	KEY_S = XK_s,
	KEY_D = XK_d,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
};
# endif

enum			e_parsing
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

typedef struct s_parsing
{
	char		*line;
	char		**checks;
	bool		*textures;
	int			cur_check;
	int			count;
	char		*tmp;
}				t_parsing;

typedef struct s_vectori //vector int for map
{
	int		x;
	int		y;
}				t_vectori;

typedef struct s_vectord //vector double for precision
{
	double	x;
	double	y;
}				t_vectord;

typedef struct s_rect
{
	t_vectord	size;
	t_vectord	pos;
	int			color;
}				t_rect;

typedef struct s_ray
{
	t_vectord	start;
	t_vectord	end;
	double		len;
	bool		vert;
	double		angle;
	int			color;
}				t_ray;

typedef struct s_image
{
	void		*image;
	void		*addr;
	int			line_len;
	int			height;
	int			width;
	int			bpp;
	int			endian;
}				t_image;

typedef struct s_map
{
	char		**str;
	int			wall_size;
	int			length;
	int			width;
}				t_map;

typedef struct s_player
{
	t_vectord	pos;
	t_vectord	delta;
	int			size;
	double		angle;
	bool		m_left;
	bool		m_right;
	bool		m_forward;
	bool		m_back;
	bool		l_left;
	bool		l_right;
	bool		map;
	bool		use;
}				t_player;

typedef struct s_paths
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	int			floor;
	int			ceiling;
}				t_paths;

typedef struct s_textures
{
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
	int			floor;
	int			ceiling;
}				t_textures;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	bool		render_map;
	t_textures	textures;
	t_image		image;
	t_map		map;
	t_player	player;
}				t_data;

void			set_mlx_image(t_image *image);

//Casting
void			cast_rays(t_player player, t_map map, t_ray *rays);

//Init
void			init(t_data *data, t_paths paths);
void			init_player(t_player *player, t_map *map);
void			init_engine(t_data *data, t_paths paths);

//Main-----------------------------------------------------

//Main
int				loop(void *param);

//Parsing
int				check_rgb(t_parsing *parse, t_paths *nsewfc);
int				check_texture_rgb(t_parsing *parse, t_paths *nsewfc);
int				check_texture_rgb2(t_parsing *parse, t_paths *nsewfc);
void			get_rgb(char *line, int *r, int *g, int *b);
char			*ft_strdup2(char *src);
char			**parser(char *map, t_paths *nsewfc);
void			check_map(char **map);
void			exit_error(char *str);

//Player
void			move_handler(t_player *player);
void			look_handler(t_player *player);

//Rendering
void			draw_background(t_image *image, t_textures textures);
void			draw_rays_3d(t_image *image, t_ray *rays, t_player player,
					t_textures textures);

//Render textures
void			draw_textured_ray(t_image *img, t_rect rect, t_ray ray,
					t_textures textures);

//Events
int				on_destroy(void *param);
int				on_key_down(int key, void *param);
int				on_key_up(int key, void *param);

//Utils----------------------------------------------------

//gnl
char			*get_next_line(int fd);

//Rendering Utils
int				create_trgb(int t, int r, int g, int b);
void			img_pix_put(t_image *img, int x, int y, unsigned int color);
void			paint_background(t_image *img, t_rect rect);

//Angle Utils
double			reset_angle(double angle);
double			calc_hyp(t_vectord side1, t_vectord side2);

#endif
