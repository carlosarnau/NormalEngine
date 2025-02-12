#pragma once

#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include "../Inspector/ComponentInspector.h"


struct HierarchyWindow : public UI_Item {
	HierarchyWindow() : UI_Item("Navigation") {
		rm_menu.flags = ImGuiHoveredFlags_ChildWindows || ImGuiHoveredFlags_RootWindow;
		rm_menu.container_name = name.c_str();
	};
	~HierarchyWindow() {};

	void Start();
	void Update();

	RMPopupMenu rm_menu;
	void UpdateRMMenu();

	ComponentInspector* inspector = nullptr;

	std::vector<uint64_t> selected;
	bool IsSelected(uint64_t eid) { for (auto v : selected) if (eid == v) return true; return false; }
	void UpdateEntry(Entity* entity);
};