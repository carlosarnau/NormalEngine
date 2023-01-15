#pragma once

class GUImanager
{
public:
	GUImanager();
	~GUImanager();

	void Init();
	void Update();
	void GUImanager::CreateCanvas();
	void GUImanager::CreateBaseElement();
	void GUImanager::CreateButton();
	void GUImanager::CreateLabel();
	void GUImanager::CreateImage();
	void CleanUp();
};