# g++ -Wall -Wextra -Werror -std=c++23 -Wpedantic -c
# Flags for the compiler
CPPFLAGS = -Wall -Wextra -Werror -std=c++23 -Wpedantic

# Default target: depends on any .cpp file
all: $(OUT)
	@echo "Compilation complete"
	./$(OUT)  # Runs the output file after compilation

# Rule to handle any .cpp file passed in the target
%: %.cpp
	g++ $(CPPFLAGS) $< 
	./a.out${OUT}

# Clean target to remove output and object files
clean:
	rm -f *.out
	@echo "Cleaned up"

# Target for compilation without running the program
compile: $(OUT)

# Derives the output file name from the .cpp file
OUT = $(basename $(TARGET))  # Removes the .cpp extension from the target
