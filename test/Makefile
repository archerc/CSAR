include ../Makefile.common

SOURCES := $(wildcard *.cpp)
OBJECTS := 

EXEUTABLES := $(foreach f,$(SOURCES:.cpp=.exe),$(BUILD_DIR)/$(f))

.PHONY: all build clean 
all:  build
build: $(EXEUTABLES)

$(BUILD_DIR)/%.exe: %.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 
	$(RM) $(EXEUTABLES)

