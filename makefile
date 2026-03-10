CFLAGS=$(cat compiler_flags.txt//"\n"/" ")

build/raylib-test-linux.x86_64 : main.cpp
	mkdir -p build
	clang main.cpp $(CFLAGS) -o build/raylib-test-linux.x86_64

clean :
	rm -r build/*
