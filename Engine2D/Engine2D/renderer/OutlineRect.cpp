#include "OutlineRect.h"

#include <renderer\Rectangle2D.h>
#include <renderer\Renderer.h>

namespace Renderer
{
	OutlineRect::OutlineRect()
	{
		Graphics::GAPI_Enable(Graphics::MULTISAMPLING);
		_transform = std::make_shared<Transform>();
		_color = std::make_shared<Color>();
		_material = std::make_shared<SpriteMaterial>();

		_mesh = Rectangle2D::RectangleOutline_Build();

		Update();
	}

	void OutlineRect::Update()
	{
		_material->UseShader();
		_material->SetColor(_material->GetColor());
		_material->IsTextureEnabled(glm::vec4(0));
	}

	void OutlineRect::Draw()
	{
		Update();
		_material->SetTransformation(_transform->GetTransformMat());
		Renderer::Render(Graphics::Primitive::LINE_STRIP, _mesh->GetVAOID(), _mesh->GetVBufferID());
		Renderer::Render(Graphics::Primitive::POINTS, _mesh->GetVAOID(), _mesh->GetVBufferID());
	}
}
