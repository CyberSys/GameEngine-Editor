#include "Camera2D.h"

namespace Renderer
{
	Camera2D::Camera2D(float window_width, float window_height)
	{
		projection_mat = glm::ortho(0.0f, window_width, window_height, 0.0f, -1.0f, 1.0f);
		view_mat = glm::mat4(1.0f);
	}

	Camera2D::Camera2D(float right, float left, float top, float down)
	{
		projection_mat = glm::ortho(left, right, down, top, -1.0f, 1.0f);
		view_mat = glm::mat4(1.0f);
	}

	Camera2D::~Camera2D(){}

	glm::mat4 Camera2D::GetViewProjectionMat()
	{
		vp = projection_mat * view_mat;
		return vp;
	}
	void Camera2D::UpdateViewPort(float window_width, float window_height)
	{
		projection_mat = glm::ortho(0.0f, window_width, window_height, 0.0f, -1.0f, 1.0f);
	}

	void Camera2D::UpdateViewPort(float left, float right, float bottom, float top)
	{
		projection_mat = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
	}
}

