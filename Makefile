CXX = g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)
INCLUDE_DIR = include
BUILD_DIR = build
INCLUDE = -I. -I/include
SOURCES = $(shell find src -name '*.cc')
OBJFILES = $(notdir $(SOURCES:.cc=.o))

APP = $(BUILD_DIR)/sim-app
OBJFILES = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cc=.o))


all: $(BUILD_DIR) $(APP) 

# Application
$(APP): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $@

# Object files
$(BUILD_DIR)/%.o: %.cc 
	mkdir -p $(dir $@)
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Build Directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	
clean:
	rm -rf build output

