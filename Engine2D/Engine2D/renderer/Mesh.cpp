#include "renderer\Mesh.h"

#include <iostream>

using namespace Graphics;

namespace Renderer
{
	Mesh::Mesh() : vertexbuffer_id(-1), vertexArraybuffer_id(-1) , _tag("")
	{
	}

	Mesh::~Mesh()
	{
	}

	void Mesh::SetVertices(std::vector<float> vertices)
	{
		_vertices = vertices;
	}

	std::vector<float> Mesh::GetVertices()
	{
		return _vertices;
	}

	void Mesh::SetIndices(std::vector<float> Indices)
	{
		_indices = Indices;
	}

	std::vector<float> Mesh::GetIndices()
	{
		return _indices;
	}

	Color Mesh::GetColor()
	{
		return _color;
	}

	void Mesh::SetColor(Color color)
	{
		_color = color;
	}

	void Mesh::SetTag(std::string tag)
	{
		_tag = tag;
	}

	std::string Mesh::GetTag()
	{
		return _tag;
	}

	void Mesh::SetUVs(std::vector<float> uvs)
	{
		_uvs = uvs;
	}

	std::vector<float> Mesh::GetUVs()
	{
		return _uvs;
	}

	void Mesh::CreateVertexBuffer(Graphics::RenderType type, Graphics::MemoryLayout _layout)
	{
		if (_vertices.size() == 0)
		{
			std::cout<< "you must fill vertex array before create one." << std::endl;
			return;
		}
		else if(_vertices.size() != 0 && _uvs.size() == 0)
		{
			std::cout << "you must fill UV Coords before create one." << std::endl;
			return;
		}

		std::vector<float> vBufer;
		//(6 verts * 3 components) + (6 uvs * 2 components)
		size_t offset = 3; //3 components each vertx	
		int j = 0;
		for (size_t i = 0; i < _vertices.size(); i += offset)
		{
			if (j < _uvs.size())
			{
				vBufer.push_back(_vertices[i]);
				vBufer.push_back(_vertices[i+1]);
				vBufer.push_back(_vertices[i+2]);
				vBufer.push_back(_uvs[j]);
				vBufer.push_back(_uvs[j+1]);
				j += 2;
			}
			else
			{
				vBufer.push_back(_vertices[i]);
				vBufer.push_back(_vertices[i + 1]);
				vBufer.push_back(_vertices[i + 2]);
			}
		}

		//create vertex buffer object to fill
		vertexbuffer_id = GAPI_CreateVertexBuffer(type, sizeof(vBufer[0]) * vBufer.size(), &vBufer[0]);

		//create vertex array object to handle all vertex buffers..
		vertexArraybuffer_id = GAPI_CreateVertexArray(vertexbuffer_id, 0, _layout);
	}

	void Mesh::CreateIndexedVertexBuffer(Graphics::RenderType type, Graphics::MemoryLayout _layout)
	{
	}

	void Mesh::UpdateVertexBuffer(Graphics::RenderType type)
	{
		//to do here
		if (_vertices.size() == 0)
		{
			std::cout << "you must fill vertex array before create one." << std::endl;
			return;
		}
		else if (_vertices.size() != 0 && _uvs.size() == 0)
		{
			std::cout << "you must fill UV Coords before create one." << std::endl;
			return;
		}

		std::vector<float> vBufer;
		//(6 verts * 3 components) + (6 uvs * 2 components)
		size_t offset = 3; //3 components each vertx	
		int j = 0;
		for (size_t i = 0; i < _vertices.size(); i += offset)
		{
			if (j < _uvs.size())
			{
				vBufer.push_back(_vertices[i]);
				vBufer.push_back(_vertices[i + 1]);
				vBufer.push_back(_vertices[i + 2]);
				vBufer.push_back(_uvs[j]);
				vBufer.push_back(_uvs[j + 1]);
				j += 2;
			}
			else
			{
				vBufer.push_back(_vertices[i]);
				vBufer.push_back(_vertices[i + 1]);
				vBufer.push_back(_vertices[i + 2]);
			}
		}

		Graphics::GAPI_UpdateVertexBuffer(vertexbuffer_id, type, sizeof(vBufer[0]) * vBufer.size(), &vBufer[0]);
	}

	int Mesh::GetVertexCount()
	{
		return _vertices.size() / 3;
	}

	int Mesh::GetIndexCount()
	{
		return _indices.size() / 3;
	}

	unsigned int Mesh::GetVBufferID()
	{
		return vertexbuffer_id;
	}

	unsigned int Mesh::GetVAOID()
	{
		return vertexArraybuffer_id;
	}
}