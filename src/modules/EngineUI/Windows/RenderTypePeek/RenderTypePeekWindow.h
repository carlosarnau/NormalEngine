#pragma once
#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include "src/modules/EngineUI/Windows/Transform/TransformWindow.h"
#include <filesystem>

#define LIMIT_OF_LOGS 10000

const std::filesystem::path g_AssetPath = "Assets";

class RenderPeekWindow : UI_Item {
public:
	RenderPeekWindow() : UI_Item("Assets") { m_CurrentDirectory = g_AssetPath ;};

	void Start();
	void Update();
	void AddLogFromModuleUi(const char* str);
	bool AddLogsInConsole(const char* logStr);
	void ClearLogs();

private:
	std::filesystem::path m_CurrentDirectory;
	SDL_Surface* dicons = SDL_LoadBMP("Assets/DirectoryIcon.bmp");
	std::vector<char*> logs;
};