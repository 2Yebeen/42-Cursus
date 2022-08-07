# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 13:06:40 by yeblee            #+#    #+#              #
#    Updated: 2022/08/08 00:07:49 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

HEADERS		= includes
LIBFT		= -L./libft -lft

DIR_O		= obj
DIR_S 		= srcs/push_swap
DIR_C		= srcs/checker
SOURCES		= 					\
			main.c				\
			ps_utils.c			\
			ps_push.c			\
			ps_swap.c			\
			ps_rotate.c			\
			ps_array.c			\
			ps_parsing.c		\
			ps_sorting.c		\
			ps_destroy.c		\
			ps_min_max.c		\
			ps_structure.c		\
			push_swap.c			\
			push_swap_utils.c
BONUS_C		=					\
			checker.c			\
			ch_command.c		\
			ch_is_sorted.c		\
			ps_utils.c			\
			ps_structure.c		\
			ps_parsing.c		\
			ps_array.c			\
			ps_push.c			\
			ps_swap.c			\
			ps_rotate.c			

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
SRC_C		= $(addprefix $(DIR_C)/,$(BONUS_C))
OBJ_C		= $(addprefix $(DIR_O)/,$(BONUS_C:.c=.o))

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(BONUS): $(OBJ_C)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@ 

$(DIR_O)/%.o: $(DIR_C)/%.c $(HEADERS)/$(BONUS).h
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@ 
	
clean:
	@$(RM) $(DIR_O)
	@make clean -C libft

fclean:	clean
	@$(RM) $(NAME) $(BONUS)
	@make fclean -C libft

re:	
	@make fclean 
	@make all

.PHONY: all bonus clean fclean re 