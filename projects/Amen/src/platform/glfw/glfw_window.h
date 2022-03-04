#pragma once
#include <core/window.h>



struct GLFWwindow;



namespace Amen
{
	struct WindowData
	{
		std::string m_title;
		int m_width;
		int m_height;
		bool m_vSynced;
		WindowEventCallback m_eventCallback;

		WindowData()
			: m_title("No Title"), m_width(0), m_height(0), m_vSynced(0), m_eventCallback(nullptr)
		{
		}

		WindowData(const std::string& title, int width, int height, bool vsync)
			: m_title(title), m_width(width), m_height(height), m_vSynced(vsync), m_eventCallback(nullptr)
		{
		}
	};

	class GLFW_Window : public Window
	{
		public:
		GLFW_Window(const WindowProps& props);
		~GLFW_Window();

		void Update() override;

		void SetTitle(const std::string& title) override;
		void SetWidth(int width) override;
		void SetHeight(int height) override;
		void SetSize(int width, int height) override;
		void SetVSync(bool enabled) override;

		inline void SetEventCallback(WindowEventCallback callback) override { m_data.m_eventCallback = callback; };

		inline int GetWidth() const override { return m_data.m_width; }
		inline int GetHeight() const override { return m_data.m_height; }
		inline const std::string& GetTitle() const override { return m_data.m_title; };
		inline bool IsVSynced() const override { return m_data.m_vSynced; }


		private:
		void InitilizeCallbacks() const;

		private:
		WindowData m_data;
		GLFWwindow* m_window;

	};
}
