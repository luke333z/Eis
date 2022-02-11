#pragma once

#include "Eis/Renderer/Objects/Buffer.h"

namespace Eis
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		uint32_t m_RendererId;
		BufferLayout m_Layout;

	public:
		OpenGLVertexBuffer(float* verticies, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		uint32_t m_RendererId;
		uint32_t m_Count;

	public:
		OpenGLIndexBuffer(uint32_t* indicies, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual uint32_t GetCount() const override
		{
			return m_Count;
		}
	};
}