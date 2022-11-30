#include <src/helpers/Globals.h>
#include <src/Application.h>
#include "ModuleWindow.h"

ModuleWindow::ModuleWindow(bool start_enabled) : Module("window")
{
	window = NULL;
	screen_surface = NULL;
}

// Destructor
ModuleWindow::~ModuleWindow()
{
}

// Called before render is available
bool ModuleWindow::Init()
{
	PLOG("Init SDL window & surface");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		PLOG("SDL_VIDEO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		int width = SCREEN_WIDTH * SCREEN_SIZE;
		int height = SCREEN_HEIGHT * SCREEN_SIZE;
		Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

		//Use OpenGL 3.1
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
		SDL_GL_SetSwapInterval(0);

		SDL_DisplayMode DM;
		SDL_GetCurrentDisplayMode(0, &DM);
		screen_size_w = DM.w;
		screen_size_h = DM.h;

		if (window_w == 0 || window_h == 0)
		{
			window_w = screen_size_w - 100;
			window_h = screen_size_h - 100;
		}

		if(fullscreen == true)
		{
			flags |= SDL_WINDOW_FULLSCREEN;
		}

		if(resizable == true)
		{
			flags |= SDL_WINDOW_RESIZABLE;
		}

		if(borderless == true)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}

		if(full_desktop == true)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		
		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if(window == NULL)
		{
			PLOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);

			icon = SDL_LoadBMP("Assets/NElogo.bmp");
			if (icon != nullptr)
			{
				SDL_SetWindowIcon(window, icon);
				SDL_FreeSurface(icon);
			}
		}
	}

	return ret;
}

// Called before quitting
bool ModuleWindow::CleanUp()
{
	PLOG("Destroying SDL window and quitting all SDL systems");

	// Destroy Surface
	if (screen_surface != NULL)
	{
		SDL_FreeSurface(screen_surface);
		screen_surface = NULL;
	}

	//Destroy window
	if(window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}

void ModuleWindow::SetTitle(const char* title)
{
	SDL_SetWindowTitle(window, title);
}

void ModuleWindow::SetFullscreen(const bool fullscreen)
{
	if (fullscreen)
	{
		SDL_GetWindowSize(window, &window_w, &window_h);
		SDL_SetWindowSize(window, screen_size_w, screen_size_h);

		SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
	}

	else
	{
		SDL_SetWindowFullscreen(this->window, 0);
		SDL_SetWindowSize(window, window_w, window_h);
	}
}

void ModuleWindow::SetResizable()
{
	SDL_SetWindowResizable(this->window, (SDL_bool)this->resizable);
}

void ModuleWindow::SetBorderless()
{
	SDL_SetWindowBordered(App->window->window, (SDL_bool)!this->borderless);
}

void ModuleWindow::SetFullDesktop(const bool full_desktop)
{
	if (full_desktop)
		SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	else
		SDL_SetWindowFullscreen(this->window, 0);
}

void ModuleWindow::SetBrightness()
{
	SDL_SetWindowBrightness(this->window, this->brightness);
}

/*
void ModuleWindow::Save(JSON_Object* obj)
{
	json_object_set_boolean(obj, "fullscreen", fullscreen);
	json_object_set_boolean(obj, "borderless", borderless);
	json_object_set_boolean(obj, "full_desktop", full_desktop);
	json_object_set_boolean(obj, "resizable", resizable);
	json_object_set_number(obj, "width", w);
	json_object_set_number(obj, "height", h);
	json_object_set_string(obj, "title", SDL_GetWindowTitle(window));
}

void ModuleWindow::Load(JSON_Object* obj) {
	fullscreen = json_object_get_boolean(obj, "fullscreen");
	borderless = json_object_get_boolean(obj, "borderless");
	full_desktop = json_object_get_boolean(obj, "full_desktop");
	resizable = json_object_get_boolean(obj, "resizable");
	w = json_object_get_number(obj, "width");
	h = json_object_get_number(obj, "height");
	SDL_SetWindowTitle(window, json_object_get_string(obj, "title"));
}
*/

void ModuleWindow::SetDarkThemeColors()
{
	auto& colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f,0.105f,0.11f,1.0f };

	// Headers
	colors[ImGuiCol_Header] = ImVec4{ 0.2f,0.205f,0.21f,1.0f };
	colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f,0.305f,0.31f,1.0f };
	colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };

	// Buttons
	colors[ImGuiCol_Button] = ImVec4{ 0.2f,0.205f,0.21f,1.0f };
	colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f,0.305f,0.31f,1.0f };
	colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };

	// Frame BG
	colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f,0.205f,0.21f,1.0f };
	colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f,0.305f,0.31f,1.0f };
	colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };

	// Tabs
	colors[ImGuiCol_Tab] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };
	colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f,0.3805f,0.381f,1.0f };
	colors[ImGuiCol_TabActive] = ImVec4{ 0.28f,0.2805f,0.281f,1.0f };
	colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f,0.205f,0.21f,1.0f };

	// Title
	colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };
	colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f,0.1505f,0.151f,1.0f };
}