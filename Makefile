# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Iinclude -std=c++17 `pkg-config --cflags poppler-cpp`
LDFLAGS = `pkg-config --libs poppler-cpp`

# Paths
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# Final executable
TARGET = $(BUILD_DIR)/app

# Default target
all: $(TARGET)

# Link final binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean command
clean:
	rm -rf $(BUILD_DIR)
