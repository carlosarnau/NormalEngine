#include "RenderTypePeekWindow.h"
#include <src/Application.h>
#include <glew/include/GL/glew.h>

void RenderPeekWindow::Start()
{
}

void RenderPeekWindow::Update()
{
	// Console
	ImGui::Begin("Console", &active);

	ImGui::End();

	// Assets navigator
	ImGui::Begin(name.c_str(), &active);

	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("Game Assets");
	ImGui::SetCursorPos(ImVec2(15, 60));
	ImGui::Separator();

	// Here starts the file system for Textures
	int i = 78;

	if (m_CurrentDirectory != std::filesystem::path(s_AssetPath))
	{
		if (ImGui::Button("<-"))
		{
			m_CurrentDirectory = m_CurrentDirectory.parent_path();
		}
	}

	static float padding = 16.0f;
	static float thumbnailSize = 128.0f;
	float cellSize = thumbnailSize + padding;

	float panelWidth = ImGui::GetContentRegionAvail().x;
	int columnCount = (int)(panelWidth / cellSize);
	if (columnCount < 1)
		columnCount = 1;

	ImGui::Columns(columnCount, 0, false);

	for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
	{
		const auto& path = directoryEntry.path();
		auto relativePath = std::filesystem::relative(path, s_AssetPath);
		std::string filenameString = relativePath.filename().string();
	
		icon = directoryEntry.is_directory() ? SDL_LoadBMP("Assets/Navigator/DirectoryIcon.bmp") : SDL_LoadBMP("Assets/Navigator/FileIcon.bmp");
		
		ImGui::ImageButton(icon, { thumbnailSize, thumbnailSize }, {0,1}, {1,0});
		if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
		{
			if (directoryEntry.is_directory())
				m_CurrentDirectory /= path.filename();
		}
		ImGui::Text(filenameString.c_str());
		ImGui::NextColumn();
	}

	ImGui::Columns(1);
	ImGui::SliderFloat("Thumbnail Size", &thumbnailSize, 16, 512);
	ImGui::SliderFloat("Padding", &padding, 0, 32);
	// TODO: status bar
	ImGui::End();
}