RM = rm -rf

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(BFL_DIR)/include -I./
LDFLAGS = -L$(BFL_DIR)
LDLIBS = -lBFL

NAME = bob_is_a_lazy_man

BFL_DIR = ../lib/BFL

SRC = $(NAME).c
OBJ = $(NAME).o
TEST = test_$(NAME).c
EXAMPLE = example_$(NAME).c

BONUS_SRC = $(NAME)_bonus.c
BONUS_OBJ = $(NAME)_bonus.o
BONUS_TEST = test_$(NAME)_bonus.c
BONUS_EXAMPLE = example_$(NAME)_bonus.c

all: $(OBJ)

ifeq ($(shell uname -s), Darwin)
$(OBJ): $(SRC)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS) -o $(OBJ)
endif
ifeq ($(shell uname -s), Linux)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OBJ)
endif

ifeq ($(shell uname -s), Darwin)
$(BONUS_OBJ): $(BONUS_SRC)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(BONUS_SRC) $(CPPFLAGS) -o $(BONUS_OBJ)
endif
ifeq ($(shell uname -s), Linux)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(BONUS_SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(BONUS_OBJ)
endif

clean:
	$(RM) *.o

fclean: clean

test: $(OBJ)
	@$(CC) $(CFLAGS) $(TEST) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

test_bonus: test $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_TEST) $(BONUS_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

example: $(OBJ)
	@$(CC) $(CFLAGS) $(EXAMPLE) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

example_bonus: $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_EXAMPLE) $(BONUS_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

.PHONY = all clean fclean test test_bonus example example_bonus
