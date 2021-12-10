CXX = g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)
IDIR = include

BUILD_DIR = build
INCLUDE = -I. -I/include
SOURCES = $(shell find src -name '*.cc')
OBJFILES = $(notdir $(SOURCES:.cc=.o))

EXEFILE = $(BUILD_DIR)/sim-app
OBJFILES = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cc=.o))


all: $(BUILD_DIR) $(EXEFILE) 

# Application
$(EXEFILE): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $@

# Object files
$(BUILD_DIR)/%.o: %.cc 
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Build Directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	
clean:
	rm -rf build

