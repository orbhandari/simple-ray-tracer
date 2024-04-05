# Compiler
CC := gcc
CXXFLAGS += --std=c++17 -I/include/* -I/src/*


# Source files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
EXEC := raytracer

# Default target
all: $(EXEC)

# Compile source files into object files
%.o: %.c
	$(CC) $(CXXFLAGS) -c $< -o $@

# Link object files into an executable
$(EXEC): $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)
