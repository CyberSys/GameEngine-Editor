#include "renderer\Transform.h"

using namespace glm;

namespace Renderer
{
	Transform::Transform() : _position(vec3{ 0.0f }), _rotationangle(vec3{ 0.0f }), _scale(vec3{ 1 })
	{
	}

	Transform::Transform(vec3 position, vec3 rotangle, vec3 scale)
	{
		_position = position;
		_rotationangle = rotangle;
		_scale = scale;
	}

	Transform::~Transform()
	{
	}

	void Transform::SetPosition(vec3& position)
	{
		_position = position;
	}

	vec3 Transform::GetPosition()
	{
		return _position;
	}

	void Transform::SetRotationAngle(vec3& rotation)
	{
		_rotationangle = rotation;
	}

	vec3 Transform::GetRotationAngle()
	{
		return _rotationangle;
	}

	void Transform::SetScale(vec3& scale)
	{
		_scale = scale;
	}

	vec3 Transform::GetScale()
	{
		return _scale;
	}
	glm::mat4 Transform::GetTransformMat()
	{
		return MVP;
	}

	glm::mat4 Transform::UpdateModelMat()
	{
		glm::quat rotQuaternion(_rotationangle);
		glm::mat4 RotationMatrix = glm::toMat4(rotQuaternion);

		glm::mat4 model_mat = glm::translate(_position) *glm::scale(_scale);

		return model_mat;
	}

	void Transform::SetTransformMatrix(glm::mat4 & transform)
	{
		MVP = transform * UpdateModelMat();
	}


	//glm::mat4 Transform::GetMVP()
	//{
	//	glm::mat4 m =  glm::translate(_position) * glm::scale(_scale);
	//	glm::mat4 V  = glm::ortho(0.0f, float(400), float(600), 0.0f, -1.0f, 1.0f);
	//	MVP = V * m;
	//	return MVP;
	//}
}
