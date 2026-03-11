CP=clang
CFLAGS=$(shell cat compiler_flags.txt | tr '\n' ' ')
FILES=$(wildcard src/*.cpp)

build/raylib-test-linux.x86_64 : $(FILES)
	mkdir -p build
	$(CP) $(FILES) $(CFLAGS) -o build/raylib-test-linux.x86_64


clean :
	rm -r build/*
