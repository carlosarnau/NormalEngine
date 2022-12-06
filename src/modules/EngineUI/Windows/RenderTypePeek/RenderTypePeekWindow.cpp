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
	if (m_CurrentDirectory != std::filesystem::path(s_AssetPath))
	{
		ImGui::SetCursorPos(ImVec2(95, 30));
		if (ImGui::Button("<--"))
		{
			m_CurrentDirectory = m_CurrentDirectory.parent_path();
		}
	}

	ImGui::SetCursorPos(ImVec2(15, 70));
	{
		static float padding = 15.0f;
		static float thumbnailSize = 75.0f;
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

			//	Charging folder and file icon
			icon = SDL_LoadBMP("Assets/DirectoryIcon.bmp");

			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
			ImGui::ImageButton((ImTextureID)icon, {thumbnailSize, thumbnailSize}, {0,1}, {1,0});
			ImGui::PopStyleColor();

			//	Drag and drop
			if (ImGui::BeginDragDropSource())
			{
				const wchar_t* itemPath = relativePath.c_str();
				ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, wcslen(itemPath) * sizeof(wchar_t), ImGuiCond_Once);
				ImGui::EndDragDropSource();
			}

			//	Accessing to folders and files
			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
			{
				if (directoryEntry.is_directory())
					m_CurrentDirectory /= path.filename();
			}
			ImGui::Text(filenameString.c_str());
			ImGui::NextColumn();
		}
	}

	// TODO: status bar
	ImGui::End();
}