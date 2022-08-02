# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 15:24:44 by yeblee            #+#    #+#              #
#    Updated: 2022/08/02 15:28:06 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
# NAMEB		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

HEADERS		= includes
LIBFT		= -L./libft -lft

DIR_O		= obj
DIR_S 		= srcs
SOURCES		= main.c				\

BONUS_S		= main.c				\

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
# SRCB		= $(addprefix $(DIR_S)/,$(BONUS_S))
# OBJB		= $(addprefix $(DIR_O)/,$(BONUS_S:.c=.o))

all: $(NAME)
# bonus: $(NAMEB)

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