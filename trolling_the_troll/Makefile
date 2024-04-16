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

all: $(OBJ)

$(OBJ): $(SRC)
	make -s -C $(BFL_DIR)
	$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OBJ)

test: $(OBJ)
	@$(CC) $(CFLAGS) $(TEST) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@./a.out || exit 0
	@$(RM) ./a.out

clean:
	$(RM) *.o

fclean: clean
