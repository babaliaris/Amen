#pragma once
#include <iostream>
#include <vector>
#include <core/core.h>

namespace Hazel
{
	enum class ShaderType
	{
		NONE,
		BOOL1, BOOL2, BOOL3, BOOL4,
		INT1, INT2, INT3, INT4,
		FLOAT1, FLOAT2, FLOAT3, FLOAT4,
		MAT3, MAT4
	};

	inline unsigned int GetShaderTypeCount(ShaderType type)
	{
		switch (type)
		{
			case Hazel::ShaderType::NONE:	return 0;
			case Hazel::ShaderType::BOOL1:	return 1;
			case Hazel::ShaderType::BOOL2:	return 2;
			case Hazel::ShaderType::BOOL3:	return 3;
			case Hazel::ShaderType::BOOL4:	return 4;
			case Hazel::ShaderType::INT1:	return 1;
			case Hazel::ShaderType::INT2:	return 2;
			case Hazel::ShaderType::INT3:	return 3;
			case Hazel::ShaderType::INT4:	return 4;
			case Hazel::ShaderType::FLOAT1:	return 1;
			case Hazel::ShaderType::FLOAT2:	return 2;
			case Hazel::ShaderType::FLOAT3:	return 3;
			case Hazel::ShaderType::FLOAT4:	return 4;
			case Hazel::ShaderType::MAT3:	return 3 * 3;
			case Hazel::ShaderType::MAT4:	return 4 * 4;
			default: return 0;
		}
	}

	inline unsigned int GetShaderTypeSize(ShaderType type)
	{
		switch (type)
		{
			case Hazel::ShaderType::NONE:	return 0;
			case Hazel::ShaderType::BOOL1:	return 1 * 1;
			case Hazel::ShaderType::BOOL2:	return 1 * 2;
			case Hazel::ShaderType::BOOL3:	return 1 * 3;
			case Hazel::ShaderType::BOOL4:	return 1 * 4;
			case Hazel::ShaderType::INT1:	return 4 * 1;
			case Hazel::ShaderType::INT2:	return 4 * 2;
			case Hazel::ShaderType::INT3:	return 4 * 3;
			case Hazel::ShaderType::INT4:	return 4 * 4;
			case Hazel::ShaderType::FLOAT1:	return 4 * 1;
			case Hazel::ShaderType::FLOAT2:	return 4 * 2;
			case Hazel::ShaderType::FLOAT3:	return 4 * 3;
			case Hazel::ShaderType::FLOAT4:	return 4 * 4;
			case Hazel::ShaderType::MAT3:	return 3 * 3 * 4;
			case Hazel::ShaderType::MAT4:	return 4 * 4 * 4;
			default: return 0;
		}
	}



	struct LayoutElement
	{
		std::string	Name;
		ShaderType	Type;
		bool Normalized;

		LayoutElement()
			: Name(""), Type(ShaderType::NONE), Normalized(false)
		{}

		LayoutElement(const std::string& name, ShaderType type, bool normalized = false)
			: Name(name), Type(type), Normalized(normalized)
		{}
	};



	class BufferLayout
	{
		public:
			BufferLayout(){}

			BufferLayout(std::initializer_list<LayoutElement> elements)
			{
				m_elements = std::vector<LayoutElement>(elements);
			}

			inline const std::vector<LayoutElement>& GetElements() const { return m_elements; }

			inline std::vector<LayoutElement>::iterator begin() { return m_elements.begin(); }
			inline std::vector<LayoutElement>::iterator end() { return m_elements.end(); }

			inline std::vector<LayoutElement>::const_iterator begin() const { return m_elements.begin(); }
			inline std::vector<LayoutElement>::const_iterator end() const { return m_elements.end(); }

		private:
			std::vector<LayoutElement> m_elements;
	};



	class AMEN_API VertexBuffer
	{
		public:

			static Ref<VertexBuffer> Create(const float *data, unsigned int size);

			void SetLayout(const BufferLayout& layout);

			inline const BufferLayout& GetLayout() const { return m_layout; }

			inline unsigned int GetStride() const { return m_stride; }

		public:
			virtual ~VertexBuffer(){}
			virtual void Bind() = 0;
			virtual void UnBind() = 0;

		protected:
			VertexBuffer(){}

		protected:
			BufferLayout m_layout;
			unsigned int m_stride = 0;
	};



	class AMEN_API IndexBuffer
	{
		public:
			static Ref<IndexBuffer> Create(unsigned int *data, unsigned int count);

			inline unsigned int GetCount() const { return m_count; }

		protected:
			IndexBuffer(unsigned int count);

		public:
			virtual ~IndexBuffer(){}
			virtual void Bind() = 0;
			virtual void UnBind() = 0;

		private:
			unsigned int m_count;
	};



	class AMEN_API ArrayBuffer
	{
		public:
			ArrayBuffer(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer);
			static Ref<ArrayBuffer> Create(Ref<VertexBuffer> vertexBuffer, Ref<IndexBuffer> indexBuffer);

			inline Ref<VertexBuffer> GetVertexBuffer() const { return m_vertexBuffer; }
			inline Ref<IndexBuffer> GetIndexBuffer() const { return m_indexBuffer; }

		public:
			virtual ~ArrayBuffer(){}
			virtual void Bind() = 0;
			virtual void UnBind() = 0;

		protected:
			Ref<VertexBuffer> m_vertexBuffer;
			Ref<IndexBuffer> m_indexBuffer;
	};
}
