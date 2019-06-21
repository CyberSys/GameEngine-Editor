#include "SpriteMaterial.h"

namespace Renderer
{
	SpriteMaterial::SpriteMaterial() : UVoffset(glm::vec2(1)) , color(glm::vec4(1))
	{
		char* vs = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec2 aTexCoord;\n"
			"uniform mat4 MVP_Mat;\n"
			"uniform vec2 UVoffset;\n"
			"out vec2 TexCoord;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = MVP_Mat * vec4(aPos,1);\n"
			
			"   TexCoord = aTexCoord * UVoffset;\n"
			"}\0";

		char* ps = "#version 330 core\n"
			"in vec2 TexCoord;\n"
			"out vec4 FragColor;\n"
			"uniform vec4 color;\n"
			"uniform vec4 hasTex;\n"
			"uniform sampler2D ourTexture;\n"
			"void main()\n"
			"{\n"
			"if(hasTex.x == 1)\n"
			"   FragColor = texture(ourTexture, TexCoord) * vec4(color.x, color.y, color.z, color.w);\n"
			"else\n"
			"   FragColor = vec4(color.x, color.y, color.z, color.w);\n"
			"}\n\0";

		_shader = std::make_shared<Shader>(vs,ps);

	}
	SpriteMaterial::~SpriteMaterial()
	{
	}

	void SpriteMaterial::SetColor(glm::vec4& color)
	{
		this->color = color;
		_shader->Send_Vec4_to_GPU("color", color);
	}

	void SpriteMaterial::SetUVs(glm::vec2& UVoffset)
	{
		this->UVoffset = UVoffset;
		_shader->Send_Vec2_to_GPU("UVoffset", UVoffset);
	}

	void SpriteMaterial::IsTextureEnabled(glm::vec4 & val)
	{
		_shader->Send_Vec4_to_GPU("hasTex", val);
	}

	glm::vec2 & SpriteMaterial::GetUVs()
	{
		return UVoffset;
	}

	glm::vec4 & SpriteMaterial::GetColor()
	{
		return color;
	}

	void SpriteMaterial::SetTransformation(glm::mat4 & transform)
	{
		_shader->Send_Mat4_to_GPU("MVP_Mat",transform);
	}

	void SpriteMaterial::UseShader()
	{
		_shader->Use();
	}
}