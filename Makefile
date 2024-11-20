# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmotono <kmotono@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 07:27:23 by kmotono           #+#    #+#              #
#    Updated: 2024/11/20 11:41:38 by kmotono          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				:= fdf
FDF_H				:= fdf.h
ROOT_DIR			:= .

MLX_DIR				:= minilibx-linux
MLX_LIB_PATH		:= $(MLX_DIR)/libmlx.a
MLX_INCLUDE_PATH	:= -L /usr/X11/lib
MLX_FLAGS			:= -lX11 -lXext -lm
MLX_BUILT			:= $(MLX_DIR)/.mlx_built
LIBS				:= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR)

SRC 				:= \
	$(addprefix $(ROOT_DIR)/, \
		fdf.c \
		handle_error.c \
		init.c \
		initialize_window_and_image.c \
		window_utils.c \
		close_window.c \
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

$(NAME): $(OBJ) $(MLX_LIB_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB_PATH) $(MLX_INCLUDE_PATH) $(MLX_FLAGS) -o $(NAME)
	touch $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(MLX_BUILT)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

$(MLX_LIB_PATH): $(MLX_BUILT)

$(MLX_BUILT):
	make -C $(MLX_DIR)
	touch $(MLX_BUILT)

.PHONY: all clean fclean re bonus $(MLX)