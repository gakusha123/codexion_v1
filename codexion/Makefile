NAME		= codexion

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
CPPFLAGS	= -I. -Iheaders

SRCS		= codexion.c \
			  parser/parser.c \
			  parser/parser_errors.c \
			  parser/parser_helpers.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
