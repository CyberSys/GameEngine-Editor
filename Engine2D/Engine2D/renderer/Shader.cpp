#include "Shader.h"

#include <graphics\GraphicsGL.h>

namespace Renderer
{
	Shader::Shader()
	{
	}

	Shader::Shader(char* vs, char* ps) : shaderprogram_id(-1),
		vertexShaderSource(nullptr),fragmentShaderSource(nullptr)
	{

		vertexShaderSource = vs;

		fragmentShaderSource = ps;

		//create shader 
		shaderprogram_id = Graphics::GAPI_CreateProgram(vertexShaderSource, fragmentShaderSource);
	}

	Shader::~Shader()
	{

	}

	void Shader::Use()
	{
		Graphics::GAPI_BindShader(shaderprogram_id);
	}

	void Shader::Send_Vec2_to_GPU(char * variable_name, glm::vec2 vec)
	{
		Graphics::GAPI_SetUniform_vec2(shaderprogram_id, variable_name, vec);
	}

	void Shader::Send_Vec4_to_GPU(char* variable_name, glm::vec4 vec)
	{
		Graphics::GAPI_SetUniform_vec4(shaderprogram_id, variable_name, vec);
	}

	void Shader::Send_Mat4_to_GPU(char* variable_name, glm::mat4 mat)
	{
		Graphics::GAPI_SetUniform_mat4(shaderprogram_id, variable_name, mat);
	}
}