CXX = g++
CXXFLAGS_DEBUG = -Wall -g -O0
CXXFLAGS_RELEASE = -O3

all: debug release

debug: main.cpp
	$(CXX) $(CXXFLAGS_DEBUG) -o dselect_debug main.cpp

release: main.cpp
	$(CXX) $(CXXFLAGS_RELEASE) -o dselect_release main.cpp


.PHONY: clean
clean:
	rm -rf dselect_debug dselect_release

