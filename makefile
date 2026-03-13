CP=clang
CFLAGS=$(shell cat compiler_flags.txt | tr '\n' ' ')
FILES=$(wildcard src/*.cpp)

.PHONY : clean cross-windows all release debug

build/linux/raylib-test-linux-debug: $(FILES)
	mkdir -p build/linux
	$(CP) $(FILES) $(CFLAGS) -g3 -o build/linux/raylib-test-linux-debug

build/linux/raylib-test-linux-release: $(FILES)
	mkdir -p build/linux
	$(CP) $(FILES) $(CFLAGS) -o build/linux/raylib-test-linux-release

release: build/linux/raylib-test-linux-release

debug: build/linux/raylib-test-linux-debug

all: release debug

clean :
	rm -r build/*
