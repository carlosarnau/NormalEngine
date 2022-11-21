#pragma once

#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include <src/modules/ECS/ModuleECS.h>

struct CameraWindow : UI_Item {
	std::string entity_id_str;
	Entity* entity = nullptr;

	CameraWindow() : UI_Item("Camera") {};

	RMPopupMenu rm_menu;

	void UpdateRMMenu();
	void Update();
};