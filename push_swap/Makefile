# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 13:06:40 by yeblee            #+#    #+#              #
#    Updated: 2022/08/05 13:16:51 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

HEADERS		= includes
LIBFT		= -L./libft -lft

DIR_O		= obj
DIR_S 		= srcs
SOURCES		= 					\
			main.c				\
			ps_utils.c			\
			ps_push.c			\
			ps_swap.c			\
			ps_rotate.c			\
			ps_array.c			\
			ps_parsing.c		\
			ps_sorting.c		\
			ps_min_max.c		\
			ps_structure.c		\
			push_swap.c			\
			push_swap_utils.c

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
# SRCB		= $(addprefix $(DIR_S)/,$(BONUS_S))
# OBJB		= $(addprefix $(DIR_O)/,$(BONUS_S:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@ 

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