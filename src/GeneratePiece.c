#include "tetris.h"

void GeneratePiece()
{
	current.type = rand() % 7;
	printf("Piece: %d\n", current.type);

	//Set the position of the tetris peice
	current.x = 3;
	current.y = -3;
	//Set the rotation of the tetromino
	current.rotation = 0;

	//Create the tetromino
	switch(current.type)
	{
	case 0:
		strcpy(&current.blocks[0], "    "
								   "####"
								   "    "
								   "   ");
		break;
	case 1:
		strcpy(&current.blocks[0], "    "
								   "### "
								   " #  "
								   "   ");
		break;
	case 2:
		strcpy(&current.blocks[0], "    "
								   " ## "
								   " ## "
								   "   ");
		break;
	case 3:
		strcpy(&current.blocks[0], "    "
								   "### "
								   "#   "
								   "   ");
		break;
	case 4:
		strcpy(&current.blocks[0], "    "
								   " ###"
								   "   #"
								   "   ");
		break;
	case 5:
		strcpy(&current.blocks[0], "    "
								   "##  "
								   " ## "
								   "   ");
		break;
	case 6:
		strcpy(&current.blocks[0], "    "
								   "  ##"
								   " ## "
								   "   ");
		break;
	}
}
