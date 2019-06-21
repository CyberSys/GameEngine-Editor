#pragma once
#include <graphics\GraphicsGL.h>

namespace Renderer
{
	class Renderer
	{
	public:
		static void Render(Graphics::Primitive type,unsigned int vao, unsigned int vbo);
	};
}