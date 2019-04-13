TARGET = physicsengine
CXX=clang++
RM=rm -f
CXXFLAGS+= -Wc++11-extensions -std=c++11 -Wall -Wno-deprecated-declarations
LDFLAGS += -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

BUILD = ./build
OBJ_DIR = $(BUILD)/objects
APP_DIR = $(BUILD)/apps

INCLUDE = -Iinclude/ -I/usr/local/include

MKDIR = mkdir -p $(OUTPUTDIR)

EXEC = run
SRCS += $(wildcard src/*.cpp src/*/*.cpp)
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*