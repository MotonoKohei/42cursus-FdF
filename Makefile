# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 07:27:23 by kmotono           #+#    #+#              #
#    Updated: 2024/11/20 10:02:21 by kmotono          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				:= fdf
FDF_H				:= fdf.h
ROOT_DIR			:= .

MLX_DIR				:= minilibx-linux
MLX					:= $(MLX_DIR)/libmlx.a -L /usr/X11/lib -lX11 -lXext -lm
LIBS				:= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR)

SRC 				:= \
	$(addprefix $(ROOT_DIR)/, \
		fdf.c \
		handle_error.c \
		init.c \
		initialize_window_and_image.c \
		window_utils.c \
		set_hooks.c \
		render.c \
		transform.c \
		my_mlx_pixel_put.c \
		bresenham.c \
		line_utils.c \
		map_utils.c \
		init_map.c \
		open_file.c \
		parse_file.c \
		rotate_point_3d.c \
		convert_to_conical.c \
		color_manager.c \
		mouse_utils.c \
		key_press.c \
		key_press_translate.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_atoi.c \
		ft_split.c \
		ft_strchr.c \
		ft_abs.c \
		ft_strlen.c \
	)

OBJ					:= $(SRC:.c=.o)

CFLAGS				:= -Wall -Wextra -Werror

all: $(NAME)

bonus: all

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)