NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar 
ARFLAGS = rcs

RM = rm -rf

INCLUDES = libft.h

SRCS =  ft_strlen.c		\
		ft_strncmp.c	\
		ft_split.c		\
		ft_strjoin.c	\
		ft_strlcpy.c	\
		ft_strdup.c		\
		ft_strlcat.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# $(NAME): $(SRCS) $(INCLUDES)
# 		 $(CC) $(CFLAGS) -c $(SRCS)
# 		 $(AR) $(ARFLAGS) $@ $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
