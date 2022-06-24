#version 330 core

uniform vec4 uColor;
uniform int uWinWidth, uWinHeight;
out vec4 color;

in vec4 gl_FragCoord;

void main()
{
	color = uColor;

	float left, top;
	float winW = float(uWinWidth), winH = float(uWinHeight);
	if(uWinWidth * 2 < uWinHeight)
	{
		left = 0.0;
		top = winH / 2.0 - winW;
		winH = winW * 2.0;
	}
	else if(uWinWidth * 2.0 >= uWinHeight)
	{
		left = winW / 2.0 - winH / 4.0; 
		top = 0.0;
		winW = winH / 2.0; 
	}

	float gridWidth = winW / 10.0, gridHeight = winH / 20.0;

	float tempX = fract((gl_FragCoord.x - left) / gridWidth), tempY = fract((gl_FragCoord.y - top) / gridHeight);

	//Shade the edges of the square
	if(tempX < tempY)
		color *= 0.8;
	else if(tempX >= tempY)
		color *= 0.6;
	
	if(gridWidth - tempX < tempY)
		color *= 0.7;
	else if(gridWidth - tempX >= tempY)
		color *= 0.9;
	
	if(tempX > 1.0 / 6.0 && tempY > 1.0 / 6.0 && tempX <= 5.0 / 6.0 && tempY <= 5.0 / 6.0)
	{
		color = uColor * 0.85;
	}
}
