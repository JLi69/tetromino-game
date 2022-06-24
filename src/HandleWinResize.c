#include "tetris.h"

void HandleWinResize(GLFWwindow *win, int width, int height)
{	
	if(width * 2 < height)	
		glViewport(0, height / 2 - width, width, width * 2);
	else if(width * 2 >= height)
		glViewport(width / 2 - height / 4, 0, height / 2, height); 
}
