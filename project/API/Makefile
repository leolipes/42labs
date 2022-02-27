NAME = server

CC = gcc
INCLUDE = -I ./include/
CFLAGS = -g $(INCLUDE)

RM = rm -rf

PATH_SRCS = ./src/
PATH_MAIN = $(PATH_SRCS)server/
PATH_ROUTER = $(PATH_SRCS)router/
PATH_MONGOOSE = $(PATH_SRCS)mongoose/
PATH_REQUEST = $(PATH_SRCS)request/
PATH_LOG = $(PATH_SRCS)log/
PATH_CONTROLLER = $(PATH_SRCS)controller/
PATH_UTILS = $(PATH_SRCS)utils/
PATH_OBJS = ./objs/

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_MONGOOSE)mongoose.c \
		$(PATH_REQUEST)request.c \
		$(PATH_ROUTER)router.c \
		$(PATH_LOG)log.c \
		$(PATH_CONTROLLER)controller.c \
		$(PATH_UTILS)ft_split.c \
		$(PATH_UTILS)ft_substr.c \
		$(PATH_UTILS)ft_strjoin.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PATH_OBJS)/*/*.o -lcurl -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)server
	@mkdir -p $(PATH_OBJS)router
	@mkdir -p $(PATH_OBJS)mongoose
	@mkdir -p $(PATH_OBJS)request
	@mkdir -p $(PATH_OBJS)log
	@mkdir -p $(PATH_OBJS)controller
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
