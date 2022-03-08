#include "pch.h"
#include "ImGuiGLFWLayer.h"
#include <imgui.h>
#include <core/logger.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>




Amen::ImGuiGLFWLayer::ImGuiGLFWLayer()
{
}





Amen::ImGuiGLFWLayer::~ImGuiGLFWLayer()
{
	AMEN_INFO("Calling ~ImGuiGLFWLayer()");
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}





void Amen::ImGuiGLFWLayer::OnAttach()
{
	//Check and create ImGui context.
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	//Set ImGui flags.
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	//Set ImGui theme.
	ImGui::StyleColorsDark();

	// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	//Initialize opengl and glfw implementations.
	ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)m_window.GetNativeWindow(), false);
	ImGui_ImplOpenGL3_Init("#version 330");
}





void Amen::ImGuiGLFWLayer::Begin()
{
	//Start the frames.
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}





void Amen::ImGuiGLFWLayer::End()
{
	//Render.
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// Update and Render additional Platform Windows
	// (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
	//  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}





void Amen::ImGuiGLFWLayer::OnImGuiRender()
{
	if (m_showDemoWindow)
		ImGui::ShowDemoWindow(&m_showDemoWindow);
}





void Amen::ImGuiGLFWLayer::OnEvent(Event& e)
{
}
