## HTOP replica in C++ 

Basically a system monitor in C++ for Linux, like HTOP. I used nCurses, Parser and a few extra external libraries to get this running, you should already have these in your system. 
## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.

Install ncurses within your own Linux environment: `sudo apt install libncurses5-dev libncursesw5-dev`

## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts

## Build Instructions

1. Clone the project repository: `git clone https://github.com/abhinavmir/htop-cpp` and `cd htop-cpp`

2. Build the project: `make build`

3. Run the resulting executable: `./build/monitor`

4. Add binaries to path if you want, and then you can access via `monitor`
