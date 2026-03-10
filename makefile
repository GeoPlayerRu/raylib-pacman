CFLAGS=$(shell cat compiler_flags.txt)
FILES=$(wildcard src/*.cpp)

build/raylib-test-linux.x86_64 : $(FILES)
	mkdir -p build
	clang $(FILES) $(CFLAGS) -o build/raylib-test-linux.x86_64


clean :
	rm -r build/*
