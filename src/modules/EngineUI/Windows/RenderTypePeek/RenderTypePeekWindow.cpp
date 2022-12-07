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
	if (m_CurrentDirectory != std::filesystem::path(g_AssetPath))
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

		int i = 0;

		for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
		{
			ImGui::PushID(i++);

			const auto& path = directoryEntry.path();
			auto relativePath = std::filesystem::relative(path, g_AssetPath);
			std::string filenameString = relativePath.filename().string();

			// Charging icons for folder and files
			folder = SDL_LoadBMP("Resources/Navigator/Folder.bmp");
			file = SDL_LoadBMP("Resources/Navigator/File.bmp");

			if (directoryEntry.is_directory())
			{
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.50f, 0.10f, 0.50f, 1.0f));		// As not working we used colors instead
			}
			else
			{
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.83f, 0.155f, 0.245f, 1.0f));	// As not working we used colors instead
			}

			// ImGui::ImageButton((ImTextureID)folder, {thumbnailSize, thumbnailSize}, {0,1}, {1,0});	// Not working
			ImGui::Button(filenameString.c_str(), {thumbnailSize, thumbnailSize});
			ImGui::PopStyleColor();

			//	Drag and drop
			if (ImGui::BeginDragDropSource())
			{
				const wchar_t* itemPath = relativePath.c_str();
				ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (wcslen(itemPath) + 1) * sizeof(wchar_t));
				ImGui::EndDragDropSource();
			}

			//	Accessing to folders and files
			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
			{
				if (directoryEntry.is_directory())
					m_CurrentDirectory /= path.filename();
			}
			// ImGui::Text(filenameString.c_str());	// Not needed if not working

			ImGui::NextColumn();

			ImGui::PopID();
		}
	}

	// TODO: status bar
	ImGui::End();
}