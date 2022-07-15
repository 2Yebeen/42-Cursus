NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

INCDIR		= ./pipex.h
INCDIR_BONUS= ./pipex_bonus.h

LIBFT		= ./libft

SRCS		= pipex.c		\
			  utils.c		

OBJS 		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) -L $(LIBFT) -lft $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re:	
	make fclean 
	make all

.PHONY: all clean fclean re