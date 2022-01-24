# makefile for surfaceArea.asm
task: main.c input.c inrnd.c output.c surfaceArea.o
	gcc -g -o task main.c input.c inrnd.c output.c surfaceArea.o -no-pie
surfaceArea.o: surfaceArea.asm
	nasm -f elf64 -g -F dwarf surfaceArea.asm -l surfaceArea.lst