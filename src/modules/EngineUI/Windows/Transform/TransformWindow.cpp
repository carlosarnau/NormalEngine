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
	ImGui::SetColumnWidth(0, 79);

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

	// Column II
	// Position inputs
	ImGui::PushItemWidth(40);

	// First slider 1
	ImGui::SetCursorPos(ImVec2(90, 72));
	static float x1 = 0.00f;
	ImGui::DragFloat("##x", &x1, 0.00f);

	// Button colored
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f,0.2f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::SetCursorPos(ImVec2(130, 72));
	ImGui::Button("x", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Second slider
	static float y1 = 0.00f;
	ImGui::DragFloat("##y", &y1, 0.00f);

	// Button colored 2
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f,0.8f,0.3f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::SetCursorPos(ImVec2(197, 72));
	ImGui::Button("y", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Third slider
	static float z1 = 0.00f;
	ImGui::DragFloat("##z", &z1, 0.00f);

	// Button colored 3
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::SetCursorPos(ImVec2(264, 72));
	ImGui::Button("z", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	// Rotation inputs
	ImGui::PushItemWidth(40);

	// First slider 1
	ImGui::SetCursorPos(ImVec2(90, 97));
	static float x2 = 0.00f;
	ImGui::DragFloat("##x", &x2, 0.00f);

	// Button colored
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f,0.2f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::SetCursorPos(ImVec2(130, 97));
	ImGui::Button("x", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Second slider
	static float y2 = 0.00f;
	ImGui::DragFloat("##y", &y2, 0.00f);

	// Button colored 2
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f,0.8f,0.3f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::SetCursorPos(ImVec2(197, 97));
	ImGui::Button("y", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Third slider
	static float z2 = 0.00f;
	ImGui::DragFloat("##z", &z2, 0.00f);

	// Button colored 3
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::SetCursorPos(ImVec2(264, 97));
	ImGui::Button("z", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	// Scale inputs
	ImGui::PushItemWidth(40);

	// First slider 1
	ImGui::SetCursorPos(ImVec2(90, 122));
	static float x3 = 0.00f;
	ImGui::DragFloat("##x", &x3, 0.00f);

	// Button colored
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f,0.2f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::SetCursorPos(ImVec2(130, 122));
	ImGui::Button("x", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Second slider
	static float y3 = 0.00f;
	ImGui::DragFloat("##y", &y3, 0.00f);

	// Button colored 2
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f,0.8f,0.3f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::SetCursorPos(ImVec2(197, 122));
	ImGui::Button("y", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Third slider
	static float z3 = 0.00f;
	ImGui::DragFloat("##z", &z3, 0.00f);

	// Button colored 3
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::SetCursorPos(ImVec2(264, 122));
	ImGui::Button("z", ImVec2{ 19, 19 });
	ImGui::PopStyleColor(3);

	ImGui::End();
}