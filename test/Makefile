include ../Makefile.common

SOURCES := $(wildcard *.cpp)
OBJECTS := 

EXEUTABLES := $(foreach f,$(SOURCES:.cpp=.exe),$(BUILD_DIR)/$(f))

.PHONY: all build clean test
all:  build
build: $(EXEUTABLES)
test: build

$(BUILD_DIR)/%.exe: %.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(EXEFLAGS) -o $@ $^

clean: 
	$(RM) $(EXEUTABLES)

