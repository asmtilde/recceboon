# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -MMD -MP

# SDL flags
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs) -lSDL2_ttf -lSDL2_image -lmd4c

# Target executable
TARGET = recceboon

# Source files
SOURCES := $(shell find src -name "*.cpp")
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(SOURCES:.cpp=.d)

# Build rules
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)"
	$(CXX) $(OBJECTS) -o $(TARGET) $(SDL_LDFLAGS)

# Compilation
%.o: %.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) $(SDL_CFLAGS) -c $< -o $@

# Include dependencies
-include $(DEPS)

# Clean up
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)
