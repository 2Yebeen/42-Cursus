# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:03:13 by yeblee            #+#    #+#              #
#    Updated: 2022/07/26 04:10:03 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = fractol

CC              = cc
FLAGS			= -O3 -Wall -Werror -Wextra
RM              = rm -rf

HEADERS         = includes
LIBFT           = -L./libft -lft
MLX				= -L./mlx -lmlx -framework OpenGL -framework AppKit

DIR_S 			= srcs
DIR_O			= obj

SOURCES         = main.c			\
				  fractol.c			\
				  fractol_draw.c	\
				  fractol_hook.c	\
				  fractol_utils.c	

SRCS			= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS            = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@make -C mlx
	@$(CC) $(FLAGS) -o $@ $^ $(LIBFT) $(MLX)
		

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@ 

clean : 
	@$(RM) $(DIR_O)
	@make clean -C libft
	@make clean -C mlx
	
fclean : clean
	@$(RM) $(NAME)
	@make fclean -C libft
re:
	@make fclean
	@make all

.PHONY: all obj clean fclean re