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

../lib/BFL:
	@mkdir -p ../lib
	@git clone https://github.com/SrVariable/BFL.git ../lib/BFL

../lib/BFL/libBFL.a: ../lib/BFL
	cd ../lib/BFL && git restore .
	@make -sC ../lib/BFL
	@rm -rf ../lib/BFL/bool ../lib/BFL/char ../lib/BFL/fd ../lib/BFL/ft_printf \
	../lib/BFL/get_next_line ../lib/BFL/math ../lib/BFL/memory ../lib/BFL/obj \
	../lib/BFL/string ../lib/BFL/test ../lib/BFL/README.md ../lib/BFL/linked_list

bfl: ../lib/BFL/libBFL.a

run: fclean bfl $(NAME)
	@clear
	@./$(NAME)

fclean:
	@rm -rf $(NAME)

.PHONY = run fclean
