NAME		= pipex

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rcs

RM			= rm -rf

INCDIR		= ./pipex.h
LIBFT		= ./libft

SRCS		= pipex.c	\
			  utils.c	\

OBJS 		= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	# @make -C $(LIBFT)
	# $(CC) -o 4(NAME) -L./$(LIBFT) -lft $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@ar rcs $@ $?

all : $(NAME)

clean :
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re:	clean all

.PHONY: all clean fclean re