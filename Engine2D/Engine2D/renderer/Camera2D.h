#pragma once

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>

namespace Renderer
{
	class Camera2D
	{
	public:
		Camera2D(float window_width, float window_height);
		Camera2D(float right, float left, float top, float down);
		~Camera2D();
		
		glm::mat4 GetViewProjectionMat();
		void UpdateViewPort(float window_width, float window_height);
		void UpdateViewPort(float left, float right, float bottom, float top);

	private:
		glm::mat4 vp;
		glm::mat4 view_mat;
		glm::mat4 projection_mat;
	};
}