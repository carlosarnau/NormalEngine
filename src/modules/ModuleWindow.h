#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include <src/modules/Module.h>
#include <libs/SDL/include/SDL.h>
#include <filesystem>

class Application;

class ModuleWindow : public Module
{
public:
	ModuleWindow(bool start_enabled = true);

	// Destructor
	virtual ~ModuleWindow();

	bool Init();
	bool CleanUp();

	void SetTitle(const char* title);

	void SetFullscreen(const bool fullscreen);
	void SetResizable();
	void SetBorderless();
	void SetFullDesktop(const bool full_desktop);
	void SetBrightness();
	void SetDarkThemeColors();

	void Save(JSON_Object* obj);
	void Load(JSON_Object* obj);

public:
	//The window we'll be rendering to
	SDL_Window* window;
	int w = SCREEN_WIDTH * SCREEN_SIZE, h = SCREEN_HEIGHT * SCREEN_SIZE;

	//The surface contained by the window
	SDL_Surface* screen_surface;
	SDL_Surface* icon;

	int window_w;
	int window_h;

	int screen_size_w;
	int screen_size_h;

	bool fullscreen = false;
	bool resizable = true;
	bool borderless = false;
	bool full_desktop = false;
	float brightness = 1;
};

#endif // __ModuleWindow_H__