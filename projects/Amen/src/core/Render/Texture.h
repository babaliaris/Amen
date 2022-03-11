#pragma once
#include <core/core.h>

namespace Amen
{
	class AMEN_API Texture
	{
		public:
			inline uint32_t GetWidth() const { return m_width; }
			inline uint32_t GetHeight() const { return m_height; }
			inline const std::string& GetPath() const { return m_path; }

		public:
			virtual ~Texture(){}
			virtual void Bind(unsigned int slot = 0) = 0;
			virtual void UnBind() = 0;

		protected:
			Texture(const std::string& path);

		protected:
			uint32_t m_width;
			uint32_t m_height;
			std::string m_path;

	};



	class AMEN_API Texture2D: public Texture
	{
		public:
			static Ref<Texture2D> Create(const std::string& path);

		public:
			virtual ~Texture2D(){}

		protected:
			Texture2D(const std::string& path);
	};
}
