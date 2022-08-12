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

# ================ Color Variables ================ #

BLACK			= 	"\033[0;30m"
GRAY			= 	"\033[1;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[1;33m"
PURPLE			=	"\033[0;35m"
CYAN			=	"\033[0;36m"
WHITE			=	"\033[1;37m"
EOC				=	"\033[0;0m"
LINE_CLEAR		=	"\x1b[1A\x1b[M"

# ================================================= #

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
			ch_read.c			\
			ch_command.c		\
			ch_is_sorted.c		\
			ch_duplication.c	\
			ps_utils.c			\
			ps_structure.c		\
			ps_parsing.c		\
			ps_destroy.c		\
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
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

$(BONUS): $(OBJ_C)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	@make -C libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo $(GREEN) "$(BONUS) is created!\n" $(EOC)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@ 

$(DIR_O)/%.o: $(DIR_C)/%.c $(HEADERS)/$(BONUS).h
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@ 
	
clean:
	@echo $(YELLOW) "Cleaning object files..." $(EOC)
	@$(RM) $(DIR_O)
	@make clean -C libft
	@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean:	clean
	@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
	@$(RM) $(NAME) $(BONUS)
	@make fclean -C libft
	@echo $(RED) "$(NAME) is removed!\n\n" $(EOC)

re:	
	@make fclean 
	@make all

.PHONY: all bonus clean fclean re 