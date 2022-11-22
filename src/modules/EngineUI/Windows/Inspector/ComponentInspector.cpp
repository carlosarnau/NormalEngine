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

	ImGui::Columns(4);

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
	ImGui::SetCursorPos(ImVec2(100, 75));
	static char x1[256];
	ImGui::InputText("x", x1, CHAR_MAX);
	ImGui::SetCursorPos(ImVec2(100, 100));
	static char y1[256];
	ImGui::InputText("y", y1, CHAR_MAX);
	ImGui::SetCursorPos(ImVec2(100, 125));
	static char z1[256];
	ImGui::InputText("z", z1, CHAR_MAX);

	ImGui::NextColumn();

	// Column II
	ImGui::SetCursorPos(ImVec2(200, 75));
	static char xf1[256];
	ImGui::InputText("x", xf1, CHAR_MAX);
	ImGui::SetCursorPos(ImVec2(200, 100));
	static char yr1[256];
	ImGui::InputText("y", yr1, CHAR_MAX);
	ImGui::SetCursorPos(ImVec2(200, 125));
	static char zp1[256];
	ImGui::InputText("z", zp1, CHAR_MAX);

	ImGui::NextColumn();

	// Column II
	ImGui::SetCursorPos(ImVec2(300, 75));
	static char xe1[43];
	ImGui::InputText("x", xe1, CHAR_MAX);
	ImGui::SetCursorPos(ImVec2(300, 100));
	static char yw1[34];
	ImGui::InputText("y", yw1, CHAR_MAX);
	ImGui::SetCursorPos(ImVec2(300, 125));
	static char zq1[54];
	ImGui::InputText("z", zq1, CHAR_MAX);

	ImGui::End();
}