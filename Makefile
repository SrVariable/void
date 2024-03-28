CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
INCLUDE = -I./BFL/include
LDFLAGS = -L./BFL
LDLIBS = -lBFL

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

RM = rm -rf

FIRST = bob_is_a_lazy_man
SECOND = trolling_the_troll

all: bfl first second

first: bfl $(FIRST).c
	@printf "\nCompiling $(FIRST).c...\n"
	@$(CC) -o $(FIRST) $(CFLAGS) $(FIRST).c $(INCLUDE) $(LDFLAGS) $(LDLIBS)
	@printf "$(GREEN)Done!\n$(RESET)"
	@printf "$(YELLOW)Usage:$(RESET) ./$(FIRST) $(RED)<string1> <string2> ...\n$(RESET)"
	@printf "$(YELLOW)Example:$(RESET) ./$(FIRST) $(RED)\"Hello World\" \"How\" \"are\" \"you?\"\n$(RESET)"
	@printf "$(YELLOW)Example:$(RESET) ./$(FIRST) $(RED)\"V\@\!d Is the b3\\\$$t\"\n$(RESET)"

second: bfl $(SECOND).c
	@printf "\nCompiling $(SECOND).c...\n"
	@$(CC) -o $(SECOND) $(CFLAGS) $(SECOND).c $(INCLUDE) $(LDFLAGS) $(LDLIBS)
	@printf "$(GREEN)Done!\n$(RESET)"
	@printf "$(YELLOW)Usage:$(RESET) ./$(SECOND) $(RED)<string1> <dict>\n$(RESET)"
	@printf "$(YELLOW)Example:$(RESET) ./$(SECOND) $(RED)\"LOL is this a string?\"\n$(RESET)"
	@printf "$(YELLOW)Example:$(RESET) ./$(SECOND) $(RED)\"this crazy allucination is crazy lol\" \"crazy lol allucination\"\n$(RESET)"

fclean:
	@printf "Removing everything...\n"
	@make fclean -C BFL > /dev/null
	@$(RM) $(FIRST) $(SECOND)
	@printf "$(GREEN)Done!\n$(RESET)"

bfl:
	@git submodule update --init --recursive
	@printf "Compiling library...\n"
	@make -C BFL > /dev/null

.PHONY = bfl first second fclean
