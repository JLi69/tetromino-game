#include "tetris.h"

unsigned int CreateShader(const char* filename, const GLenum shaderType)
{
	int currentCh = 0;

	unsigned int shaderId = glCreateShader(shaderType);
	FILE* shaderFile = fopen(filename, "r");
	char* src = malloc(1024); //Assume that the file is less than 1024 bytes in size
	while((src[currentCh] = fgetc(shaderFile)) != EOF) currentCh++;
	const char* srcBegin = &src[0]; //The beginning of the source
	glShaderSource(shaderId, 1, &srcBegin, NULL); //Get the source for the shader
	glCompileShader(shaderId); //Compile the shader
	free(src);

	fclose(shaderFile); //Close the file

	return shaderId;
}

unsigned int SetupShaderProgram()
{
	//Create the program
	unsigned int program = glCreateProgram();

	//Set up the fragment shader
	unsigned int fs = CreateShader("shaders/basic-fragment.glsl", GL_FRAGMENT_SHADER);
	//Set up the vertex shader
	unsigned int vs = CreateShader("shaders/basic-vertex.glsl", GL_VERTEX_SHADER);

	//Attach/Link the shaders to the program
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	//Clean up
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int SetupVertexBuffer()
{
	//Set up the array buffer
	float square[] = 
	{
		-0.1f, -0.05f, 	//Lower left corner
		-0.1f, 0.05f,  	//Upper left corner
		0.1f, 0.05f,   	//Upper right corner

		0.1f, 0.05f,  	//Upper right corner
		0.1f, -0.05f, 	//Lower right corner
		-0.1f, -0.05f,  //Lower left corner
	};
	unsigned int id;
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, sizeof(float) * 2, (void*)0);
	glEnableVertexAttribArray(0);

	return id;
}

void Init(GLFWwindow** win)
{
	//Initialize glfw
	if(!glfwInit()) exit(-1);

	//Initialize and set up the window
	*win = glfwCreateWindow(400, 800, "Tetris Clone", NULL, NULL);
	if(!*win)
	{
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(*win);

	//Initialize glad
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		exit(-1);

	//Set up key input
	glfwSetKeyCallback(*win, HandleKeyInput);
	//Handle window reszing
	glfwSetWindowSizeCallback(*win, HandleWinResize);

	//Set the random seed
	srand(time(NULL));
}
