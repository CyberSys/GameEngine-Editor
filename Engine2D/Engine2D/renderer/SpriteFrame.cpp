#include "SpriteFrame.h"

namespace Renderer
{
	SpriteFrame::SpriteFrame(){}

	SpriteFrame::~SpriteFrame(){}

	glm::vec4 SpriteFrame::GetFrame(){
		return _frame;
	}

	void SpriteFrame::SetFrame(glm::vec4& frame){
		_frame = frame;
	}
}

