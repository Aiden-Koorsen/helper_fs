# For GCC compilers
# NOTE this is only a temporary solution, I will create a CMake file eventually

lib:
	gcc -c src/str.c -o build/h_str.o -I include
	gcc -c src/file.c -o build/h_file.o -I include
	ar rcs build/libhelper_fs.a build/h_str.o build/h_file.o

demo:
	gcc test/main.c -o test/test -I include -L build -lhelper_fs

all:
	gcc -c src/str.c -o build/h_str.o -I include
	gcc -c src/file.c -o build/h_file.o -I include
	ar rcs build/libhelper_fs.a build/h_str.o build/h_file.o

	gcc test/main.c -o test/test -I include -L build -lhelper_fs