NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	main.c algorithm.c init_stack.c utils.c \
				valid_input.c stack_analysis.c \
				./operations/*.c
LIBFT_PATH	=	./_LIBFT
LIBFT		=	$(LIBFT_PATH)/libft.a

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
					@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
					@echo "|p        |"
					@echo "| u       |"
					@echo "|  s      |"
					@echo "|   h     |"
					@echo "|         |"
					@echo "|     s   |"
					@echo "|      w  |"
					@echo "|       a |"
					@echo "|        p|"
					@echo "Compilation successful!"

$(LIBFT):
					@make -C $(LIBFT_PATH) all

clean:
					@make -C $(LIBFT_PATH) clean
					@echo "cleaned"

fclean:			clean
					@make -C $(LIBFT_PATH) fclean
					@rm -f $(NAME)
					@echo "fcleaned"

re:				fclean all

.PHONY:			all clean fclean re libft
