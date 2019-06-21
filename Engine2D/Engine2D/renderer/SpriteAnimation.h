#pragma once
#include <renderer\Texture2D.h>
#include <renderer\SpriteFrame.h>

#include <vector>
#include <memory>

namespace Renderer
{
	class SpriteAnimation
	{
	public:
		SpriteAnimation(Texture2D* texture);

		~SpriteAnimation();

		std::vector<glm::vec4> GetFrames();

		void Animation_Play();

	private:
		void GenerateFramesFromTexture();
		

		std::vector<SpriteFrame> _frames;
		Texture2D* _texture;
	};
}