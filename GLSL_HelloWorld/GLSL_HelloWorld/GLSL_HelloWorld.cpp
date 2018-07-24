// GLSL_HelloWorld.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define GLFW_DLL
#define GLFW_INCLUDE_GLU
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3dll_d.lib")

void InitApp() {
	// Ŭ���� ����(����) ����
	glClearColor(1, 1, 1, 1);
}

void ErrorCallback(int error, const char* description) {
	std::cout << description << std::endl;
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void WindowSizeChangeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}



int _tmain(int argc, _TCHAR* argv[])
{
	// GLFW ������ �ڵ鷯
	GLFWwindow* window = NULL;

	// ���� �ڵ鷯 ���
	glfwSetErrorCallback(ErrorCallback);

	// GLFW �ʱ�ȭ
	if (!glfwInit())
		exit(EXIT_FAILURE);

	// ������ ����
	window = glfwCreateWindow(640, 480, "Tutorial 00: Test", NULL, NULL);
	if (!window) {
		// ���� ������ ������ �����ߴٸ� ���ø����̼� ����
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// ���ؽ�Ʈ ����
	glfwMakeContextCurrent(window);

	// swap ���� ����
	glfwSwapInterval(1);

	// Ű �ڵ鷯 ���
	glfwSetKeyCallback(window, KeyCallback);
	// ������ ������ ���� �ڵ鷯 ���
	glfwSetWindowSizeCallback(window, WindowSizeChangeCallback);

	// GLEW �ʱ�ȭ
	glewInit();

	// ���ø����̼��� �ʱ�ȭ
	InitApp();

	// �� ������ ����. �����찡 ����Ǳ� ������ �ݺ��Ѵ�.
	while (!glfwWindowShouldClose(window))
	{
		// ���� �����
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ���⿡ Update/Render �ڵ� 

		// ���� ���� ��ü. (�׸� ����� ���÷����ϴ� ���)
		glfwSwapBuffers(window);

		// ������ �̺�Ʈ (Ű ��Ʈ��ũ ��) ����.
		glfwPollEvents();
	}

	// ������ ����
	glfwDestroyWindow(window);

	// GLFW ����
	glfwTerminate();

	return 0;


}

