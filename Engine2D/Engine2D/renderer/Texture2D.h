#pragma once
#include <glm.hpp>

namespace Renderer
{
	class Texture2D
	{
	public:
		Texture2D(char* filename);

		~Texture2D();

		void Attach_Texture_to_Geomtry();

		void DeleteTextureFromGPU();

		unsigned char* GetData();

		glm::vec3 GetDimensions();
	private:

		void ReadImageFromFile(char* filename);

		unsigned char* data;
		int width;
		int height;
		int depth;
		unsigned int textureID;
	};
}