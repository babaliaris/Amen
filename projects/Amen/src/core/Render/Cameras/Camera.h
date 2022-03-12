#pragma once
#include <glm/glm.hpp>
#include <core/Render/Shader.h>
#include <core/core.h>
#include <core/Timestep.h>

namespace Hazel
{
	class AMEN_API Camera
	{
		friend class Renderer;

		public:

			enum class MovementE
			{
				FORWARD, BACKWARD, LEFT, RIGHT,		//Fixed Movement.
				ROLL_LEFT, ROLL_RIGHT,				//Roll along the Z axis.
				ROTATE_LEFT, ROTATE_RIGHT,			//Rotate along Y axis.
				LOOK_UP, LOOK_DOWN					//Rotate along X axis.
			};

			struct OrthographicProps
			{
				float Left, Right, Bottom, Top, Near, Far;

				OrthographicProps()
					: Left(0.0f), Right(0.0f), Bottom(0.0f), Top(0.0f), Near(0.1f), Far(100.0f)
				{}

				OrthographicProps(float left, float right, float bottom, float top, float near_ = 0.1f, float far_ = 100.0f)
					: Left(left), Right(right), Bottom(bottom), Top(top), Near(near_), Far(far_)
				{}
			};

			struct PerspectiveProps
			{
				float Fov, Aspect_Ration, Near, Far;

				PerspectiveProps()
					: Fov(45.0f), Aspect_Ration(0.0f), Near(0.1f), Far(100.0f)
				{}

				PerspectiveProps(float fov, float aspect_ration, float near_ = 0.1f, float far_ = 100.0f)
					: Fov(fov), Aspect_Ration(aspect_ration), Near(near_), Far(far_)
				{}
			};

			union CameraProps
			{
				OrthographicProps	ortho_props;
				PerspectiveProps	pers_props;

				CameraProps(OrthographicProps props)
					: ortho_props(props)
				{}

				CameraProps(PerspectiveProps props)
					: pers_props(props)
				{}
			};



		protected:
			enum class RecalculateReasonE
			{
				NONE,
				ALL,
				POSITION_CHANGED,
				PROPS_CHANGED
			};




		public:
			virtual ~Camera(){}

			inline void SetPos(const glm::vec3& pos) 
			{ 
				m_pos = pos; 
				m_reason = RecalculateReasonE::POSITION_CHANGED;
				RecalculateMatrices(RecalculateReasonE::POSITION_CHANGED); 
			}

			inline void SetProps(const CameraProps& props) 
			{ 
				m_props = props;
				m_reason = RecalculateReasonE::PROPS_CHANGED;
				RecalculateMatrices(RecalculateReasonE::PROPS_CHANGED); 
			}

			inline void Move(MovementE movement, const Timestep& deltaTime)
			{
				this->MoveImpl(movement, deltaTime);
				m_reason = RecalculateReasonE::POSITION_CHANGED;
				RecalculateMatrices(RecalculateReasonE::POSITION_CHANGED);
			}

			inline void SetMovementSpeed(float speed) { m_movementSpeed = speed; }
			inline void SetRotationSpeed(float speed) { m_rotationSpeed = speed; }

			inline const glm::vec3& GetPos() const { return m_pos; }
			inline const glm::mat4& GetView() const { return m_view; }
			inline const glm::mat4& GetProj() const { return m_proj; }
			inline const CameraProps& GetProps() const { return m_props; }
			inline RecalculateReasonE GetReason() const { return m_reason; }


		protected:
			Camera(CameraProps props)
				: m_pos(0.0f), m_view(1.0f), m_proj(1.0f), m_props(props), m_reason(RecalculateReasonE::ALL)
			{}

			virtual void RecalculateMatrices(RecalculateReasonE reason) = 0;

			virtual void MoveImpl(MovementE movement, const Timestep& deltaTime) {}


		protected:
			glm::vec3 m_pos;
			glm::mat4 m_view;
			glm::mat4 m_proj;
			CameraProps m_props;
			RecalculateReasonE m_reason;
			float m_movementSpeed = 10.0f;
			float m_rotationSpeed = 10.0f;
	};
}
