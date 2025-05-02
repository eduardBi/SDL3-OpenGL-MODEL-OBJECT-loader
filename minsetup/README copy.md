install sdl 3 (mingw)
add to yo project x86_64 from downloaded archive 
create yo c script 
run command to create executable 
gcc -o hello.exe hello.c -Ix86_64-w64-mingw32/include -Lx86_64-w64-mingw32/lib -lSDL3
then on the same level as your exe file put SDL3.dll from  x86_64-w64-mingw32/bin/SDL3.dll 
then run 
./hello.exe

g++ -std=c++17 hello.cpp objLoader/mesh_loader.cpp objLoader/tiny_obj_loader.cc objLoader/loaderObj.cpp ^
    -o hello.exe ^
    -IportSDL3_minGW -LportSDL3_minGW ^
    -lSDL3 -lopengl32 -lglu32


