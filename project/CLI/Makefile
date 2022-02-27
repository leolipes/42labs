NAME = cli

CC = gcc
INCLUDE = -I ./include/
CFLAGS = -g $(INCLUDE)

RM = rm -rf

PATH_SRCS = ./src/
PATH_MAIN = $(PATH_SRCS)cli/
PATH_UTILS = $(PATH_SRCS)utils/
PATH_OBJS = ./objs/

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_UTILS)ft_split.c \
		$(PATH_UTILS)ft_substr.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PATH_OBJS)/*/*.o -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)cli
	@mkdir -p $(PATH_OBJS)utils
	$(CC) $(CFLAGS) -c $< -o $@
run: all
	./$(NAME)

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
