# Compiler
CXX = g++

# Output executable
TARGET = program

# Source files
SRCS = main.cpp matrix.cpp

# Default rule to compile everything in one step
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)