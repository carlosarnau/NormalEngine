#include "ComponentInspector.h"
#include <src/Application.h>

void ComponentInspector::UpdateRMMenu() {
	rm_menu.CheckToOpen();
	if (ImGui::BeginPopup(rm_menu.container_name)) {
		if (ImGui::MenuItem("Add Transform")) {}
		if (ImGui::MenuItem("Add Mesh")) {}
	}
}

void ComponentInspector::Update() {

	ImGui::Begin("UI Editor", &active);

	// Buttons to display the different UI elements
	ImGui::SetCursorPos(ImVec2(15, 32));
	ImGui::Text("UI Elements");
	ImGui::SetCursorPos(ImVec2(15, 60));
	ImGui::Separator();

	static float thumbnailSizeX = 75.0f;
	static float thumbnailSizeY = 20;

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.50f, 0.10f, 0.50f, 1.0f));

	ImGui::SetCursorPos(ImVec2(15, 75));
	ImGui::Button("Canvas", { thumbnailSizeX, thumbnailSizeY });

	ImGui::SetCursorPos(ImVec2(15, 100));
	ImGui::Button("Button", { thumbnailSizeX, thumbnailSizeY });

	ImGui::SetCursorPos(ImVec2(15, 125));
	ImGui::Button("Label", { thumbnailSizeX, thumbnailSizeY });

	ImGui::SetCursorPos(ImVec2(15, 150));
	ImGui::Button("Image", { thumbnailSizeX, thumbnailSizeY });

	ImGui::PopStyleColor();

	// Settings to modify UI properties
	ImGui::SetCursorPos(ImVec2(15, 280));
	ImGui::Text("Element Properties");
	ImGui::SetCursorPos(ImVec2(15, 308));
	ImGui::Separator();

	ImGui::SetCursorPos(ImVec2(15, 323));
	float3 ItemPosition = { 0,0,0 };
	ImGui::DragFloat3("Position", ItemPosition.ptr());

	ImGui::SetCursorPos(ImVec2(15, 348));
	float3 ItemRotation = { 0,0,0 };
	ImGui::DragFloat3("Rotation", ItemRotation.ptr());

	static char pname[32] = "Label1";
	char buf[64];
	ImGui::SetCursorPos(ImVec2(15, 383));
	ImGui::Text("Name:"); ImGui::SameLine();
	sprintf(buf, "%s###Button", pname); // ### operator override ID ignoring the preceding label
	ImGui::Button(buf);
	if (ImGui::BeginPopupContextItem())
	{
		ImGui::Text("Edit name:");
		ImGui::InputText("##edit", pname, IM_ARRAYSIZE(pname));
		if (ImGui::Button("Close"))
			ImGui::CloseCurrentPopup();
		ImGui::EndPopup();
	}
	if (ImGui::IsItemHovered())
		ImGui::SetTooltip("Right-click to edit name");

	ImGui::End();

	bool changes_happened = false;
	ImGui::Begin(name.c_str(), &active);
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

	ImGui::End();
}