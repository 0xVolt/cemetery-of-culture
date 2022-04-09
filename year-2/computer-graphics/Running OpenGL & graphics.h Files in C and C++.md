sudo apt update
sudo apt install build-essential
sudo apt install cmake
sudo apt install xorg-dev

download glfw source package https://www.glfw.org/download.html
unpack it in Desktop
go to unpacked directory

cmake -G "Unix Makefiles"
make
sudo make install

sudo apt-get install libx11-dev libglu1-mesa-dev freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libgl1-mesa-glx libgl1-mesa-dev libglfw3-dev libglfw3

make your own code and name it with extension .c
and then

gcc "source filename".c -o "filename" -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

also works with C++:

g++ "source filename".cpp -o "filename" -std=c++11 -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

--------------------------------------------------------------------------------------------------------------------------------

Instructions to execute programs

To compile and run a program using GLUT or OpenGL,

Use this on the fly:
g++  -o a -std=c++11 -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

followed by
./a

To compile a program against libXbgi for graphics.h library use:
  gcc -o a program.c /usr/lib/libXbgi.a -lX11 -lm

  or 

  g++ -o a program.cpp /usr/lib/libXbgi.a -lX11 -lm
