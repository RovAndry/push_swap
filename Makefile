NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

SRCS_PATH	=	./src
SRCS		=	$(shell find $(SRCS_PATH) -name "*.c")
OBJS		=	$(patsubst $(SRCS_PATH)/%.c,objs/%.o,$(SRCS))

objs/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -g

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
