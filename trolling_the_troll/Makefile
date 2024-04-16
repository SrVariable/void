RM = rm -rf

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(BFL_DIR)/include -I./
LDFLAGS = -L$(BFL_DIR)
LDLIBS = -lBFL

NAME = trolling_the_troll

BFL_DIR = ../lib/BFL

SRC = $(NAME).c
OBJ = $(NAME).o
TEST = test_$(NAME).c
EXAMPLE = example_$(NAME).c

BONUS_SRC = $(NAME)_bonus.c
BONUS_OBJ = $(NAME)_bonus.o
BONUS_TEST = test_$(NAME)_bonus.c

all: $(OBJ)

$(OBJ): $(SRC)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OBJ)

clean:
	$(RM) *.o

fclean: clean

test: $(OBJ)
	@$(CC) $(CFLAGS) $(TEST) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

bonus: $(BONUS_SRC)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(BONUS_SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(BONUS_OBJ)

test_bonus: test $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_TEST) $(BONUS_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "Bonus part"
	@./a.out
	@$(RM) ./a.out

example: $(OBJ)
	@$(CC) $(CFLAGS) $(EXAMPLE) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

.PHONY = all clean fclean bonus test test_bonus example
