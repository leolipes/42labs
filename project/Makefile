NAME = server

CC = gcc
INCLUDE = -I ./include/
CFLAGS = -g $(INCLUDE)

RM = rm -rf

PATH_SRCS = ./src/
PATH_MAIN = $(PATH_SRCS)server/
PATH_ROUTER = $(PATH_SRCS)router/
PATH_LIB = $(PATH_SRCS)lib/
PATH_REQUEST = $(PATH_SRCS)request/
PATH_OBJS = ./objs/

SRCS =	$(PATH_MAIN)main.c\
		$(PATH_LIB)mongoose.c\
		$(PATH_REQUEST)request.c\
		$(PATH_ROUTER)router.c

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PATH_OBJS)/*/*.o -lcurl -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)server
	@mkdir -p $(PATH_OBJS)router
	@mkdir -p $(PATH_OBJS)lib
	@mkdir -p $(PATH_OBJS)request
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