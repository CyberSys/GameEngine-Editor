#include "Renderer.h"

namespace Renderer
{
	void Renderer::Render(Graphics::Primitive type, unsigned int vao, unsigned int vbo)
	{
		Graphics::GAPI_Draw(type, vao, vbo, 6);
	}
}
