/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:28:24 by kmotono           #+#    #+#             */
/*   Updated: 2024/11/20 11:59:58 by kmotono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_HEIGHT 960
# define WIN_WIDTH 1280
# define HEIGHT_SCALE 5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int		i;
	int		j;
	int		k;
	int		color;
}			t_point;

typedef struct s_pair_points
{
	t_point	*point1;
	t_point	*point2;
}			t_pair_points;

typedef struct s_map
{
	int		**grid;
	int		width;
	int		height;
	int		max_level;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img_data;
	int		win_height;
	int		win_width;
	int		scale;
	int		height_scale;
	float	angle_i;
	float	angle_j;
	float	angle_k;
	int		translate_i;
	int		translate_j;
	t_map	*map;
	int		is_dragging;
	int		prev_i;
	int		prev_j;
	int		conical_mode;
}			t_vars;

typedef struct s_line_params
{
	double	t;
	int		di;
	int		dj;
	int		increment;
	int		adjustment;
	int		i;
	int		j;
}			t_line_params;

void		handle_error(const char *message);

void		validate_input(int argc);
void		initialize_mlx(t_vars *vars);
void		initialize_vars(t_vars *vars, t_map *map, const char *filename);

void		initialize_window_and_image(t_vars *vars);
void		set_hooks(t_vars *vars);

void		create_window(t_vars *vars);
void		allocate_image_data(t_vars *vars);
void		create_image(t_vars *vars);
void		get_image_data_address(t_vars *vars);
int			close_window(t_vars *vars);

void		my_mlx_pixel_put(t_vars *vars, int i, int j, int color);
void		draw_image(t_vars *vars);
void		clear_image(t_vars *vars, int color);
void		init_point(t_point *point, int i, int j, int k);

void		scale_point(t_vars *vars, t_point *point);
void		translate_point(t_vars *vars, t_point *point);

void		scale_point(t_vars *vars, t_point *point);
void		translate_point(t_vars *vars, t_point *point);
void		rotate_point_3d(t_vars *vars, t_point *point);
void		convert_to_conical(t_vars *vars, t_point *point);

void		draw_image_line(t_vars *vars, t_point *point1, t_point *point2);
double		calculate_t(int current, int start, int end);

void		initialize_line_params_low(t_line_params *params, t_point *point1,
				t_point *point2);
void		initialize_line_params_high(t_line_params *params, t_point *point1,
				t_point *point2);
void		draw_line_low(t_vars *vars, t_point *point1, t_point *point2);
void		draw_line_high(t_vars *vars, t_point *point1, t_point *point2);
void		swap_points(t_point **point1, t_point **point2);

int			get_color(int k);
int			interpolate_color(int color1, int color2, double t);

void		init_map(const char *filename, t_map *map);
void		parse_file(const char *filename, t_map *map);
int			open_file(const char *filename);
int			calc_max_level(t_map *map);
void		free_map(t_map *map, int count);

int			mouse_press(int button, int j, int i, t_vars *vars);
int			mouse_release(int button, int j, int i, t_vars *vars);
int			mouse_move(int j, int i, t_vars *vars);

int			key_press(int keycode, t_vars *vars);
int			key_press_translate(int keycode, t_vars *vars);

int			ft_atoi(const char *str);
char		**ft_split(const char *s, char c);
char		*ft_strchr(const char *str, int c);
int			ft_abs(int value);
size_t		ft_strlen(const char *s);

#endif
