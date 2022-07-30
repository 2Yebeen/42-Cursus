# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 17:16:35 by yeblee            #+#    #+#              #
#    Updated: 2022/07/30 11:13:08 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAMEB		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

HEADERS		= includes
LIBFT		= -L./libft -lft

DIR_O		= obj
DIR_S 		= srcs
SOURCES		= main.c				\
			  ps_utils.c			\
			  ps_atoi.c				\
			  ps_push_swap.c		\
			  ps_push_swap_utils.c	\


SRCB		= main.c				\
			  ps_utils.c			\
			  ps_atoi.c				\
			  ps_push_swap.c		\
			  ps_push_swap_utils.c	\


SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
OBJB 		= $(SRCB:.c=.o)

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@ 

clean:
	@$(RM) $(DIR_O)
	@make clean -C libft

fclean:	clean
	@$(RM) $(NAME) $(NAMEB)
	@make fclean -C libft

re:	
	@make fclean 
	@make all

.PHONY: all clean fclean re bonus