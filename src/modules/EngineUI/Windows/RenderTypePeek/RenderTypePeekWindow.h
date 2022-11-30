#pragma once
#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include "src/modules/EngineUI/Windows/Transform/TransformWindow.h"
#include <filesystem>

constexpr char* s_AssetPath = "Assets";

class RenderPeekWindow : UI_Item {
public:
	RenderPeekWindow() : UI_Item("Assets") {
		m_CurrentDirectory = s_AssetPath;
	};

	void Start();
	void Update();

private:
	std::filesystem::path m_CurrentDirectory;
};