# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:03:13 by yeblee            #+#    #+#              #
#    Updated: 2022/07/24 23:07:03 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = fractol

CC              = cc
FLAGS			= -O3 -Wall -Wextra -Werror
RM              = rm -rf

HEADERS         = includes
LIBFT           = libft
MLX				= mlx

DIR_S 			= srcs
DIR_O			= obj

SOURCES         = main.c	\
				  fractal.c	\
				  ft_hook.c	\
				  ft_utils.c

SRCS			= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS            = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
		@make -C $(LIBFT)
		@make -C $(MLX)
		@$(CC) $(FLAGS) -o $@ $^ -L $(LIBFT) -lft -L $(MLX) -lmlx -framework OpenGL -framework Appkit
		

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
			@mkdir -p $(DIR_O)
			@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@ 

clean : 
		@$(RM) $(DIR_O)
		@make clean -C $(LIBFT)
		@make clean -C $(MLX)

fclean : clean
		@$(RM) $(NAME)
		@make fclean -C $(LIBFT)

re:
		@make fclean
		@make all

.PHONY: all obj clean fclean re