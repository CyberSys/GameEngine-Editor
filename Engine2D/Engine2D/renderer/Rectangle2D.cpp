#include "Rectangle2D.h"

namespace Renderer
{
	using namespace Graphics;

	std::shared_ptr<Mesh> Rectangle2D::Rectangle2D_Build()
	{
		std::shared_ptr<Mesh> res(new Mesh());
		std::vector<float> _vertices;
		std::vector<float> _uvs;

		//vertex1
		_vertices.push_back(1);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex2
		_vertices.push_back(1);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex3
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex4
		_vertices.push_back(1);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex5
		_vertices.push_back(0);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex6
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		res->SetVertices(_vertices);

		//uv1
		_uvs.push_back(1);
		_uvs.push_back(0);

		//uv2
		_uvs.push_back(1);
		_uvs.push_back(1);

		//uv3
		_uvs.push_back(0);
		_uvs.push_back(0);

		//uv4
		_uvs.push_back(1);
		_uvs.push_back(1);

		//uv5
		_uvs.push_back(0);
		_uvs.push_back(1);

		//uv6
		_uvs.push_back(0);
		_uvs.push_back(0);

		res->SetUVs(_uvs);

		

		MemoryElement pos_element;
		pos_element.components = 3;
		pos_element.offset = 0;

		MemoryElement uv_element;
		uv_element.components = 2;
		uv_element.offset = 3 * sizeof(float);

		MemoryLayout ml;
		ml.size = 5 * sizeof(float);
		ml.elements.push_back(pos_element);
		ml.elements.push_back(uv_element);

		res->CreateVertexBuffer(RenderType::STATIC, ml);
		return res;
	}


	std::shared_ptr<Mesh> Rectangle2D::Rectangle2D_Build(float w, float h)
	{
		std::shared_ptr<Mesh> res(new Mesh());
		std::vector<float> _vertices;
		std::vector<float> _uvs;

		//vertex1
		_vertices.push_back(w);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex2
		_vertices.push_back(w);
		_vertices.push_back(h);
		_vertices.push_back(0);

		//vertex3
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex4
		_vertices.push_back(w);
		_vertices.push_back(h);
		_vertices.push_back(0);

		//vertex5
		_vertices.push_back(0);
		_vertices.push_back(h);
		_vertices.push_back(0);

		//vertex6
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		res->SetVertices(_vertices);

		//uv1
		_uvs.push_back(1);
		_uvs.push_back(0);

		//uv2
		_uvs.push_back(1);
		_uvs.push_back(1);

		//uv3
		_uvs.push_back(0);
		_uvs.push_back(0);

		//uv4
		_uvs.push_back(1);
		_uvs.push_back(1);

		//uv5
		_uvs.push_back(0);
		_uvs.push_back(1);

		//uv6
		_uvs.push_back(0);
		_uvs.push_back(0);

		res->SetUVs(_uvs);



		MemoryElement pos_element;
		pos_element.components = 3;
		pos_element.offset = 0;

		MemoryElement uv_element;
		uv_element.components = 2;
		uv_element.offset = 3 * sizeof(float);

		MemoryLayout ml;
		ml.size = 5 * sizeof(float);
		ml.elements.push_back(pos_element);
		ml.elements.push_back(uv_element);

		res->CreateVertexBuffer(RenderType::STATIC, ml);
		return res;
	}


	std::shared_ptr<Mesh> Rectangle2D::Rectangle2D_Build(float w, float h, float u, float v)
	{
		std::shared_ptr<Mesh> res(new Mesh());
		std::vector<float> _vertices;
		std::vector<float> _uvs;

		//vertex1
		_vertices.push_back(w);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex2
		_vertices.push_back(w);
		_vertices.push_back(h);
		_vertices.push_back(0);

		//vertex3
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex4
		_vertices.push_back(w);
		_vertices.push_back(h);
		_vertices.push_back(0);

		//vertex5
		_vertices.push_back(0);
		_vertices.push_back(h);
		_vertices.push_back(0);

		//vertex6
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		res->SetVertices(_vertices);

		//uv1
		_uvs.push_back(u);
		_uvs.push_back(0);

		//uv2
		_uvs.push_back(u);
		_uvs.push_back(v);

		//uv3
		_uvs.push_back(0);
		_uvs.push_back(0);

		//uv4
		_uvs.push_back(u);
		_uvs.push_back(v);

		//uv5
		_uvs.push_back(0);
		_uvs.push_back(v);

		//uv6
		_uvs.push_back(0);
		_uvs.push_back(0);

		res->SetUVs(_uvs);



		MemoryElement pos_element;
		pos_element.components = 3;
		pos_element.offset = 0;

		MemoryElement uv_element;
		uv_element.components = 2;
		uv_element.offset = 3 * sizeof(float);

		MemoryLayout ml;
		ml.size = 5 * sizeof(float);
		ml.elements.push_back(pos_element);
		ml.elements.push_back(uv_element);

		res->CreateVertexBuffer(RenderType::STATIC, ml);
		return res;
	}


	std::shared_ptr<Mesh> Rectangle2D::RectangleOutline_Build()
	{
		std::shared_ptr<Mesh> res(new Mesh());
		std::vector<float> _vertices;
		std::vector<float> _uvs;

		//vertex1
		_vertices.push_back(1);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex2
		_vertices.push_back(1);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex3
		_vertices.push_back(1);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex4
		_vertices.push_back(0);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex5
		_vertices.push_back(0);
		_vertices.push_back(1);
		_vertices.push_back(0);

		//vertex6
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex7
		_vertices.push_back(0);
		_vertices.push_back(0);
		_vertices.push_back(0);

		//vertex8
		_vertices.push_back(1);
		_vertices.push_back(0);
		_vertices.push_back(0);

		res->SetVertices(_vertices);

		//uv1
		_uvs.push_back(1);
		_uvs.push_back(0);

		//uv2
		_uvs.push_back(1);
		_uvs.push_back(1);

		//uv3
		_uvs.push_back(0);
		_uvs.push_back(0);

		//uv4
		_uvs.push_back(1);
		_uvs.push_back(1);

		//uv5
		_uvs.push_back(0);
		_uvs.push_back(1);

		//uv6
		_uvs.push_back(0);
		_uvs.push_back(0);

		//uv7
		_uvs.push_back(0);
		_uvs.push_back(1);

		//uv8
		_uvs.push_back(0);
		_uvs.push_back(0);

		res->SetUVs(_uvs);



		MemoryElement pos_element;
		pos_element.components = 3;
		pos_element.offset = 0;

		MemoryElement uv_element;
		uv_element.components = 2;
		uv_element.offset = 3 * sizeof(float);

		MemoryLayout ml;
		ml.size = 5 * sizeof(float);
		ml.elements.push_back(pos_element);
		ml.elements.push_back(uv_element);

		res->CreateVertexBuffer(RenderType::STATIC, ml);
		return res;
	}
}