CC			= cc
FLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
BONUS		= checker
INCLUDE		= include
SRC			= src/ft_move_to_a.c src/ft_move_to_top.c src/main.c \
				src/ft_move.c src/ft_move_to_b.c src/ft_sort_three.c
UTILS		= utils/ft_isdigit.c utils/ft_atoi.c utils/ft_isspace.c utils/ft_lstadd_front.c \
				utils/ft_list_len.c
OP			= operations/pb.c operations/rra.c operations/rrr.c \
				operations/ra.c operations/rrb.c operations/sa.c \
				operations/pa.c operations/rb.c operations/rr.c
BSRC		= src/checker.c
BUTILS		= utils/checker_utils.c utils/ft_atoi.c utils/ft_isdigit.c \
				utils/ft_isspace.c utils/ft_lstadd_front.c utils/ft_strcmp.c
BOP			= operations/checker_op_2.c operations/checker_op.c
SRC_OBJS	= $(SRC:.c=.o)
OP_OBJS		= $(OP:.c=.o)
UTILS_OBJS	= $(UTILS:.c=.o)
BSRC_OBJS	= $(BSRC:.c=.o)
BOP_OBJS	= $(BOP:.c=.o)
BUTILS_OBJS	= $(BUTILS:.c=.o)

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(SRC_OBJS) $(OP_OBJS) $(UTILS_OBJS)
	$(CC) $(FLAGS) $(SRC_OBJS) $(OP_OBJS) $(UTILS_OBJS) -o $(NAME)


$(BONUS) : $(BSRC_OBJS) $(BOP_OBJS) $(BUTILS_OBJS)
	$(CC) $(FLAGS) $(BSRC_OBJS) $(BOP_OBJS) $(BUTILS_OBJS) -o $(BONUS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -f $(SRC_OBJS) $(OP_OBJS) $(UTILS_OBJS) $(BSRC_OBJS) $(BOP_OBJS) $(BUTILS_OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re
