#include "pch.h"
#include "OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>

Hazel::OrthographicCamera::OrthographicCamera(const OrthographicProps& props)
	: Camera(props), m_RotationZ(0.0f)
{
	this->RecalculateMatrices(RecalculateReasonE::ALL);
}





Hazel::OrthographicCamera::~OrthographicCamera()
{
}





void Hazel::OrthographicCamera::RecalculateMatrices(RecalculateReasonE reason)
{
	//Recalculate Projection Matrix.
	if (reason == RecalculateReasonE::PROPS_CHANGED || reason == RecalculateReasonE::ALL)
	{
		
		m_proj = glm::ortho(m_props.ortho_props.Left,
			m_props.ortho_props.Right,
			m_props.ortho_props.Bottom,
			m_props.ortho_props.Top,
			m_props.ortho_props.Near,
			m_props.ortho_props.Far);
			
	}


	//Recalculate View Matrix.
	if (reason == RecalculateReasonE::POSITION_CHANGED || reason == RecalculateReasonE::ALL)
	{
		
		m_view = glm::inverse( 
			glm::translate(glm::mat4(1.0f), m_pos) * 
			glm::rotate(glm::mat4(1.0f), glm::radians(m_RotationZ), glm::vec3(0.0f, 0.0f, 1.0f)) 
		);
		
		
	}
}




void Hazel::OrthographicCamera::MoveImpl(MovementE movement, const Timestep& deltaTime)
{
	switch (movement)
	{
		case Hazel::Camera::MovementE::FORWARD:
			m_pos.y += m_movementSpeed * deltaTime.GetTimeSeconds();
			break;
		case Hazel::Camera::MovementE::BACKWARD:
			m_pos.y -= m_movementSpeed * deltaTime.GetTimeSeconds();
			break;
		case Hazel::Camera::MovementE::LEFT:
			m_pos.x -= m_movementSpeed * deltaTime.GetTimeSeconds();
			break;
		case Hazel::Camera::MovementE::RIGHT:
			m_pos.x += m_movementSpeed * deltaTime.GetTimeSeconds();
			break;
		case Hazel::Camera::MovementE::ROLL_LEFT:
			m_RotationZ += m_rotationSpeed * deltaTime.GetTimeSeconds();
			break;
		case Hazel::Camera::MovementE::ROLL_RIGHT:
			m_RotationZ -= m_rotationSpeed * deltaTime.GetTimeSeconds();
			break;
		case Hazel::Camera::MovementE::ROTATE_LEFT:
			break;
		case Hazel::Camera::MovementE::ROTATE_RIGHT:
			break;
		case Hazel::Camera::MovementE::LOOK_UP:
			break;
		case Hazel::Camera::MovementE::LOOK_DOWN:
			break;
		default:
			break;
	}

}
