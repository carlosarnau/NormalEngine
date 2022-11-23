#include "ComponentInspector.h"
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

	/*
	if (entity == nullptr) { ImGui::End(); return; }

	changes_happened |= ImGui::Checkbox("##ActiveEntityCheckbox", &entity->active);

	ImGui::SameLine();
	changes_happened |= ImGui::InputText("##EntityNameInspector", entity->name, sizeof(entity->name));

	static char button_id[64];
	for (auto c : entity->components) {
		sprintf(button_id, "##Button%llu", c->id.id);
		ImGui::Checkbox(button_id, &c->active);
		ImGui::SameLine();		
		c->DrawInspector();
		sprintf(button_id, "Delete##Button%llu", c->id.id);
		ImGui::Button(button_id);
	}
	*/ //Not needed

	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("Camera settings:");
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
	
	ImGui::End();

	// Action control
	ImGui::Begin("Action controls");

	// Start
	if (ImGui::Button("Start", ImVec2(50, 20)))
	{
	}
	if (ImGui::IsItemHovered()) {
		ImGui::Text("The action will start");
	}

	ImGui::SameLine();

	// Pause
	if (ImGui::Button("Pause", ImVec2(50, 20)))
	{
	}
	if (ImGui::IsItemHovered()) {
		ImGui::Text("You'll pause the action");
	}

	ImGui::SameLine();

	// Stop
	if (ImGui::Button("Stop", ImVec2(50, 20)))
	{
	}
	if (ImGui::IsItemHovered()) {
		ImGui::Text("You'll stop the action");
	}

	ImGui::End();
}