#pragma once
#include <glm.hpp>

namespace Renderer
{
	class Shader
	{
	public:
		Shader();
		Shader(char* vs, char* ps);
		~Shader();

		void Use();

		void Send_Vec2_to_GPU(char* variable_name, glm::vec2 vec);

		void Send_Vec4_to_GPU(char* variable_name, glm::vec4 vec);

		void Send_Mat4_to_GPU(char* variable_name, glm::mat4 mat);

	private:
		unsigned int shaderprogram_id;
		char *vertexShaderSource;
		char *fragmentShaderSource;
	};
}