NAME = codexion
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -I include
RM = rm -f
OBJ_DIR = objs

SRCS = main.c								\
	   src/parsing/parse_data.c				\
	   src/simulation/begin_simulation.c	\
	   src/coders/init.c					\

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
