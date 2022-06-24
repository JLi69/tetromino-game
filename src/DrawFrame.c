#include "tetris.h"

void DrawFrame(unsigned int program, GLFWwindow *win)
{
	//Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	int uColorLocation = glGetUniformLocation(program, "uColor"),
		uOffsetLocation = glGetUniformLocation(program, "uOffset"),
		uWinWidthLoctaion = glGetUniformLocation(program, "uWinWidth"),
		uWinHeightLocation = glGetUniformLocation(program, "uWinHeight");

	//Get the window dimensions and pass them to the shader
	int winW, winH;
	glfwGetWindowSize(win, &winW, &winH); 
	glUniform1i(uWinWidthLoctaion, winW);
	glUniform1i(uWinHeightLocation, winH);

	//Change the color of the tetromino based on the shape
	switch(current.type)
	{
	case 0:
		glUniform4f(uColorLocation, 0.0f, 0.5f, 1.0f, 1.0f);
		break;
	case 1:
		glUniform4f(uColorLocation, 1.0f, 0.5f, 0.0f, 1.0f);
		break;
	case 2:
		glUniform4f(uColorLocation, 1.0f, 1.0f, 0.0f, 1.0f);
		break;
	case 3:
		glUniform4f(uColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);
		break;
	case 4:
		glUniform4f(uColorLocation, 1.0f, 0.0f, 1.0f, 1.0f);
		break;
	case 5:
		glUniform4f(uColorLocation, 1.0f, 0.0f, 0.0f, 1.0f);
		break;
	case 6:
		glUniform4f(uColorLocation, 0.0f, 1.0f, 1.0f, 1.0f);
		break;
	}
	
	//Draw the tetris peice
	for(int i = 0; i < 16; i++)
	{
		int x = i % 4 + current.x, y = (i - i % 4) / 4 + current.y;
		if(current.blocks[i] == '#')
		{
			glUniform2f(uOffsetLocation, (float)x / 5.0f - 0.9f, -(float)y / 10.0f + 0.95f);
			glDrawArrays(GL_TRIANGLES, 0, 6);
		}
	}

	//Draw the fallen blocks
	for(int i = 0; i < 200; i++)
	{
		int x = i % 10, y = (i - i % 10) / 10;
		switch(blocks[i])
		{
		case 1:
			glUniform4f(uColorLocation, 0.0f, 0.5f, 1.0f, 1.0f);
			break;
		case 2:
			glUniform4f(uColorLocation, 1.0f, 0.5f, 0.0f, 1.0f);
			break;
		case 3:
			glUniform4f(uColorLocation, 1.0f, 1.0f, 0.0f, 1.0f);
			break;
		case 4:
			glUniform4f(uColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);
			break;
		case 5:
			glUniform4f(uColorLocation, 1.0f, 0.0f, 1.0f, 1.0f);
			break;
		case 6:
			glUniform4f(uColorLocation, 1.0f, 0.0f, 0.0f, 1.0f);
			break;
		case 7:
			glUniform4f(uColorLocation, 0.0f, 1.0f, 1.0f, 1.0f);
			break;
		case 8:
			glUniform4f(uColorLocation, 0.7f, 0.7f, 0.7f, 1.0f);
			break;
		default:
			continue;
		}

		glUniform2f(uOffsetLocation, (float)x / 5.0f - 0.9f, -(float)y / 10.0f + 0.95f);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
}

void DrawGameOver()
{
	static int index = 200;
	
	if(index >= 0)
	{
		blocks[index] = 8;
		index--;
	}
}
