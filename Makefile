CC		= cc
FLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
BINUS	= checker
SRC		= src/ft_move_to_a.c src/ft_move_to_top.c src/main.c \
			src/ft_move.c src/ft_move_to_b.c src/ft_sort_three.c
UTILS	= utils/ft_isdigit.c utils/ft_atoi.c utils/ft_isspace.c utils/ft_lstadd_front.c
Op		= operations/pb.c operations/rra.c operations/rrr.c \
			operations/ra.c operations/rrb.c operations/sa.c \
			operations/pa.c operations/rb.c operations/rr.c
BSRC	= src/checker.c
BUTILS	= utils/checker_utils.c ft_atoi.c ft_isdigit.c ft_isspace.c ft_lstadd_front.c ft_strcmp.c

