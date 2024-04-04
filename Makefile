CXX=g++
CXXFLAGS=-std=c++11 -Wall
SOURCES=33.cpp
TARGETS=a.out

all: $(TARGETS)

$(TARGETS): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGETS) $(SOURCES)

clean:
	rm -f $(TARGETS)
