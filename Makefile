# ONLY WINDOWS

CXX = g++

CXXFLAGS = -std=c++20 -g -Ilib/sdl/include -Iinclude

LDFLAGS = -Llib/sdl/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/debug/game

MAIN_SRC = $(SRC_DIR)/main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

SRCS = $(filter-out $(MAIN_SRC), $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/**/**/*.cpp))

OBJS = $(MAIN_OBJ)
OBJS += $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRCS))

# Automatic Test
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@if not exist $(subst /,\, $(dir $@)) mkdir $(subst /,\, $(dir $@))
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

$(OBJ_DIR):
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

run: $(TARGET)
	$(TARGET).exe

clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)

.PHONY: all clean run
