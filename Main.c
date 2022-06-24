#include "src/tetris.h"

Tetromino current;
int blocks[200] = { 0 };
bool gameOver = false;
int score = 0;

int main(int argc, char* args[])
{
	int level = 0;

	GLFWwindow* glWindow;
	Init(&glWindow);

	//Generate the first tetris peice
	GeneratePiece();

	unsigned int vertBuffer = SetupVertexBuffer();
	unsigned int shaderProgram = SetupShaderProgram();
	glUseProgram(shaderProgram);

	clock_t start = clock();

	//Main game loop
	while(!glfwWindowShouldClose(glWindow))
	{
		DrawFrame(shaderProgram, glWindow);

		char title[64] = "Tetris Clone SCORE: 0";
		int tempScore = score;
		for(int i = 20 + log(score) / log(10); i >= 20; i--)
		{
			title[i] = (char)(tempScore % 10 + '0');
			tempScore /= 10;
		}

		if(gameOver)
		{
			for(int i = 0; i < 64; i++)
				title[i] = (char)(0);
			strcpy(&title[0], "GAME OVER! SCORE: 0");
			int tempScore = score;
			if(tempScore > 0)
				for(int i = 18 + log(score) / log(10); i >= 18; i--)
				{
					title[i] = (char)(tempScore % 10 + '0');
					tempScore /= 10;
				}

			if((float)(clock() - start) / CLOCKS_PER_SEC > 0.001)
			{
				DrawGameOver();
				start = clock();
			}
		}
		glfwSetWindowTitle(glWindow, title);

		//Update the peices after a certain period of time
		if(!gameOver && (float)(clock() - start) / CLOCKS_PER_SEC > 0.015 - 0.001 * (level - 1))
		{
			UpdateFrame();
			start = clock();
		}

		//Speed up the peices
		level = (score / 400) + 1;
		
		//GLFW stuff
		glfwSwapBuffers(glWindow);
		glfwPollEvents();
	}

	//Release the resources used by glfw
	glfwTerminate();
}
