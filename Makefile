NAME	=

SRCS	=

OBJS	=

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(INCLUDE)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:
			fclean all

.PHONY	:	all clean fclean re
