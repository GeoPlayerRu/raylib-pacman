CP=clang
CFLAGS=$(shell cat compiler_flags.txt | tr '\n' ' ')
FILES=$(wildcard src/*.cpp)

.PHONY : clean cross-windows

build/linux/raylib-test-linux.x86_64 : $(FILES)
	mkdir -p build/linux
	$(CP) $(FILES) $(CFLAGS) -o build/linux/raylib-test-linux.x86_64


clean :
	rm -r build/*
