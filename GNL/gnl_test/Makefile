CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -D BUFFER_SIZE=3

AR			= ar
ARFLAGS		= rcs

RM			= rm a.out

SRCS		= ../get_next_line.c				\
			  ../get_next_line_utils.c			\
			  main.c

BONUS		= ../get_next_line_bonus.c			\
			  ../get_next_line_utils_bonus.c	\
			  bonus.c

man :
	$(CC) $(CFLAGS) $(DFLAGS) $(SRCS)

bonus :
	$(CC) $(CFLAGS) $(DFLAGS) $(BONUS)

fc:
	$(RM)