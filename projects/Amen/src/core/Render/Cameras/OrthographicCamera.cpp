#include "pch.h"
#include "OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>

Amen::OrthographicCamera::OrthographicCamera(const OrthographicProps& props)
	: Camera(props), m_RotationZ(0.0f)
{
	this->RecalculateMatrices(RecalculateReasonE::ALL);
}





Amen::OrthographicCamera::~OrthographicCamera()
{
}





void Amen::OrthographicCamera::RecalculateMatrices(RecalculateReasonE reason)
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




void Amen::OrthographicCamera::MoveImpl(MovementE movement)
{
	switch (movement)
	{
		case Amen::Camera::MovementE::FORWARD:
			m_pos.y += m_movementSpeed;
			break;
		case Amen::Camera::MovementE::BACKWARD:
			m_pos.y -= m_movementSpeed;
			break;
		case Amen::Camera::MovementE::LEFT:
			m_pos.x -= m_movementSpeed;
			break;
		case Amen::Camera::MovementE::RIGHT:
			m_pos.x += m_movementSpeed;
			break;
		case Amen::Camera::MovementE::ROLL_LEFT:
			m_RotationZ += m_rotationSpeed;
			break;
		case Amen::Camera::MovementE::ROLL_RIGHT:
			m_RotationZ -= m_rotationSpeed;
			break;
		case Amen::Camera::MovementE::ROTATE_LEFT:
			break;
		case Amen::Camera::MovementE::ROTATE_RIGHT:
			break;
		case Amen::Camera::MovementE::LOOK_UP:
			break;
		case Amen::Camera::MovementE::LOOK_DOWN:
			break;
		default:
			break;
	}

}
