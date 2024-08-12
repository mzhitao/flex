# 定义变量
CC = clang
CXX = clang++
LD = clang++
CFLAGS = -std=c++17 -Wall
LDFLAGS =

BUILD_DIR = build
SRC_DIR = src
SRCS := $(shell find $(SRC_DIR)/ -name "*.cpp")
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

EXE = $(BUILD_DIR)/main

$(EXE): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(BUILD_DIR)/main

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(EXE)
	@./$(EXE)

# 清理生成的文件
clean:
	rm -rf $(OBJS) $(EXE)

# 伪目标
.PHONY: all clean run
