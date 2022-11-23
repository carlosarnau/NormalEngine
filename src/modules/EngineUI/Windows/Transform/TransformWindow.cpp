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

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 150);

	// Column I
	//
	// Position options
	ImGui::SetCursorPos(ImVec2(15, 75));
	ImGui::Text("Position");

	//
	// Rotation options
	ImGui::SetCursorPos(ImVec2(15, 100));
	ImGui::Text("Rotation");

	//
	// Scale options
	ImGui::SetCursorPos(ImVec2(15, 125));
	ImGui::Text("Scale");

	ImGui::NextColumn();

	ImGui::SetCursorPos(ImVec2(235, 72));
	static int vec3i[3] = { 0, 0, 0 };
	ImGui::InputInt3(" ", vec3i);

	ImGui::SetCursorPos(ImVec2(235, 97));
	static int vec3j[3] = { 0, 0, 0 };
	ImGui::InputInt3("  ", vec3j);

	ImGui::SetCursorPos(ImVec2(235, 122));
	static int vec3k[3] = { 0, 0, 0 };
	ImGui::InputInt3("   ", vec3k);


	ImGui::End();
}