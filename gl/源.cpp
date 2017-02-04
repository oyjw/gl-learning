#include <stdlib.h>
#include <GL/glew.h>
#include <GL\GL.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "matrix.h"
void Init();
void keyboard(unsigned char key, int x, int y);
void display(void);
GLuint CreateProgram(const char* vertex_shader_file_name, const char* fragment_shader_file_name);
    
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(512,512);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("GLUT Test");
	if (glewInit()) {
		std::cerr << "Unable to initialize GLEW ... exiting" << std::endl;
		exit(EXIT_FAILURE);
	}
	Init();
	glutKeyboardFunc(&keyboard);
	glutDisplayFunc(&display);
	//
	glutMainLoop();

	return EXIT_SUCCESS;
}
   

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '\x1B':
	exit(EXIT_SUCCESS);
	break;
	}
}
GLuint vao;
GLuint vbo;
const float vertexData[] = {
	 0.25f,  0.25f, -1.0f, 1.0f,
	 0.25f, -0.25f, -1.0f, 1.0f,
	-0.25f,  0.25f, -1.0f, 1.0f,

	 0.25f, -0.25f, -1.0f, 1.0f,
	-0.25f, -0.25f, -1.0f, 1.0f,
	-0.25f,  0.25f, -1.0f, 1.0f,

	-0.25f,  0.25f, -1.0f, 1.0f,
	-0.25f, -0.25f, -1.0f, 1.0f,
	-0.25f, -0.25f, -3.0f, 1.0f,

	-0.25f,  0.25f, -1.0f, 1.0f,
	-0.25f, -0.25f, -3.0f, 1.0f,
	-0.25f,  0.25f, -3.0f, 1.0f,

	 0.25f,  0.25f, -1.0f, 1.0f,
	 0.25f, -0.25f, -3.0f, 1.0f,
	 0.25f, -0.25f, -1.0f, 1.0f,

	 0.25f,  0.25f, -1.0f, 1.0f,
	 0.25f,  0.25f, -3.0f, 1.0f,
	 0.25f, -0.25f, -3.0f, 1.0f,

	 0.25f,  0.25f, -3.0f, 1.0f,
	 0.25f,  0.25f, -1.0f, 1.0f,
	-0.25f,  0.25f, -1.0f, 1.0f,

	 0.25f,  0.25f, -3.0f, 1.0f,
	-0.25f,  0.25f, -1.0f, 1.0f,
	-0.25f,  0.25f, -3.0f, 1.0f,

	 0.25f, -0.25f, -3.0f, 1.0f,
	-0.25f, -0.25f, -1.0f, 1.0f,
	 0.25f, -0.25f, -1.0f, 1.0f,

	 0.25f, -0.25f, -3.0f, 1.0f,
	-0.25f, -0.25f, -3.0f, 1.0f,
	-0.25f, -0.25f, -1.0f, 1.0f,

	0.25f,  0.25f, -3.0f, 1.0f,
	-0.25f,  0.25f, -3.0f, 1.0f,
	0.25f, -0.25f, -3.0f, 1.0f,

	0.25f, -0.25f, -3.0f, 1.0f,
	-0.25f,  0.25f, -3.0f, 1.0f,
	-0.25f, -0.25f, -3.0f, 1.0f,


	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,


	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

};
void
Init(void)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData),
		vertexData, GL_STATIC_DRAW);
		
	GLuint program = CreateProgram("test.vert" , "test.frag");
	glUseProgram(program);

	GLfloat n = 1.0f, f = 3.0f;
	GLint location = glGetUniformLocation(program, "perspectiveMatrix");
	GLfloat matrix[16] = { 0 };
	memset(matrix, 0, sizeof(matrix));
	matrix[0] = 1.0f;
	matrix[5] = 1.0f;
	/*matrix[10] = 1.0f;
	matrix[15] = 1.0f;*/
	matrix[10] = 2.0f;// (n + f) / (f - n);
	matrix[14] = 3.0f;// (2 * n * f) / (f - n);
	matrix[11] = -1.0f;
	glUniformMatrix4fv(location, 1, GL_FALSE, matrix);

	Matrix4 test_matrix;
	test_matrix.values[0] = 1.0f;
	test_matrix.values[5] = 1.0f;
	/*matrix[10] = 1.0f;
	matrix[15] = 1.0f;*/
	test_matrix.values[10] = 2.0f;// (n + f) / (f - n);
	test_matrix.values[14] = 3.0f;// (2 * n * f) / (f - n);
	test_matrix.values[11] = -1.0f;

	for (int i = 0; i < 36; ++i)
	{
		if (i % 3 == 0) std::cout << std::endl;
		float tmp[4];
		float in[4];
		for (int j = 0; j < 4; ++j)
		{
			in[j] = vertexData[i * 4 + j];
		}
		test_matrix.mul(in, tmp);
		for (int i = 0; i < 4; ++i)
		{
			std::cout << tmp[i]/tmp[3] << "  ";
		}
		std::cout << std::endl;
	}
	location = glGetUniformLocation(program, "offset");
	glUniform3f(location, 0.0f, 0.0f, 0.0f);
	glVertexAttribPointer(0, 4, GL_FLOAT,
		GL_FALSE, 0, 0);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)(12*12*4));
	size_t colorData = sizeof(vertexData) / 2;
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);


	/*glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);*/

}

std::string FindFileOrThrow(const char* file_name)
{
	std::ifstream testFile(file_name);
	if(testFile.is_open())
		return file_name;

	throw std::runtime_error("Could not find the file " + std::string(file_name));
}

GLuint CompileShader(GLenum shader_type, const char* shader_source)
{
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &shader_source, NULL);
	glCompileShader(shader);
	GLint ret;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &ret);
	if (ret != GL_TRUE)
	{
		char buf[1024];
		glGetShaderInfoLog(shader, 1024, NULL, buf);
		std::cerr << buf << std::endl;
		std::flush(std::cerr);
		system("pause");
	}
	return shader;
}

GLuint LoadShader(GLenum shader_type, const char* shader_file_name)
{
	std::string strFilename = FindFileOrThrow(shader_file_name);
	std::ifstream shaderFile(strFilename.c_str());
	std::stringstream shaderData;
	shaderData << shaderFile.rdbuf();
	shaderFile.close();
	std::cout << shaderData.str().c_str() << std::endl;
	return CompileShader(shader_type, shaderData.str().c_str());
}


GLuint CreateProgram(const char* vertex_shader_file_name, const char* fragment_shader_file_name)
{
	GLuint vertex_shader = LoadShader(GL_VERTEX_SHADER, vertex_shader_file_name);
	GLuint fragment_shader = LoadShader(GL_FRAGMENT_SHADER, fragment_shader_file_name);
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	GLint ret;
	glGetProgramiv(program, GL_LINK_STATUS, &ret);
	if (ret != GL_TRUE)
	{
		char buf[1024];
		glGetProgramInfoLog(program, 1024, NULL, buf);
		std::cerr << buf << std::endl;
		std::flush(std::cerr);
		exit(EXIT_FAILURE);
	}
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	std::cout << "success" << std::endl;
	std::flush(std::cout);
	return program;
}

void display()
{
	glViewport(0, 0, 512, 512); 
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	 
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glutSwapBuffers();
	std::cout << (glGetError()==GL_NO_ERROR )<< std::endl;

	std::cout << glGetError() << std::endl;
}