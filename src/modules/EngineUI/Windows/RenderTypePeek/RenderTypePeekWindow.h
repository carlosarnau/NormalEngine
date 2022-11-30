#pragma once

#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include "src/modules/EngineUI/Windows/Transform/TransformWindow.h"
#include <filesystem>


class RenderPeekWindow : UI_Item {
public:
	RenderPeekWindow() : UI_Item("Assets") {};

	void Start();
	void Update();

private:
	std::filesystem::path m_CurrentDirectory;
};