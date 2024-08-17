# 定义变量
CC = gcc
CXX = g++

CXXFLAGS = -std=c++17 -Wall -MMD -MP
CXXFLAGS += -I$(SRC_DIR)
LDFLAGS = -lboost_system

BUILD_DIR = build
SRC_DIR = src

SRCS := $(shell find $(SRC_DIR)/ -name "*.cpp")
SRCS += $(SRC_DIR)/lex.cpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.d, $(SRCS))


EXE = $(BUILD_DIR)/main

$(EXE): $(OBJS)
	@mkdir -p $(@D)
	$(info "building $@")
	@$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/main $(LDFLAGS)

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(info "compiling $<")
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

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
