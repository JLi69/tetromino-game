#include "src/tetris.h"
#include <sys/time.h>

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

	struct timeval start;
	gettimeofday(&start, 0);

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
			
			struct timeval now;
			gettimeofday(&now, 0);
			double secondsPassed = now.tv_sec - start.tv_sec + 1e-6 * (now.tv_usec - start.tv_usec);
			if(secondsPassed > 0.03)
			{
				DrawGameOver();
				gettimeofday(&start, 0);
			}
		}
		glfwSetWindowTitle(glWindow, title);
	
		//GLFW stuff
		glfwSwapBuffers(glWindow);
		glfwPollEvents();

		//Speed up the peices
		level = (score / 400) + 1;	
		
		//Update the peices after a certain period of time
		struct timeval now;
		gettimeofday(&now, 0);
		double secondsPassed = now.tv_sec - start.tv_sec + 1e-6 * (now.tv_usec - start.tv_usec);	
		if(!gameOver && secondsPassed > 0.3 - 0.02 * (level - 1))
		{
			UpdateFrame();
			gettimeofday(&start, 0);	
		}
	}

	//Release the resources used by glfw
	glfwTerminate();
}
