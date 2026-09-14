# Installation

* Download MSYS2 from https://www.msys2.org/
* Run install script, use a non OneDrive folder for the install location, probably in your userspace on the C drive.
* Run MSYS2 console application
* Enter `pacman -S mingw-w64-ucrt-x86_64-gcc` to install the compilers
* Add `C:.../MSYS/ucrt64/bin/` to your PATH environment variable
* Test by opening VS-Code opening a terminal and typing `gcc --version`

## HelloWorld

Simplest option compliles directly to `a.exe`
```
gcc helloworld.c
./a.exe
```

## HelloWorld with a libary function 

This has three source files
* hello.c - the main program
* lib.h   - contains the decleration of a function
* lib.c   - the implementation of the function

Compile the two .c files to .o files

```gcc -c lib.c hello.c```

Compile the .o files to make an executable

```gcc -o hello.exe hello.o lib.o```

Run with 

```./hello.exe```
