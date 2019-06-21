#include "Texture2D.h"

#include <graphics\GraphicsGL.h>
#include <stb_image.h>

using namespace Graphics;

namespace Renderer
{
	Texture2D::Texture2D(char * filename)
	{
		ReadImageFromFile(filename);

		if (data)
		{
			textureID = GAPI_CreateTexture2D(width, height, data, true);

			GAPI_ApplySamplerTex2D(textureID, true,
				TextureAddressMode::WRAP,
				TextureAddressMode::WRAP,
				TextureFilter::LINEAR,
				ComparisonFunction::NEVER, 0, 0, 0, 1);
		}
	}

	Texture2D::~Texture2D(){}

	void Texture2D::Attach_Texture_to_Geomtry()
	{
		GAPI_BindTexture2D(textureID, 0);
	}

	void Texture2D::DeleteTextureFromGPU()
	{
		GAPI_DeleteTexture2D(textureID);
	}

	unsigned char * Texture2D::GetData()
	{
		return data;
	}

	glm::vec3 Texture2D::GetDimensions()
	{
		return glm::vec3(width, height, depth);
	}

	void Texture2D::ReadImageFromFile(char * filename)
	{
		data = stbi_load(filename, &width, &height, &depth, 0);
	}
}