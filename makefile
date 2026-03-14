CP=clang
CROSS_CP=x86_64-w64-mingw32-g++
CFLAGS=$(shell cat compiler_flags.txt | tr '\n' ' ')
WINCFLAGS=-Wall -lm -Iinclude/windows -lraylib -lopengl32 -lwinmm -lgdi32 -lshell32 -Llib/windows/ -static
FILES=$(wildcard src/*.cpp)

.PHONY : clean cross-windows all release debug

build/linux/raylib-test-linux-debug: $(FILES)
	mkdir -p build/linux
	$(CP) $(FILES) lib/linux/libraylib.a $(CFLAGS) -lX11 -g3 -o build/linux/raylib-test-linux-debug

build/linux/raylib-test-linux-release: $(FILES)
	mkdir -p build/linux
	$(CP) $(FILES) $(CFLAGS) -O3 -o build/linux/raylib-test-linux-release

build/windows/raylib-test-windows-debug.exe: $(FILES)
	mkdir -p build/windows
	$(CROSS_CP) $(FILES) $(WINCFLAGS) -o build/windows/raylib-test-windows-debug.exe

build/windows/raylib-test-windows-release.exe: $(FILES)
	mkdir -p build/windows
	$(CROSS_CP) $(FILES) $(WINCFLAGS) -O3 -o build/windows/raylib-test-windows-release.exe

release: build/linux/raylib-test-linux-release build/windows/raylib-test-windows-release.exe

debug: build/linux/raylib-test-linux-debug build/windows/raylib-test-windows-debug.exe

all: release debug

cross-windows: build/windows/raylib-test-windows-debug.exe

clean :
	rm -r build/*
