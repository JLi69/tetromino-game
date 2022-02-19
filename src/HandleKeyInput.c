#include "tetris.h"

void HandleKeyInput(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	//Check if the player lost
	for(int i = 0; i < 10; i++)
		if(blocks[i] != 0)
		{
			gameOver = true;
			return;
		}

	if(gameOver)
		return;

	if(action == GLFW_PRESS)
	{
		switch(key)
		{
		//Move the tetris peice left or right
		case GLFW_KEY_RIGHT:
			printf("right key pressed\n");
			current.x++;
			if(!CheckTetrisPos())
				current.x--;
			break;
		case GLFW_KEY_LEFT:
			printf("left key pressed\n");
			current.x--;
			if(!CheckTetrisPos())
				current.x++;
			break;
		//Rotate the tetris peice
		case GLFW_KEY_UP:
			printf("up key pressed\n");
			current.rotation++;
			RotatePiece();
			if(!CheckTetrisPos())
			{
				current.rotation--;
				RotatePiece();
			}
			break;
		//Drop the tetris peice
		case GLFW_KEY_SPACE:
			while(!CheckTetrisFallen())
			{
				score++;
				current.y++;
			}
			break;
		}

		if(CheckTetrisFallen() && !gameOver)
		{
			for(int i = 0; i < 16; i++)
			{
				int x = current.x + i % 4,
					y = current.y + (i - i % 4) / 4;
				if(current.blocks[i] == '#')
				{
					if(y < 0)
						continue;

					blocks[x + y * 10] = current.type + 1;
				}
			}
			
			GeneratePiece();
		}
	}
}
