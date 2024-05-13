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
	@mkdir -p ../lib/BFL
	@echo Configurando dependencias...
	@git clone https://github.com/SrVariable/BFL.git ../lib/BFL > /dev/null 2>&1
	@make -sC ../lib/BFL > /dev/null
	@rm -rf ../lib/BFL/bool ../lib/BFL/char ../lib/BFL/fd \
	../lib/BFL/ft_printf ../lib/BFL/get_next_line ../lib/BFL/math \
	../lib/BFL/memory ../lib/BFL/obj ../lib/BFL/string
	@clear
	@./$(NAME)

fclean:
	@rm -rf $(NAME) ../lib

.PHONY = run fclean
