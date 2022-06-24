#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct
{
	int type; //Shape of tetromino represented as an integer
			  //0 = I, 1 = J, 2 = L, 3 = S, 4 = Z, 5 = O, 6 = T
	int rotation; //Rotation of the tetromino
	int x, y; //position of the top left corner of the tetromino
	char blocks[16];
} Tetromino;

//Current tetris peice
extern Tetromino current;
//Fallen blocks
extern int blocks[200];
//Store if the user lost
extern bool gameOver;
extern int score; //Store the score of the player

//Update the frame
void UpdateFrame();

//Draw the frame
void DrawFrame(unsigned int program, GLFWwindow *win);

//Generate the next peice
void GeneratePiece();
//Rotate the peice
void RotatePiece();
//Check if the tetris peice is in a valid position
bool CheckTetrisPos();
//Check if the tetris peice has fallen to the bottom of the screen
//or on the top of another peice
bool CheckTetrisFallen();

//Draw the game over screen
void DrawGameOver();

//Handle key input
void HandleKeyInput(GLFWwindow *win, int key, int scancode, int action, int mods);
//Handle window resizing
void HandleWinResize(GLFWwindow *win, int width, int height);

//Set up the shaders
unsigned int CreateShader(const char* filename, const GLenum shaderType);
unsigned int SetupShaderProgram();
//Set up the vertex buffer
unsigned  SetupVertexBuffer();
//Set up GLFW/glad
void Init(GLFWwindow** win);
