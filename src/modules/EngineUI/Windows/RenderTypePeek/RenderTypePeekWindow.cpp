#include "RenderTypePeekWindow.h"
#include <src/Application.h>
#include <glew/include/GL/glew.h>

void RenderPeekWindow::Start()
{
}

void RenderPeekWindow::Update()
{
	ImGui::Begin(name.c_str(), &active);
	
	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("Render attributes:");
	ImGui::SetCursorPos(ImVec2(15, 57));
	ImGui::Separator();

	/*
	if (ImGui::CollapsingHeader("Meshes")) {

	}
	if (ImGui::CollapsingHeader("Textures")) {
		ImGui::SliderInt("Texture Show Width", &t_w, 0, 4000);
		static int select_img = 0;
		int num_images = App->renderer3D->textures.size();
		if (num_images > 0) {
			ImGui::SliderInt("##Select", &select_img, 0, num_images - 1);
			const GPUTex& t = App->renderer3D->textures[select_img];
			glEnable(GL_TEXTURE_2D);
			int h = t.h / (t.w / (float)t_w), w = t_w;
			ImGui::Image((ImTextureID)t.img_id, ImVec2(w, h));
			PLOG("Error initializing OpenGL! %s\n", gluErrorString(glGetError()));
		}
	}
	extern GLuint checkers_textureID;
	// ImGui::Image((ImTextureID)checkers_textureID, ImVec2(400,400));
	*/

	int win_w, win_h;
	SDL_GetWindowSize(App->window->window, &win_w, &win_h);

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, win_w / 2);

	ImGui::SetCursorPos(ImVec2(15, 75));
	ImGui::Text("Textures");

	ImGui::NextColumn();

	ImGui::SetCursorPos(ImVec2( (win_w / 2) + 15, 75));
	ImGui::Text("Meshes");

	ImGui::End();
}