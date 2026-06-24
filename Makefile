NAME = codexion
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -I include -g
RM = rm -f
OBJ_DIR = objs
HEADERS = include/codexion.h

SRCS = main.c								\
	   src/parsing/parse_data.c				\
	   src/simulation/begin_simulation.c	\
	   src/coders/init.c					\
	   src/coders/routine.c					\
	   src/utils/logs.c						\
	   src/utils/monitoring.c				\
	   src/monitor/init.c					\
	   src/threads/init.c					\

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

run: $(NAME)
	./$(NAME) 5 100 100 100 100 5 1000 fifo

make dbg: $(NAME)
	valgrind --tool=helgrind ./$(NAME) 2 100 100 100 100 2 1000 fifo

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
