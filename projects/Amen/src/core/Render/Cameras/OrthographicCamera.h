#pragma once
#include <core/Render/Cameras/Camera.h>
#include <core/core.h>

namespace Amen
{
	class AMEN_API OrthographicCamera: public Camera
	{
		public:
			OrthographicCamera(const OrthographicProps& props);
			~OrthographicCamera();

			inline void SetRotation(float angle) { m_RotationZ = angle; }

		protected:
			virtual void RecalculateMatrices(RecalculateReasonE reason) override;
			virtual void MoveImpl(MovementE movement, const Timestep& deltaTime) override;

		private:
			float m_RotationZ;

	};
}
