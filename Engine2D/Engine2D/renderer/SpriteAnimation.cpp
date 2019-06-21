#include "SpriteAnimation.h"


namespace Renderer
{
	using namespace std;

	SpriteAnimation::SpriteAnimation(Texture2D* texture)
	{
		_texture = texture;
	}

	SpriteAnimation::~SpriteAnimation()
	{
	}

	std::vector<glm::vec4> SpriteAnimation::GetFrames()
	{
		return std::vector<glm::vec4>();
	}

	void SpriteAnimation::Animation_Play()
	{
	}

	void SpriteAnimation::GenerateFramesFromTexture()
	{

	}

}

