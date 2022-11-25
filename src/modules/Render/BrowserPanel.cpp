#include "BrowserPanel.h"
#include <src/Application.h>
#include <filesystem>

namespace NormalEngine
{
	constexpr char* s_AssetDirectory = "Assets";

	void BrowserPanel::OnImGuiRender()
	{
		ImGui::Begin("Scene Hierarchy");
		for (auto& p : std::filesystem::directory_iterator(s_AssetDirectory))
		{
			std::string path = p.path().string();
			ImGui::Text("%s", path.c_str());
		}
		ImGui::End();
	}
}