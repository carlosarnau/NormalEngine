#include "SceneView.h"
#include <src/Application.h>
#include <glew/include/GL/glew.h>
//#include "../../../Render/ModuleRenderer3D.h"
void SceneView::Start()
{
	fb.Create(App->window->w, App->window->h);
	App->renderer3D->hijack_framebuffer = &fb;
}

void SceneView::Update()
{
	extern const std::filesystem::path g_AssetPath;

	// Game view
	ImGui::Begin("Game", &active);
	if (engineView == Game)
	{
		ImVec2 scenesize = { (float)fb.attachment.w, (float)fb.attachment.h };
		float ww = ImGui::GetContentRegionAvail().x;
		float hh = ImGui::GetContentRegionAvail().y;
		scenesize.y = hh;
		scenesize.x = ww;

		ImGui::Image((ImTextureID)fb.attachment.img_id, scenesize, { 0,1 }, { 1,0 });
	}
	ImGui::End();

	// Edito view
	ImGui::Begin(name.c_str(), &active);
	if (engineView == Scene)
	{
		ImVec2 scenesize = { (float)fb.attachment.w, (float)fb.attachment.h };
		float ww = ImGui::GetContentRegionAvail().x;
		float hh = ImGui::GetContentRegionAvail().y;
		scenesize.y = hh;
		scenesize.x = ww;

		glBegin(GL_QUADS);
		glVertex3f(-45, 30, -50);
		glVertex3f(-10, 30, -50);
		glVertex3f(-10, 5, -50);
		glVertex3f(-45, 5, -50);
		glEnd();

		ImGui::Image((ImTextureID)fb.attachment.img_id, scenesize, { 0,1 }, { 1,0 });
	}

	if (ImGui::BeginDragDropTarget())
	{
		if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("CONTENT_BROWSER_ITEM"))
		{
			const wchar_t* path = (const wchar_t*)payload->Data;
			// TryLoadFromDisk(g_AssetPath);
		}
		ImGui::EndDragDropTarget();
	}

	ImGui::End();

	// Action controls
	ImGui::Begin("Action Controls", nullptr, ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar);

	ImVec2 scenesize = { (float)fb.attachment.w, (float)fb.attachment.h };
	float ww = ImGui::GetContentRegionAvail().x;
	float hh = ImGui::GetContentRegionAvail().y;
	scenesize.y = hh;
	scenesize.x = ww;

	// Start
	ImGui::SetCursorPos(ImVec2(scenesize.x / 2 - 68, 28));
	if (ImGui::Button("Start", ImVec2(50, 20)))
	{
		engineView = Game;
		App->renderer3D->gcam = App->renderer3D->GAMEPLAY;
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Start the action");
	}

	ImGui::SameLine();

	// Pause
	if (ImGui::Button("Pause", ImVec2(50, 20)))
	{

	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Pause the action");
	}

	ImGui::SameLine();

	// Stop
	if (ImGui::Button("Stop", ImVec2(50, 20)))
	{
		engineView = Scene;
		App->renderer3D->gcam = App->renderer3D->SCENE;
		
	}
	if (ImGui::IsItemHovered())
	{
		ImGui::SetTooltip("Stop the action");
	}

	ImGui::End();
}

void SceneView::CleanUp()
{
	fb.Destroy();
}