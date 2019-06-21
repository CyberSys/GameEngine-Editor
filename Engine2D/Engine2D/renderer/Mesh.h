#pragma once
#include <graphics\GraphicsGL.h>
#include <renderer\Color.h>
#include <renderer\MeshFilter.h>

#include <vector>
#include <string>

namespace Renderer
{
	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void SetVertices(std::vector<float> vertices);

		std::vector<float> GetVertices();

		void SetIndices(std::vector<float> Indices);

		std::vector<float> GetIndices();

		Color GetColor();

		void SetColor(Color color);

		void SetTag(std::string tag);

		std::string GetTag();

		void SetUVs(std::vector<float> uvs);

		std::vector<float> GetUVs();

		void CreateVertexBuffer(Graphics::RenderType type, Graphics::MemoryLayout _layout);

		void CreateIndexedVertexBuffer(Graphics::RenderType type, Graphics::MemoryLayout _layout);

		void UpdateVertexBuffer(Graphics::RenderType type);

		int GetVertexCount();

		int GetIndexCount();

		unsigned int GetVBufferID();

		unsigned int GetVAOID();

	protected:
		std::vector<float> _vertices;
		std::vector<float> _indices;
		std::vector<float> _uvs;
		Color _color;
		std::string _tag;
		unsigned int vertexbuffer_id;
		unsigned int vertexArraybuffer_id;
	};
}