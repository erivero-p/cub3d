# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 13:20:42 by marirodr          #+#    #+#              #
#    Updated: 2023/11/29 12:58:22 by erivero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror -lm

LIBFT		=	libft/libft.a

MLX42		=	MLX42/libmlx42.a

SRC_DIR		=	src/
OBJ_DIR		=	objs/

#direccion de carpetas dentro de src/
#PARSE es la variable para los archivos sin extension de la carpeta de parseo
PARSE		=	parse format init map_read char_check wall_check scene_check

UTILS		=	clean_handling error_handling debug

SETTING		=	window controls

MAP			=	map

SRC			=	main.c \
				$(addsuffix .c, $(addprefix parser/, $(PARSE))) \
				$(addsuffix .c, $(addprefix utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix settings/, $(SETTING))) \
				$(addsuffix .c, $(addprefix map/, $(MAP))) \
#con la linea de arriba le añadimos primero la extension .c a los archivos, le añadimos la ruta de la carpeta donde se encuentra y llamamos a ssu variable correspondiente


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

MLX_FLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

GREEN		=	\033[0;32m
RED			=	\033[0;31m
END			=	\033[0m

RM			=	rm -rf

all: $(NAME)
$(NAME): $(OBJ)
	@make -s -C libft
	@make -s -C MLX42
	@$(CC) $(CFLAGS) $(OBJ) $(MLX42) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled ✅$(END)"
				
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
#cada vez que queramos añadir una carpeta, utilizamos una linea similar a la de abajo para dentro de la carpeta /objs ir añadiendolos todos
	@mkdir -p $(OBJ_DIR)/parser $(OBJ_DIR)/utils $(OBJ_DIR)/settings $(OBJ_DIR)/map
	@$(CC) $(FLAGS) -c $< -o $@
# no se si en la linea de arriba tenemos que llamar a $(MLX_FLAGS)


clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Compiled objects have been removed$(END)"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@make clean -C MLX42/
	@echo "$(RED)$(NAME) cleaned 🗑$(END)"

re: fclean all

.PHONY: all, clean, fclean, re