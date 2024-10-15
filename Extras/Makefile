# Name of the static library to be generated
NAME = get_next_line.a

# Compiler to use
CC = cc

# Directory where the header files are located
HEADER_DIR = ../intra-uuid-18fd33e4-5554-4a4f-9a92-d364bc41d591-6097669-jaferna2

# Default value for BUFFER_SIZE (can be overridden)
BUFFER_SIZE ?= 42 

# Variable to enable/disable the -D BUFFER_SIZE flag 
USE_BUFFER_SIZE ?= 1

# Compilation flags
CFLAGS = -Wall -Werror -Wextra -g3 -I $(HEADER_DIR)

# Sanitize flags to test 
C_SANITIZE_FLAGS = -Wall -Werror -Wextra -fsanitize=address -I $(HEADER_DIR)

# Add BUFFER_SIZE definition to compilation flags if enabled 
ifeq ($(USE_BUFFER_SIZE), 1)
	CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

# Source files 
SRC_FILES = get_next_line.c get_next_line_utils.c
C_FILES = $(addprefix $(HEADER_DIR)/, $(SRC_FILES)) main.c

# Bonus files
BONUS_SRC_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_C_FILES = $(addprefix $(HEADER_DIR)/, $(BONUS_SRC_FILES)) main_bonus.c 

# Object files correspondig to the source files
OBJS = $(C_FILES:.c=.o)

# Bonus objects
BONUS_OBJS = $(BONUS_C_FILES:.c=.o)

#___ MAKEFILE COMMANDS___#

# Target to generate .o files and create the static library .a file 
all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Rule to compile object files
$(HEADER_DIR)/%.o: $(HEADER_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile main.c into main.o (assuming this file exists)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean up .o files 
clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

# Clean up .o files + delete the .a file and the test executable
fclean: clean
	rm -f $(NAME)	
	rm -f ./test_program
	rm -f ./test_program_bonus
	rm -f main.o
	rm -f main_bonus.o

# Clean up and then build all targets
re:	fclean all

# Compile and run the test program
test: $(NAME) main.o
	$(CC) $(CFLAGS) -o test_program main.o $(NAME)
	@./test_program

# Compile and run the test program with sanitize
test_sanitize: $(NAME) main.o
	$(CC) $(C_SANITIZE_FLAGS) -o test_program main.o $(NAME)
	@./test_program

# Compile and run the test program with valgrind
test_valgrind: $(NAME) main.o
	$(CC) $(C_FLAGS) -o test_program main.o $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all  ./test_program

#__________BONUS_________#

# Compile and run the test program
test_bonus: $(NAME) main_bonus.o
	$(CC) $(CFLAGS) -o test_program_bonus main_bonus.o $(NAME)
	@./test_program_bonus

# Compile and run the test program with sanitize
test_sanitize_bonus: $(NAME) main_bonus.o
	$(CC) $(C_SANITIZE_FLAGS) -o test_program_bonus main_bonus.o $(NAME)
	@./test_program_bonus

# Compile and run the test program with valgrind
test_valgrind_bonus: $(NAME) main_bonus.o
	$(CC) $(C_FLAGS) -o test_program_bonus main_bonus.o $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all  ./test_program_bonus


.PHONY: all clean fclean re test test_sanitize test_valgrind test_bonus test_sanitize_bonus test_valgrind_bonus
