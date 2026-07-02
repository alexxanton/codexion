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
	   src/utils/time.c						\
	   src/utils/utils.c					\
	   src/monitor/init.c					\
	   src/threads/init.c					\
	   src/dongles/dongle.c					\

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

PARAMS = 1 1000 100 100 100 2 1000 fifo

run: $(NAME)
	./$(NAME) $(PARAMS)

make dbg: $(NAME)
	valgrind --tool=helgrind ./$(NAME) $(PARAMS)

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
