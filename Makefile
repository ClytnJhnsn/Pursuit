CXX = g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)

SOURCES = $(wildcard *.cc)
OBJFILES = $(notdir $(SOURCES:.cc=.o))

all: sim_app

sim_app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $@

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f *.o *.exe *_app

