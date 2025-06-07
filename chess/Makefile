# Compiler and flags
CXX := g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Output executable
TARGET := FantasyChess.exe

# Build rules
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
