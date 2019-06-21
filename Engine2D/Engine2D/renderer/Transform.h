#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>
#include <gtc\quaternion.hpp>
#include <gtx\quaternion.hpp>

namespace Renderer
{
	class Transform
	{
	public:
		Transform();
		Transform(glm::vec3 position, glm::vec3 rotangle, glm::vec3 scale);
		~Transform();

		void SetPosition(glm::vec3& position);
		glm::vec3 GetPosition();

		void SetRotationAngle(glm::vec3& rotation);
		glm::vec3 GetRotationAngle();

		void SetScale(glm::vec3& scale);
		glm::vec3 GetScale();

		glm::mat4 GetTransformMat();

		glm::mat4 UpdateModelMat();

		void SetTransformMatrix(glm::mat4& transform);

	private:
		glm::vec3 _position;
		glm::vec3 _rotationangle;
		glm::vec3 _scale;
		glm::mat4 MVP;
	};
}
