# Compiler settings
CXX = g++ -g 
EXE = bin/release/game
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
ASSETS_DIR = assets

# Compiler flags
CXXFLAGS = -std=c++17 -Iinclude `pkg-config --cflags sdl2` -Wall -Wextra

# Linker flags
LDFLAGS = `pkg-config --libs sdl2`

# Libraries
LIBS = -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Targets
all: $(BUILD_DIR) bin $(EXE)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

bin:
	@mkdir -p bin

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@rm -rf $(BUILD_DIR) $(EXE)

run: $(EXE)
	@./$(EXE)

.PHONY: all clean run
