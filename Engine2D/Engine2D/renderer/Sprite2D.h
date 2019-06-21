#pragma once
#include <renderer\Mesh.h>
#include <renderer\Transform.h>
#include <renderer\Texture2D.h>
#include <renderer\SpriteMaterial.h>
#include <renderer\SpriteAnimation.h>



namespace Renderer
{
	class Sprite2D
	{
	public:
		Sprite2D(char* texture_filepath);

		~Sprite2D() {};

		void Update();

		void Draw();

		std::shared_ptr <Mesh> _mesh;
		std::shared_ptr<Color> _color;
		std::shared_ptr<Texture2D> _texture;
		std::shared_ptr<Transform> _transform;
		std::shared_ptr<SpriteMaterial> _material;
	};
}