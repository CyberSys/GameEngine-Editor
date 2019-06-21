#include "Color.h"

namespace Renderer
{
	Color::Color() : color(glm::vec4(1.0f))
	{
	}

	Color::Color(glm::vec4 color)
	{
		this->color = color;
	}

	Color::~Color() {}

	void Color::SetColor(glm::vec4 color)
	{
		this->color = color;
	}

	glm::vec4 Color::GetColor()
	{
		return color;
	}
}
