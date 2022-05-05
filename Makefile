NAME	=	push_swap
NAME_B	=	checker

INCLUDES =	-I./includes \
			-I./libft/includes

LIBFT	=	-L./libft -lft

SDIR	=	./srcs
_SRCS	=	push_swap.c \
			ft_perror.c \
			check_param.c \
			cpy_int.c \
			instructions.c \
			operations.c \
			init_elem.c \
			start_algo.c \
			algo_score.c \
			sort.c \
			close_algo.c
SRCS	=	$(patsubst %,$(SDIR)/%,$(_SRCS))

SDIR_B	=	./srcs_bonus
_SRCS_B	=	checker.c \
			ft_perror.c \
			check_param.c \
			cpy_int.c \
			read_stdin.c \
			instructions_b.c \
			operations.c
SRCS_B	=	$(patsubst %,$(SDIR_B)/%,$(_SRCS_B))

ODIR	=	./objs
_OBJS	=	${_SRCS:.c=.o}
OBJS	=	$(patsubst %,$(ODIR)/%,$(_OBJS))

ODIR_B	=	./objs_b
_OBJS_B	=	${_SRCS_B:.c=.o}
OBJS_B	=	$(patsubst %,$(ODIR_B)/%,$(_OBJS_B))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

# Mise en forme
_END	=	$'\x1b[0m
_BOLD	=	$'\x1b[1m
_UNDER	=	$'\x1b[4m
_REV	=	$'\x1b[7m

# Couleurs
_GREY	=	$'\x1b[30m
_RED	=	$'\x1b[31m
_GREEN	=	$'\x1b[32m
_YELLOW	=	$'\x1b[33m
_BLUE	=	$'\x1b[34m
_PURPLE	=	$'\x1b[35m
_CYAN	=	$'\x1b[36m
_WHITE	=	$'\x1b[37m

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo "$(_RED)Compilation libft.a en cours...$(_END)"
			@make -C ./libft
			@echo "$(_RED)Compilation push_swap en cours...$(_END)"
			@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(OBJS) -o $(NAME)
			@echo "$(_GREEN)$(_BOLD)Fin de la compilation push_swap$(_END)"

$(ODIR)/%.o: $(SDIR)/%.c
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus	:	$(OBJS_B)
			@echo "$(_RED)Compilation libft.a en cours...$(_END)"
			@make -C ./libft
			@echo "$(_RED)Compilation checker en cours...$(_END)"
			@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(OBJS_B) -o $(NAME_B)
			@echo "$(_GREEN)$(_BOLD)Fin de la compilation bonus$(_END)"

$(ODIR_B)/%.o: $(SDIR_B)/%.c
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean	:
			@echo "$(_BLUE)Clean des .o$(_END)"
			@make -C ./libft clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_B)

fclean	:	clean
			@echo "$(_BLUE)Clean des executables$(_END)"
			@$(RM) ./libft/libft.a
			@$(RM) $(NAME)
			@$(RM) $(NAME_B)

re		:	fclean all bonus

.PHONY	:	all clean fclean re
