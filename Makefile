CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = gnl_xtester.out

SRC = main.c \
      ../get_next_line.c \
      ../get_next_line_utils.c

BONUS_SRC = main_bonus.c \
	    ../get_next_line_bonus.c \
	    ../get_next_line_utils_bonus.c

OBJS =$(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	rm -f $(OBJS)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ)
	rm -f $(BONUS_OBJ)

valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

valgrind_bonus: bonus
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run valgrind
