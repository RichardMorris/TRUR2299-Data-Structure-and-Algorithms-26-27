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

# Git configuration

* Create a new project on GitHub
* Set .gitignore option to C++
* Create the project
* Copy clone URL like `https://github.com/RichardMorris/TRUR2299-Data-Structure-and-Algorithms-26-27.git` from GitHub.
* In VS-Code open a new window and choose the "Clone Git Repository..." option
* Paste in the clone URL.
* Commit your first file
* In a Git Bash prompt enter
* ```git config  user.name "RichardMorris"```
* In GitHub navigate to settings->developer settings->personal acess tokens (classic)
* Generate a new token with repo scope, and expiry date in July next year. Copy this.
* In Git Bash type
```git push```
* Paste in the Access Token when the window pops up.

# Input example

There are several different methods for reading from the standard input.

`scanf` scans the input using a format string.
* `scanf(format, addr1, addr2, ...)`
* where `format` consists of
  * `%d` for integers, 
  * `%c` for single character, 
  * `%s` for strings (end at whitespace)
  * `%f` for floating point
* `addr1` is the address of a variable `&number` etc. Think of this as the position in memory where the value of the variable is stored.
* For a character array `char name[10];` you just use `name` for the address

`getchar` read a single character
* `int ch = getchar()`
* return the next character code, 
  * 0x0d for new-line
  * EOF = -1 - for end of input 
  * ascsii character 

`fgets` reads a line of text into a buffer
* `char line[200];`
* `fgets(line, sizeof(line), stdin);`
  * `line` is a array variable
  * `sizeof(line)` is max number of characters to read 
  * `stdin` is the standard terminal input

  Use `gcc -o input.exe input.c` to compile direct to an executable. 