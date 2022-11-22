#include "TransformWindow.h"
#include <src/Application.h>
#include <glew/include/GL/glew.h>

void TransformWindow::Start()
{
}

void TransformWindow::Update()
{
	ImGui::Begin("Transform", &active);

    ImGui::SetCursorPos(ImVec2(15, 32));
    ImGui::Text("Transform object options:");
    ImGui::SetCursorPos(ImVec2(15, 57));
    ImGui::Separator();

    // Translate


    // Rotate


    // Scale


	ImGui::End();
}