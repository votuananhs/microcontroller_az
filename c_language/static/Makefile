
all: main.c
	rm -rf static_keyword.*
	gcc main.c -O0 -Xlinker -Map=static_keyword.map -o static_keyword.exe
	size static_keyword.exe
