#include "RenderTypePeekWindow.h"
#include <src/Application.h>
#include <glew/include/GL/glew.h>

void RenderPeekWindow::Start()
{
}

void RenderPeekWindow::Update()
{
	ImGui::Begin(name.c_str(), &active);

	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("Render attributes:");
	ImGui::SetCursorPos(ImVec2(15, 57));
	ImGui::Separator();

	int win_w, win_h;
	SDL_GetWindowSize(App->window->window, &win_w, &win_h);

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, win_w / 2);

	ImGui::SetCursorPos(ImVec2(15, 75));
	ImGui::Text("Textures:");

	// Here starts the file system for Textures
	constexpr char* s1_AssetDirectory = "Assets/Textures";
	int i = 100;
	for (auto& p : std::filesystem::directory_iterator(s1_AssetDirectory))
	{
		std::string path = p.path().string();
		ImGui::SetCursorPos(ImVec2(15, i));
		ImGui::Text("%s", path.c_str());
		i = i + 25;
	}

	ImGui::NextColumn();

	ImGui::SetCursorPos(ImVec2( (win_w / 2) + 15, 75));
	ImGui::Text("Meshes:");
	// Here starts the file system for Textures
	constexpr char* s2_AssetDirectory = "Assets/Meshes";
	int j = 100;
	for (auto& p : std::filesystem::directory_iterator(s2_AssetDirectory))
	{
		std::string path = p.path().string();
		ImGui::SetCursorPos(ImVec2((win_w / 2) + 15, j));
		ImGui::Text("%s", path.c_str());
		j = j+25;
	}

	ImGui::End();
}