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

	ImGui::End();
}