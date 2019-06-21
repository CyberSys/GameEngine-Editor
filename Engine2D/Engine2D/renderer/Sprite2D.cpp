#include "Sprite2D.h"

#include <renderer\Rectangle2D.h>
#include <renderer\Renderer.h>


namespace Renderer
{
	Sprite2D::Sprite2D(char* texture_filepath)
	{
		_transform = std::make_shared<Transform>();
		_color = std::make_shared<Color>();
		_material = std::make_shared<SpriteMaterial>();
		_texture = std::make_shared<Texture2D>(texture_filepath);

		_mesh = Rectangle2D::Rectangle2D_Build();

		Update();
	}

	void Sprite2D::Update()
	{
		_material->UseShader();
		_material->SetColor(_material->GetColor());
		_material->SetUVs(_material->GetUVs());
		_material->IsTextureEnabled(glm::vec4(1));
		_material->SetTransformation(_transform->GetTransformMat());
	}

	void Sprite2D::Draw()
	{
		Update();
		_texture->Attach_Texture_to_Geomtry();
		Renderer::Render(Graphics::Primitive::TRIANGLES,_mesh->GetVAOID(), _mesh->GetVBufferID());
	}
}
