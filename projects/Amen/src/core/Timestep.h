#pragma once

namespace Hazel
{
	class Timestep
	{
		public:
			Timestep(double time)
				: m_time(time)
			{}

			operator float() const { return (float)m_time; }
			operator double() const { return m_time; }

			inline double GetTimeSeconds() const { return m_time; }
			inline double GetTimeMilli() const { return m_time * 1000.0f; }

		private:
			double m_time;

	};
}