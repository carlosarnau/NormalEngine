#pragma once

#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"

class RenderPeekWindow : UI_Item {
public:
	RenderPeekWindow() : UI_Item("Assets") {};

	void Start();
	void Update();

private:
	int t_w = 500;
};