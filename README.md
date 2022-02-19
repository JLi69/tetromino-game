# Tetromino Game
A clone of the popular game Tetris.

## How to Compile the Code
To compile the source code into the binary file type the following commands:
```
cmake -S tetromino-game -B tetromino-game/build
cd tetromino-game/build
make
```
To run the program just type `./c-tetris`.

**NOTE: the folder 'shaders' and the files inside of it must be in the same directory as the executable file otherwise the program will not run properly**

**NOTE 2: Some necessary depedencies: ![GLFW](https://www.glfw.org/) and ![glad](https://glad.dav1d.de/)**

**NOTE 3: I wrote this targeted towards Linux so there may be some issues on Windows or MacOS. If you figure out a way to compile the source code on these platforms, please fork the project with the necessary adjustments or send a pull request.**

Have fun playing! :)

## Screenshots
![Screenshot 1](https://github.com/JLi69/tetromino-game/blob/main/screenshots/Screenshot%20from%202022-02-19%2009-16-45.png)

![Screenshot 2](https://github.com/JLi69/tetromino-game/blob/main/screenshots/Screenshot%20from%202022-02-19%2009-20-26.png)

## Video
![Gameplay Video](https://www.youtube.com/watch?v=TS5ESyjaoLg)
