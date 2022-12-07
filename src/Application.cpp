#include <src/Application.h>

Application::Application()
{
	InitTimer();
	CalibrateTimer();

	// The order of calls is very important!
	// Modules will Init() Start() and Update in this order
	// They will CleanUp() in reverse order
	window = new ModuleWindow();
	input = new ModuleInput();
	renderer3D = new ModuleRenderer3D();
	camera = new ModuleCamera3D();
	fs = new ModuleFS();
	ecs = new ModuleECS();
	engine_ui = new ModuleEngineUI();

	// Main Modules
	AddModule(window);
	AddModule(camera);
	AddModule(input);
	
	// Scenes
	AddModule(ecs);

	// Renderer last!
	AddModule(renderer3D);

	// UI Even further last!
	AddModule(engine_ui);
	AddModule(fs);
}

Application::~Application()
{		
	std::list<Module*>::iterator item = list_modules.end(); 

	do {
		--item;
		if (*item == nullptr || (*item)->static_m)
			continue;
		delete* item;
		*item = nullptr;
	} while (item != list_modules.begin());

	list_modules.clear();
}

bool Application::Init()
{
	bool ret = true;

	// Call Init() in all modules
	//std::list<Module*>::iterator item = list_modules.begin();

	for (Module* item : list_modules) {
		item->Init();
	}

	// After all Init calls we call Start() in all modules
	PLOG("Application Start --------------");
	
	for (Module* item : list_modules) {
		item->Start();
	}
	
	ms_timer.Start();
	return ret;
}

// ---------------------------------------------
void Application::PrepareUpdate()
{
	dt = (float)ms_timer.ReadMilliSec() / 1000.0f;
	PLOG("%f", dt);
	ms_timer.Start();
}

// ---------------------------------------------
void Application::FinishUpdate()
{
	//Do here object move?

}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;
	PrepareUpdate();
	
	for (Module* item : list_modules) {
		if (ret != UPDATE_CONTINUE) break;
		ret = item->PreUpdate(dt);
	}

	for (Module* item : list_modules) {
		if (ret != UPDATE_CONTINUE) break;
		ret = item->Update(dt);
	}

	for (Module* item : list_modules) {
		if (ret != UPDATE_CONTINUE) break;
		ret = item->PostUpdate(dt);
	}

	FinishUpdate();
	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	std::list<Module*>::iterator item = list_modules.end();
	do {
		--item;
		(*item)->CleanUp();
		if ((*item)->static_m)
			continue;
		delete* item;
		*item = nullptr;
	} while (item != list_modules.begin());

	return ret;
}

void Application::Save(JSON_Object* root_node)
{
	JSON_Value* curr_val;
	JSON_Object* curr_obj;
	for (Module* mod : list_modules) {
		curr_val = json_value_init_object();
		json_object_set_value(root_node, mod->name, curr_val);
		curr_obj = json_value_get_object(curr_val);
		mod->Save(curr_obj);
	}
}

void Application::Load(JSON_Object* root_node)
{
	JSON_Value* curr_val;
	JSON_Object* curr_obj;
	for (Module* mod : list_modules) {
		curr_val = json_object_get_value(root_node, mod->name);
		curr_obj = json_value_get_object(curr_val);
		mod->Load(curr_obj);
	}
}

void Application::AddModule(Module* mod)
{
	list_modules.push_back(mod);
}