install sdl 3 (mingw)
add to yo project x86_64 from downloaded archive 
create yo c script 
run command to create executable 
gcc -o hello.exe hello.c -Ix86_64-w64-mingw32/include -Lx86_64-w64-mingw32/lib -lSDL3
then on the same level as your exe file put SDL3.dll from  x86_64-w64-mingw32/bin/SDL3.dll 
then run 
./hello.exe



g++ -std=c++11 -o hello.exe hello.cpp -Ix86_64-w64-mingw32/include -Lx86_64-w64-mingw32/lib -lSDL3 -lopengl32 -lglu32 -lGL

# Using this package

This package contains SDL3 built for the mingw-w64 toolchain.

The files for 32-bit architecture are in i686-w64-mingw32
The files for 64-bit architecture are in x86_64-w64-mingw32

You can install them to another location, just type `make` for help.

To use this package, point your include path at _arch_/include and your library path at _arch_/lib, link with the SDL3 library and copy _arch_/bin/SDL3.dll next to your executable.

e.g.
```sh
gcc -o hello.exe hello.c -Ix86_64-w64-mingw32/include -Lx86_64-w64-mingw32/lib -lSDL3
cp x86_64-w64-mingw32/bin/SDL3.dll .
./hello.exe
```











g++ -std=c++17 hello.cpp objLoader/mesh_loader.cpp objLoader/tiny_obj_loader.cc objLoader/loaderObj.cpp ^
    -o hello.exe ^
    -Ix86_64-w64-mingw32/include ^
    -Lx86_64-w64-mingw32/lib ^
    -lSDL3 -lopengl32 -lglu32



# Documentation

An API reference, tutorials, and additional documentation is available at:

https://wiki.libsdl.org/SDL3

# Example code

There are simple example programs available at:

https://examples.libsdl.org/SDL3

# Discussions

## Discord

You can join the official Discord server at:

https://discord.com/invite/BwpFGBWsv8

## Forums/mailing lists

You can join SDL development discussions at:

https://discourse.libsdl.org/

Once you sign up, you can use the forum through the website or as a mailing list from your email client.

## Announcement list

You can sign up for the low traffic announcement list at:

https://www.libsdl.org/mailing-list.php

