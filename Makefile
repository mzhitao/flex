# 定义变量
CC = gcc
CXX = g++

CFLAGS = -std=c++17 -Wall -MMD -MP
LDFLAGS =

BUILD_DIR = build
SRC_DIR = src

SRCS := $(shell find $(SRC_DIR)/ -name "*.cpp")
SRCS += $(SRC_DIR)/lex.cpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.d, $(SRCS))


EXE = $(BUILD_DIR)/main

$(EXE): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o $(BUILD_DIR)/main

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/lex.cpp:$(SRC_DIR)/word.l
	flex -o $@ $<

-include $(DEPS)

run: $(EXE)
	@./$(EXE)

# 清理生成的文件
clean:
	rm -rf $(OBJS) $(EXE)

# 伪目标
.PHONY: all clean run
