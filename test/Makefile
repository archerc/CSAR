include ../Makefile.common

SOURCES := $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

EXEUTABLES := $(SOURCES:.cpp=.exe)

.PHONY: all clean 
all: $(RESULT_DIR)$(EXEUTABLES)

$(BUILD_DIR)/%.exe: %.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 

