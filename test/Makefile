include ../Makefile.common

SOURCES := $(wildcard *.cpp)
OBJECTS := 

EXEUTABLES := $(add-prefix $(BUILD_DIR)/,$(SOURCES:.cpp=.exe))

.PHONY: all build clean 
all:  build
build: $(EXEUTABLES)

$(BUILD_DIR)/%.exe: %.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 

