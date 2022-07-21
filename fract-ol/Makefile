# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:03:13 by yeblee            #+#    #+#              #
#    Updated: 2022/07/21 14:46:30 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = fractol

CC              = cc

RM              = rm -rf

INCDIR          = include
LIBFT           = libft
MLX				= mlx

SRCS            = src/fractol.c

OBJS            = $(SRCS:.c=.o)

%.o : %.c
		$(CC) -c $< -o $@

$(NAME) : $(OBJS)
		make -C ./mlx
		# $(CC) -o $(NAME) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -framework OpenGL -framework Appkit $(OBJS) -O
		$(CC) -o $(NAME) -L./$(MLX) -lmlx -framework OpenGL -framework Appkit $(OBJS) -O

all : $(NAME)

clean : 
		$(RM) $(OBJS)
		# @make clean -C $(LIBFT)
		@make clean -C $(MLX)

fclean : clean
		$(RM) $(NAME)
		# @make fclean -C $(LIBFT)

re:     clean all

.PHONY: all clean fclean re