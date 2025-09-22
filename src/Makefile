# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 09:38:06 by khanakgulat       #+#    #+#              #
#    Updated: 2021/11/23 17:01:19 by khanakgulat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FILES = clean_up.c \
		cub.c \
		fill.c \
		init_graphics.c \
		pars_doubles.c \
		pars_fc.c \
		pars_map.c \
		pars_path.c \
		parsing.c \
		raycasting1.c \
		raycasting2.c \
		raycasting3.c \
		raycasting4.c \
		raycasting5.c render.c

OBJ = $(FILES:.c=.o)

# Detect OS
UNAME_S := $(shell uname -s)

# macOS specific flags
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -framework OpenGL -framework AppKit -lmlx -Lmlx
	MLX_PATH = mlx
endif

# Linux specific flags
ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = -Lmlx-linux -lmlx -lXext -lX11 -lm -lbsd
	MLX_PATH = mlx-linux
endif

all: $(NAME)

# Build target that automatically cleans up object files after successful compilation
build: $(NAME) clean-obj

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./$(MLX_PATH)
	gcc -Wall -Werror -Wextra $(OBJ) libft/libft.a $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Build successful! Executable: $(NAME)"

%.o: %.c
	gcc -Wall -Werror -Wextra -I$(MLX_PATH) -c $< -o $@

# Clean only object files (keeps libraries and executable)
clean-obj:
	@echo "🧹 Cleaning up object files..."
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./mlx clean
	make -C ./mlx-linux clean
	@echo "✅ Object files cleaned!"

clean:
	@echo "🧹 Cleaning all build artifacts..."
	make -C ./libft fclean
	make -C ./$(MLX_PATH) clean
	rm -f $(OBJ)
	@echo "✅ Clean complete!"

fclean: clean
	@echo "🧹 Full clean (including executable)..."
	rm -f $(NAME)
	@echo "✅ Full clean complete!" 

norme: 
	norminette $(FILES) libft/ || true

re: fclean all

# Quick rebuild that cleans object files automatically
rebuild: fclean build

.PHONY: all build clean clean-obj fclean norme re rebuild
