include Makefile.common

TEST_APP = test_emplace

.PHONY: all build-static build-shared check clean distclean test
all: build-static build-shared check test
build-static:
	$(MAKE) -C src build-static

build-shared:
	$(MAKE) -C src build-shared

check: build-static build-shared
	$(MAKE) -C test

test:
	./build/$(TEST_APP).exe
	
clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean

distclean: clean
	$(MAKE) -C src distclean

ifneq ($(OS),Windows)
.PHONY: install install-static
install:
	$(MAKE) -C src install-static
	$(MAKE) -C src install-shared
	$(MAKE) -C include install

install-static:
	$(MAKE) -C src install-static
	$(MAKE) -C include install
endif
