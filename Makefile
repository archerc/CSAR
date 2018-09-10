# Project: csar
# Makefile created by Dev-C++ 5.11

NAME     = csar.exe
BUILDIR  = build
SRCDIR 	 = src
MSYS = D:/Applications/msys64
MinGW64 = $(MSYS)/mingw64
CPP = $(MinGW64)/bin/g++
# CPP      = g++.exe
# CC       = gcc.exe
# WINDRES  = windres.exe
# RM	   = rm -f
OBJ      = src/csar.o test/test_emplace.o test/test_json.o
LINKOBJ  = 
LIBS     = -lboost_program_options-mt -L $(MinGW64)/lib
INCS     = -I $(MinGW64)/include -I include
CXXINCS  = $(INCS)
CXXFLAGS = $(CXXINCS) --std=c++14
CFLAGS   = $(INCS) 
BIN 	 = $(BUILDIR)/$(NAME)
SRC 	 = $(SRCDIR)/$(NAME:.exe=.cpp)

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(SRC)
	$(CPP) -o $@ $< $(LINKOBJ) $(LIBS)

src/csar.o: src/csar.cpp
	$(CPP) -c src/csar.cpp -o src/csar.o $(CXXFLAGS)

test/test_emplace.o: test/test_emplace.cpp
	$(CPP) -c test/test_emplace.cpp -o test/test_emplace.o $(CXXFLAGS)

test/test_json.o: test/test_json.cpp
	$(CPP) -c test/test_json.cpp -o test/test_json.o $(CXXFLAGS)
