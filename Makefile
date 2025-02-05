# Compiler flags
CPPFLAGS = -Wall -Wextra -Werror -std=c++23 -Wpedantic

# Output executable file name (default: a.out)
OUT = a.out

# Default target: Compile and run the program
all: $(OUT)
	@echo "Compilation complete"
	./$(OUT)  # Run the program after compilation

# Rule for compiling any .cpp files into object files
$(OUT): $(SRC:.cpp=.o)
	g++ $(CPPFLAGS) $(SRC) -o $(OUT)

# Clean target to remove output and object files
clean:
	find . -type f \( -name '*.o' -o -name '*.out' -o -name 'a.out' -o -name '*.exe' -o -name '*.bin' -o -name '*.obj' -o -name 'core' \) -delete
	@echo "Cleaned up"

# Compile only (no execution)
compile: $(OUT)
