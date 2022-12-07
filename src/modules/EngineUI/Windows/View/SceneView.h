#pragma once
#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include <src/modules/Render/RendererTypes.h>

class SceneView : UI_Item {
	GPUFBO fb;
public:
	SceneView() : UI_Item("Scene") {};
	void Start();
	void Update();

	void CleanUp();
	
	enum View
	{
		Scene,
		Game,
	};
	View engineView = Scene;
};

