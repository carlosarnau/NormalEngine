#include "CameraWindow.h"
#include <src/Application.h>

void CameraWindow::UpdateRMMenu() {
	rm_menu.CheckToOpen();
	if (ImGui::BeginPopup(rm_menu.container_name)) {
		if (ImGui::MenuItem("Add Transform")) {}
		if (ImGui::MenuItem("Add Mesh")) {}
	}
}

void CameraWindow::Update() {
	bool changes_happened = false;
	ImGui::Begin(name.c_str(), &active);

	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("Camera settings");
	ImGui::SetCursorPos(ImVec2(15, 60));
	ImGui::Separator();

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 74);
	
	// Column I
	//
	// Position options
	ImGui::SetCursorPos(ImVec2(15, 78));
	ImGui::Text("Position");

	//
	// Rotation options
	ImGui::SetCursorPos(ImVec2(15, 108));
	ImGui::Text("Rotation");

	ImGui::NextColumn();

	// Column II
	// Position inputs
	ImGui::PushItemWidth(40);

	// First slider 1
	ImGui::SetCursorPos(ImVec2(90, 75));
	static float x1 = 0.00f;
	ImGui::DragFloat("##x", &x1, 0.00f);

	// Button colored
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f,0.2f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::SetCursorPos(ImVec2(130, 75));
	ImGui::Button("X", ImVec2{ 20, 20 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Second slider
	static float y1 = 0.00f;
	ImGui::DragFloat("##y", &y1, 0.00f);

	// Button colored 2
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f,0.8f,0.3f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::SetCursorPos(ImVec2(197, 75));
	ImGui::Button("Y", ImVec2{ 20, 20 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Third slider
	static float z1 = 0.00f;
	ImGui::DragFloat("##z", &z1, 0.00f);

	// Button colored 3
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::SetCursorPos(ImVec2(264, 75));
	ImGui::Button("Z", ImVec2{ 20, 20 });
	ImGui::PopStyleColor(3);

	// Rotation inputs
	ImGui::PushItemWidth(40);

	// First slider 1
	ImGui::SetCursorPos(ImVec2(90, 105));
	static float x2 = 0.00f;
	ImGui::DragFloat("##x", &x2, 0.00f);

	// Button colored
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f,0.2f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f,0.1f,0.15f,1.0f });
	ImGui::SetCursorPos(ImVec2(130, 105));
	ImGui::Button("X", ImVec2{ 20, 20 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Second slider
	static float y2 = 0.00f;
	ImGui::DragFloat("##y", &y2, 0.00f);

	// Button colored 2
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f,0.8f,0.3f,1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f,0.7f,0.2f,1.0f });
	ImGui::SetCursorPos(ImVec2(197, 105));
	ImGui::Button("Y", ImVec2{ 20, 20 });
	ImGui::PopStyleColor(3);

	ImGui::SameLine();

	// Third slider
	static float z2 = 0.00f;
	ImGui::DragFloat("##z", &z2, 0.00f);

	// Button colored 3
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::SetCursorPos(ImVec2(264, 105));
	ImGui::Button("Z", ImVec2{ 20, 20 });
	ImGui::PopStyleColor(3);
	
	ImGui::End();
}