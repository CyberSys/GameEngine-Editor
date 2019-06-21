#pragma once
#include <renderer\Shader.h>
#include <renderer\Color.h>

#include <memory>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>

namespace Renderer
{
	class SpriteMaterial
	{
	public:
		SpriteMaterial();

		~SpriteMaterial();

		void SetColor(glm::vec4& color);

		void SetUVs(glm::vec2& UVoffset);

		void IsTextureEnabled(glm::vec4& val);

		glm::vec2& GetUVs();

		glm::vec4& GetColor();

		void SetTransformation(glm::mat4 & transform);

		void UseShader();

	private:
		std::shared_ptr<Shader> _shader;
		glm::vec4 color;
		glm::vec2 UVoffset;
	};
}