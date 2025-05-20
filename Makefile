NAME= libftprintf.a

SRCS= ft_printf.c ft_sources.c

COMP_LIB = ar rcs
RM= rm -f
CC= cc
CC_FLAGS= -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
ADD = $(SRCS)

all:$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all

$(OBJS):
	$(CC) $(CC_FLAGS) $(ADD)

$(NAME): $(OBJS)
	$(COMP_LIB) $(NAME) $(OBJS)