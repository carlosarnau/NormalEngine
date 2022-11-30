#include "RenderTypePeekWindow.h"
#include <src/Application.h>
#include <glew/include/GL/glew.h>

void RenderPeekWindow::Start()
{
}

void RenderPeekWindow::Update()
{
	ImGui::Begin(name.c_str(), &active, ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar);

	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("Game Assets");
	ImGui::SetCursorPos(ImVec2(15, 60));
	ImGui::Separator();

	int win_w, win_h;
	SDL_GetWindowSize(App->window->window, &win_w, &win_h);

	// Here starts the file system for Textures
	constexpr char* s1_AssetDirectory = "Assets";
	int i = 78;
	for (auto& p : std::filesystem::directory_iterator(s1_AssetDirectory))
	{
		std::string path = p.path().string();
		ImGui::SetCursorPos(ImVec2(15, i));
		ImGui::Text("%s", path.c_str());
		i = i + 25;
	}

	ImGui::End();
}