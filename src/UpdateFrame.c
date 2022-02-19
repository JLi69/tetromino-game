#include "tetris.h"

void UpdateFrame()
{
	//Check if the player lost
	for(int i = 0; i < 10; i++)
		if(blocks[i] != 0)
		{
			gameOver = true;
			return;
		}

	//Cause the tetris peice to fall down
	current.y++;

	if(CheckTetrisFallen() && !gameOver)
	{
		for(int i = 0; i < 16; i++)
		{
			int x = current.x + i % 4,
				y = current.y + (i - i % 4) / 4;
			if(current.blocks[i] == '#')
			{
				//Check if the player lost
				if(y < 0)
					continue;	

				blocks[x + y * 10] = current.type + 1;
			}
		}
		
		GeneratePiece();	
	}

	//Clear any completed lines
	int completedLineCount = 0;
	for(int i = 0; i < 20; i++)
	{
		bool completed = true;
		for(int j = 0; j < 10 && completed; j++)
			completed = completed && (blocks[i * 10 + j] != 0);

		if(completed)
		{
			completedLineCount++;
			score += completedLineCount * 20;

			for(int j = 0; j < 10; j++)
				blocks[i * 10 + j] = 0;
			
			//Cause any blocks above to fall
			for(int j = i; j > 0; j--)
			{
				for(int j2 = 0; j2 < 10; j2++)
				{
					blocks[j * 10 + j2] = blocks[(j - 1) * 10 + j2];
				}
			}
		}
	}
}

//Check if the tetris peice has fallen to
//the bottom of the screen or if it fell
//on top of another tetromino
bool CheckTetrisFallen()
{
	for(int i = 0; i < 16; i++)
	{
		if(current.blocks[i] == '#')
		{
			if(current.y + ((i - i % 4) / 4) == 19)
				return true;

			if(current.y + ((i - i % 4) / 4) < 0)
				continue;
			
			int nextY = current.y + ((i - i % 4) / 4) + 1;
			if(blocks[nextY * 10 + current.x + i % 4] != 0)
				return true; 
		}
	}

	return false;
}

//Check if the tetris position is valid
bool CheckTetrisPos()
{
	for(int i = 0; i < 16; i++)
	{
		if(current.blocks[i] == '#')
		{
			//Block is out of bounds
			if(current.x + (i % 4) < 0 || current.x + (i % 4) >= 10 || current.y + ((i - i % 4) / 4) >= 20)
				return false;
			if(current.y + ((i - i % 4) / 4) >= 0)
			{
				int index = (current.x + i % 4) + (current.y + ((i - i % 4) / 4)) * 10;
				if(blocks[index] != 0)
					return false;
			}
		}
	}
	//In valid position
	return true;
}

//Rotate the tetromino
void RotatePiece()
{
	switch(current.type)
	{
	case 0:
		current.rotation += 2;
		current.rotation %= 2;
		switch(current.rotation)
		{
		case 0:
			strcpy(&current.blocks[0], "    "
									   "####"
									   "    "
									   "   ");
			break;
		case 1:
			strcpy(&current.blocks[0], " #  "
									   " #  "
									   " #  "
									   " # ");

			break;
		}
		break;
	case 1:
		current.rotation += 4;
		current.rotation %= 4;
		switch(current.rotation)
		{
		case 0:
			strcpy(&current.blocks[0], "    "
									   "### "
									   " #  "
									   "   ");
			break;
		case 1:
			strcpy(&current.blocks[0], " #  "
									   " ## "
									   " #  "
									   "   ");
			break;
		case 2:
			strcpy(&current.blocks[0], " #  "
									   "### "
									   "    "
									   "   ");
			break;
		case 3:
			strcpy(&current.blocks[0], " #  "
									   "##  "
									   " #  "
									   "   ");
			break;
		}
		break;
	case 2:
		current.rotation += 1;
		current.rotation %= 1;
		break;
	case 3:
		current.rotation += 4;
		current.rotation %= 4;
		switch(current.rotation)
		{
		case 0:
			strcpy(&current.blocks[0], "    "
									   "### "
									   "#   "
									   "   ");
			break;
		case 1:
			strcpy(&current.blocks[0], " #  "
									   " #  "
									   " ## "
									   "   ");
			break;
		case 2:
			strcpy(&current.blocks[0], "    "
									   "  # "
									   "### "
									   "   ");
			break;
		case 3:
			strcpy(&current.blocks[0], " ## "
									   "  # "
									   "  # "
									   "   ");
			break;
		}
		break;
	case 4:
		current.rotation += 4;
		current.rotation %= 4;
		switch(current.rotation)
		{
		case 0:
			strcpy(&current.blocks[0], "    "
									   " ###"
									   "   #"
									   "   ");
			break;
		case 1:
			strcpy(&current.blocks[0], "  # "
									   "  # "
									   " ## "
									   "   ");
			break;
		case 2:
			strcpy(&current.blocks[0], "    "
									   " #  "
									   " ###"
									   "   ");
			break;
		case 3:
			strcpy(&current.blocks[0], " ## "
									   " #  "
									   " #  "
									   "   ");
			break;
		}
		break;
	case 5:
		current.rotation += 2;
		current.rotation %= 2;
		switch(current.rotation)
		{
		case 0:
			strcpy(&current.blocks[0], "    "
									   "##  "
									   " ## "
									   "   ");
			break;
		case 1:
			strcpy(&current.blocks[0], "  # "
									   " ## "
									   " #  "
									   "   ");
			break;
		}
		break;
	case 6:
		current.rotation += 2;
		current.rotation %= 2;
		switch(current.rotation)
		{
		case 0:
			strcpy(&current.blocks[0], "    "
									   "  ##"
									   " ## "
									   "   ");
			break;
		case 1:
			strcpy(&current.blocks[0], " #  "
									   " ## "
									   "  # "
									   "   ");
			break;
		}
		break;
	}
}
