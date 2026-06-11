NAME = codexion
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -I include
RM = rm -f

SRCS = main.c								\
	   src/parsing/parse_data.c				\
	   src/simulation/begin_simulation.c	\

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
