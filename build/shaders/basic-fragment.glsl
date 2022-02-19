#version 330 core

uniform vec4 uColor;
out vec4 color;

in vec4 gl_FragCoord;

void main()
{
	color = uColor;

	int tempX = int(gl_FragCoord.x) % 40, tempY = int(gl_FragCoord.y) % 40;

	if(tempX < tempY)
		color *= 0.8;
	else if(tempX >= tempY)
		color *= 0.6;
	
	if(40 - tempX < tempY)
		color *= 0.7;
	else if(40 - tempX >= tempY)
		color *= 0.9;
	
	if(tempX > 5 && tempY > 5 && tempX < 34 && tempY < 34)
		color = uColor * 0.85;
}
