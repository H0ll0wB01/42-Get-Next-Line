# Name of the static library to be generated
NAME = get_next_line.a

# Compiler to use
CC = cc

# Directory where the header files are located
HEADER_DIR = ./includes

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
CFILES = ft_get_next_line.c	 ft_get_next_line_utils.c

# Object files correspondig to the source files
OBJS = $(CFILES:.c=.o)

#___ MAKEFILE COMMANDS___#

# Target to generate .o files and create the static library .a file 
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile main.c into main.o (assuming this file exists)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean up .o files 
clean:
	rm -f $(OBJS)

# Clean up .o files + delete the .a file and the test executable
fclean: clean
	rm -f $(NAME)	
	rm -f ./test_program
	rm -f main.o
	rm -f example.txt

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

test_valgrind: $(NAME) main.o
	$(CC) $(C_FLAGS) -o test_program main.o $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all  ./test_program
.PHONY: all clean fclean re test
