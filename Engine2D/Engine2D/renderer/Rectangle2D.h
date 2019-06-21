#pragma once
#include <renderer\Mesh.h>

namespace Renderer
{
	class Rectangle2D
	{
	public:
		static std::shared_ptr<Mesh> Rectangle2D_Build();
		static std::shared_ptr<Mesh> Rectangle2D_Build(float w, float h);
		static std::shared_ptr<Mesh> Rectangle2D_Build(float w, float h, float u, float v);

		static std::shared_ptr<Mesh> RectangleOutline_Build();
	};
}