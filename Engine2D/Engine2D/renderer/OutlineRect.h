#pragma once
#include <renderer\Mesh.h>
#include <renderer\Transform.h>
#include <renderer\SpriteMaterial.h>

namespace Renderer
{
	class OutlineRect
	{
	public:
		OutlineRect();

		~OutlineRect() {};

		void Update();

		void Draw();

		std::shared_ptr <Mesh> _mesh;
		std::shared_ptr<Color> _color;
		std::shared_ptr<Transform> _transform;
		std::shared_ptr<SpriteMaterial> _material;
	};
}