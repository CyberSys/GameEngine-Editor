#pragma once

#include "MemoryElement.h"
#include <vector>

namespace Graphics
{
	struct MemoryLayout
	{
		unsigned int size = 0;
		std::vector<MemoryElement> elements;
	};
}