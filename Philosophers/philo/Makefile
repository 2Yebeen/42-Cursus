# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 17:26:36 by yeblee            #+#    #+#              #
#    Updated: 2022/12/15 20:56:01 by yeblee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY	= 	"\033[1;30m"
YELLOW	=	"\033[1;33m"
EOC		=	"\033[0;0m"
RED		=	"\033[0;31m"

NAME	= philo

CC		= cc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -rf

HEADERS	= includes
DIR_S	= srcs
DIR_O	= obj

SOURCES	= main.c		\

SRCS	= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS	= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all		: $(NAME)

$(NAME) : $(OBJS)
		@echo $(GREEN) "Source files are compiled!\n" $(EOC)
		@$(CC) $(FLAGS) -o $@ $^
		@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
		@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
		@mkdir -p $(DIR_O)
		@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@	

clean	:
		@echo $(YELLOW) "Cleaning object files..." $(EOC)
		@$(RM) $(DIR_O)
		@echo $(RED) "Object files are cleaned!\n" $(EOC)
fclean	:
		@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
		@$(RM) $(NAME)
		@echo $(RED) "$(NAME) is removed!\n\n" $(EOC)
re		:
		@make fclean 
		@make all

.PHONY: all clean fclean re 