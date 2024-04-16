RM = rm -rf

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(BFL_DIR)/include -I./
LDFLAGS = -L$(BFL_DIR)
LDLIBS = -lBFL

NAME = ultramarines_vs_necrones

BFL_DIR = ../lib/BFL

SRC = $(NAME).c
OBJ = $(NAME).o
TEST = test_$(NAME).c
EXAMPLE = example_$(NAME).c

all: $(OBJ)

$(OBJ): $(SRC)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OBJ)

clean:
	$(RM) *.o

fclean: clean

test: $(SRC)
	@$(CC) $(CFLAGS) -D SOLDIER_AMOUNT=1 $(TEST) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

example: $(OBJ)
	@$(CC) $(CFLAGS) $(EXAMPLE) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out
	@$(RM) ./a.out

.PHONY = all clean fclean test example
