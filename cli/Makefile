NAME = cli

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = command.c \
	  display.c \
	  handler.c \
	  main.c \
	  utils.c

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: fclean $(NAME)
	@make -sC ../lib/BFL > /dev/null
	@clear
	@./$(NAME)

fclean:
	@make fclean -sC ../lib/BFL /dev/null
	@rm -f $(NAME)

.PHONY = run fclean
