NAME = codexion
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS = main.c	\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c Makefile $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME) clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
