#pragma once
#include <glm.hpp>

namespace Renderer
{
	class SpriteFrame
	{
	public:
		SpriteFrame();

		~SpriteFrame();

		glm::vec4 GetFrame();

		void SetFrame(glm::vec4& frame);
	private:
		glm::vec4 _frame;
	};
}