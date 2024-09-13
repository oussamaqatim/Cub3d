/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:47:35 by oussama           #+#    #+#             */
/*   Updated: 2023/02/28 18:44:45 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>

# define T_S 32

# define W 13
# define S 1
# define A 0
# define D 2

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}t_color;

typedef struct s_img
{
	void	*img;
	int		*addr_i;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_raycasting
{
	double	fov;
	double	ray_angle;
	double	y_wall_hit;
	double	x_wall_hit;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;
	double	horz_distance;
	double	horz_wall_hit_x;
	double	horz_wall_hit_y;
	bool	horz_wall_found;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	double	x_vert_intercept;
	double	y_vert_intercept;
	double	x_vert_step;
	double	y_vert_step;
	double	vert_distance;
	bool	vert_wall_found;
	bool	was_hit_vert;
	double	wall_height;
	double	distance;
	double	offset_x;
	double	offset_y;
	int		p_color;
	double	wall_top;
	double	wall_bottom;
}	t_raycasting;

typedef struct s_map
{
	char			*file_map;
	char			**map;
	int				lenght;
	char			*n_texture;
	char			*s_texture;
	char			*e_texture;
	char			*w_texture;
	t_color			*f_color;
	t_color			*c_color;
	t_raycasting	*ray;
	int				flag_so;
	int				flag_no;
	int				flag_we;
	int				flag_ea;
	int				flag_f;
	int				flag_c;
	int				count;
	int				flag_r;
	char			**var;
	int				count_player;
	int				count_line;
	int				p_x;
	int				p_y;
	void			*init;
	void			*win;
	t_img			img;
	t_img			*full_img;
	int				max_len;
	int				width;
	int				height;
	int				facing_up;
	int				facing_down;
	int				facing_right;
	int				facing_left;
	t_img			*img_s;
	t_img			*img_n;
	t_img			*img_w;
	t_img			*img_e;
	int				width_txt;
	int				height_txt;
	int				walk;
	int				jnab;
	int				turn_left_right;
	double			move_speed;
	double			rotation_angle;
	double			rotation_speed;
	double			x;
	double			y;
	void			*n_txt;
	void			*s_txt;
	void			*e_txt;
	void			*w_txt;
	int				c_coleur;
	int				f_coleur;
}	t_map;

/********* Cub3D_utilis *************/

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
int		get_lenght(char *ln, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(char *str);
int		ft_isdigit(char *s);
char	*word_dup(char *str, int start, int finish);

/**************** parse ***********************/

void	ft_parsing(t_map *ptr);
int		ft_check_1_map(t_map *ptr, int i, int j);
int		ft_check(t_map *ptr, int i, int j);
void	ft_norm_no(t_map *ptr, int i, int j);
void	ft_norm_so(t_map *ptr, int i, int j);
void	ft_norm_we(t_map *ptr, int i, int j);
void	ft_norm_ea(t_map *ptr, int i, int j);
void	ft_norm_c(t_map *ptr, int i, int j);
void	ft_norm_f(t_map *ptr, int i, int j);
void	init_map(t_map *map, char *file);
void	get_angle_value(char c, t_map *var);
int		ft_check_vergule(char *str);

/**************** map : 2 ***********************/

void	check_map_b(t_map *var);
void	check_walls(t_map *var);
void	check_lines(t_map *var);
void	error_map(char *msg, t_map *var);
void	ft_take_var(t_map *map, int *index);

/**************** map : 2 ***********************/

char	**ft_split_map(t_map *map, int i, int j);
int		get_lenght_map(char *ln, int i, char c);
void	get_map_texture(t_map *ptr, char c);
void	get_colors(t_map *ptr, char **splited);
void	get_rgb(t_map *ptr, t_color *color, char *str);
int		ft_check_number(char *str);
int		ft_check_caracter(char *str);
int		ft_check_vergule(char *str);
void	check_map(t_map *map);

/********** ft_free ******************/

void	ft_error_msg(t_map *ptr);
void	ft_free_map(t_map *map);
void	ft_free_split(char **str, char *ptr);
void	get_player_postion(t_map *var, int x, int y);

/****************rendring**********************/

bool	check_if_wall(t_map *var, int next_x, int next_y);
void	put_pixel(int color, t_map *cub, int x, int y);
void	my_img_pix_put2(t_map *var, int x, int y, int color);
void	calcul_xoffset(t_map *var);
void	get_color_from_txt(t_map *var);
void	draw_txt(t_map *var, int id);
void	calcul_for_3d(t_map *var);
double	get_horz_distance(t_map *var);
double	get_vert_distance(t_map *var);
void	compare_distance_here(t_map *var);
void	compare_distance(t_map *var);
void	calcul_steps_h(t_map *var);
void	calcul_intercept_steps_h(t_map *var, double *next_x, double *next_y);
void	get_intersection_horz(t_map *var);
void	calcul_steps_v(t_map *var);
void	calcul_intercept_steps_v(t_map *var, double *next_x, double *next_y);
void	get_intersection_vert(t_map *var);
void	facing_up_down(t_map *var);
void	facing_right_left(t_map *var);
void	get_intersection(t_map *var);
void	normalizingray_angle(t_map *var);
void	rendering_3d(t_map *var);
void	draw_all(t_map *var);
void	init_rest_of_txts(t_map *var);
void	init_txt_img(t_map *var);
int		create_rgb(int r, int g, int b);
void	draw_ceil_floor(t_map *var);

/****************mouvement**********************/

void	move_player(t_map *za);
void	collide(t_map	*var, int status);
int		key_release(int key, t_map *za);
int		key_press(int key, t_map *za);
int		ft_exit(t_map *za);

#endif