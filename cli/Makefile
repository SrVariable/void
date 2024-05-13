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
	@clear
	@./$(NAME)

fclean:
	@rm -rf $(NAME)

.PHONY = run fclean
