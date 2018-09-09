include ../Makefile.common

SRC := $(wildcard *.cpp)
STATIC_OBJ := $(SRC:.cpp=.o)
SHARED_OBJ := $(SRC:.cpp=.lo)

override CPPFLAGS += -I../include -DNDEBUG

NAME := csar
STATIC_LIB := lib$(NAME).a

SHARED_LIB_VERSIONED := lib$(NAME).dll
override LDFLAGS += --shared
LDLIBS :=

STATIC_EXE := $(NAME).exe

BUILD_DIR := ../build
RESULT_DIR := $(BUILD_DIR)/
CACHE_DIR := $(BUILD_DIR)/cache

.PHONY: all build-static build-shared build-exe clean distclean
all: build-static build-shared build-exe
build-static: $(RESULT_DIR)$(STATIC_LIB)
build-shared: $(RESULT_DIR)$(SHARED_LIB_VERSIONED)
build-shared: $(RESULT_DIR)$(STATIC_EXE)

clean:
	$(RM) $(STATIC_OBJ)
	$(RM) $(SHARED_OBJ)

distclean: clean cleandeps
	$(RM) $(RESULT_DIR)$(STATIC_LIB)
	$(RM) $(RESULT_DIR)$(SHARED_LIB_VERSIONED)
	$(RM) $(RESULT_DIR)$(SHARED_LIB_VERSIONED)

$(RESULT_DIR)$(STATIC_EXE): $(STATIC_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(EXEFLAGS) -o $@ $^ $(LDLIBS)

$(RESULT_DIR)$(SHARED_LIB_VERSIONED): $(STATIC_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(RESULT_DIR)$(STATIC_LIB): $(STATIC_OBJ)
	mkdir -p $(BUILD_DIR)
	$(AR) $(ARFLAGS) -o $@ $^


$(CACHE_DIR)/%.o : %.cpp

include ../Makefile.deps
