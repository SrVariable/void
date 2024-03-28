CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./BFL/include
LDFLAGS = -L./BFL
LDLIBS = -lBFL

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

RM = rm -rf

FIRST = bob_is_a_lazy_man

first: bfl $(FIRST).c
	@printf "Compiling $(FIRST).c...\n"
	@$(CC) -o $(FIRST) $(CFLAGS) $(FIRST).c $(INCLUDE) $(LDFLAGS) $(LDLIBS)
	@printf "$(GREEN)Done!\n\n$(RESET)"
	@printf "$(YELLOW)Usage:$(RESET) ./$(FIRST) $(RED)<string1> <string2> ...\n$(RESET)"
	@printf "$(YELLOW)Example:$(RESET) ./$(FIRST) $(RED)\"Hello World\" \"How\" \"are\" \"you?\"\n$(RESET)"

fclean:
	@printf "Removing everything...\n"
	@make fclean -C BFL > /dev/null
	@$(RM) $(FIRST)
	@printf "$(GREEN)Done!\n$(RESET)"

bfl:
	@git submodule update --init --recursive
	@printf "Compiling library...\n"
	@make -C BFL > /dev/null

.PHONY = bfl first fclean
