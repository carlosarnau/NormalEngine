#pragma once

#include <src/helpers/Globals.h>
#include <src/helpers/Timer.h>
#include <src/modules/Module.h>
#include <src/modules/ModuleWindow.h>
#include <src/modules/ModuleInput.h>
#include <src/modules/Render/ModuleRenderer3D.h>
#include <src/modules/ModuleCamera3D.h>
#include <src/modules/EngineUI/ModuleEngineUI.h>
#include <src/modules/EventSystem/ModuleEventSystem.h>
#include <src/modules/FileSystem/ModuleFS.h>

#include<list>
#include<vector>


class Application
{
public:
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRenderer3D* renderer3D;
	ModuleCamera3D* camera;
	ModuleEngineUI* engine_ui = &e_engine_ui;
	ModuleEventSystem* events;
	ModuleFS* fs;

private:
	Timer	ms_timer;
	float	dt;
	std::list<Module*> list_modules;

public:

	Application();
	~Application();

	bool Init();
	void SendEvents(std::vector<std::shared_ptr<Event>>& evt_vec);
	update_status Update();
	bool CleanUp();

private:

	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();
};

extern Application* App;