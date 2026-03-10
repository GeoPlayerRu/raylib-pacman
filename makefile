CFLAGS=$(shell cat compiler_flags.txt)

build/raylib-test-linux.x86_64 : src/main.cpp
	mkdir -p build
	clang src/main.cpp $(CFLAGS) -o build/raylib-test-linux.x86_64


clean :
	rm -r build/*
