NAME = server

CC = gcc
INCLUDE = -I ./include/
CFLAGS = -g $(INCLUDE)

RM = rm -rf

PATH_SRCS = ./src/
PATH_OBJS = ./objs/

SRCS =	./lib/mongoose.c \
		$(PATH_SRCS)server.c \
		$(PATH_SRCS)router.c \
		$(PATH_SRCS)client.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PATH_OBJS)*.o -lcurl -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re

# SRCS =	main.c \
# 		mongoose.c \
# 		router.c \

# OBJS =	${SRCS:.c=.o}

# CC =	gcc
# RM =	rm -f

# NAME =	api_server
# INCLUDE = -I ./include

# ${NAME}:	${OBJS}
# 	${CC} ${INCLUDE} -o ${NAME} ${OBJS}

# all:	${NAME}

# clean:
# 	${RM} ${OBJS}

# fclean:		clean
# 	${RM} ${NAME}

# re:		fclean all