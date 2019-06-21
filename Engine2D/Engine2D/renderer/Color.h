#pragma once
#include <glm.hpp>

namespace Renderer
{
	class Color
	{
	public:
		Color();

		Color(glm::vec4 color);

		~Color();

		void SetColor(glm::vec4 color);

		glm::vec4 GetColor();

	private:
		glm::vec4 color;
	};
}