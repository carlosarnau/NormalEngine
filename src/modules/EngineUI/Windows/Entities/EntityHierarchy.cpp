#include "EntityHierachy.h"
#include <src/Application.h>
#include <src/modules/ECS/ModuleECS.h>

void HierarchyWindow::Start() 
{
    inspector = (CameraWindow*)App->engine_ui->GetItem("Camera");
}

void HierarchyWindow::UpdateRMMenu() 
{
}

static ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanFullWidth;

void HierarchyWindow::UpdateEntry(Entity* curr_e) 
{
    bool isselected = IsSelected(curr_e->id);
    ImGuiTreeNodeFlags tmp_flags = node_flags
        | ((curr_e->children.size() == 0) * ImGuiTreeNodeFlags_Leaf)
        | (isselected * ImGuiTreeNodeFlags_Selected);

    bool open = ImGui::TreeNodeEx(&curr_e->id, tmp_flags, curr_e->name);
    if (ImGui::IsItemClicked()) {
        if (!CheckModifiers()) 
            selected.clear();
        selected.push_back(curr_e->id);
        if (inspector != nullptr) {
            if (selected.back() == App->ecs->root.id) {
                inspector->entity = &App->ecs->root;
            }
            else {
                inspector->entity = App->ecs->GetEntity(selected.back());
            }
        }
    }

    for (int i = 0; open && i < curr_e->children.size(); ++i)
        UpdateEntry(curr_e->children[i]);

    if (open) ImGui::TreePop();
}

void HierarchyWindow::Update()
{
	ImGui::Begin(name.c_str(), &active);

    ImGui::SetCursorPos(ImVec2(15, 32));
    ImGui::Text("GameObject options");
    ImGui::SetCursorPos(ImVec2(15, 60));
    ImGui::Separator();

    //Column I
    // GameObject delete
    ImGui::SetCursorPos(ImVec2(15, 78));
    if (ImGui::Button("Delete..", ImVec2(200, 20)))
        ImGui::OpenPopup("Delete");
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("GameObject will be deleted");
    }

    // Delete confirmation popup
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal("Delete", NULL, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Are you sure you want to delete this item?\nThis operation cannot be undone!\n\n");
        ImGui::Separator();

        if (ImGui::Button("OK", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
        ImGui::EndPopup();
    }

    // GameObject reparent
    ImGui::SetCursorPos(ImVec2(15, 108));
    if (ImGui::Button("Reparent", ImVec2(200, 20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("You will reparent GameObject");
    }

    // GameObject empty creation
    ImGui::SetCursorPos(ImVec2(15, 138));
    if (ImGui::Button("Create Empty", ImVec2(200, 20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("You will create an empty GameObject");
    }

    // GameObject children creation
    ImGui::SetCursorPos(ImVec2(15, 168));
    if (ImGui::Button("Create Children", ImVec2(200,20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("A children of GameObject will be created");
    }

    ImGui::SetCursorPos(ImVec2(15, 216));
    ImGui::Separator();

    ImGui::SetCursorPos(ImVec2(15, 230));
    ImGui::Text("GameObject properties:");

	ImGui::End();
    
    ImGui::Begin("Hierarchy");

    ImGui::End();
}