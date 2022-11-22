#include "EntityHierachy.h"
#include <src/Application.h>
#include <src/modules/ECS/ModuleECS.h>

void HierarchyWindow::Start() {
    inspector = (CameraWindow*)App->engine_ui->GetItem("Camera");
}

void HierarchyWindow::UpdateRMMenu() {
    rm_menu.CheckToOpen();
    if (ImGui::BeginPopup(rm_menu.container_name))
    {
        if (ImGui::MenuItem("New Entity"))
        {
            for (int i = 0; i < selected.size(); ++i)
                App->ecs->AddEntity(selected[i]);
            if (selected.size() == 0)
                App->ecs->AddEntity(UINT64_MAX);
        }
        for (int i = 0; i < selected.size(); ++i)
            if (selected[i] == UINT64_MAX)
                continue;
        if (ImGui::MenuItem("Delete Selected"))
        {
            for (int i = 0; i < selected.size(); ++i)
                App->ecs->DeleteEntity(selected[i]);

            selected.clear();
        }
        ImGui::EndPopup();
    }
}

static ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanFullWidth;

void HierarchyWindow::UpdateEntry(Entity* curr_e) {
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

void HierarchyWindow::Update() {
	
	ImGui::Begin(name.c_str(), &active);
    /*
    if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0) && !CheckModifiers()) {
        selected.clear();
        if (inspector != nullptr) inspector->entity = nullptr;
    }

    UpdateEntry(&App->ecs->root);

    UpdateRMMenu();
    */

    ImGui::SetCursorPos(ImVec2(15, 32));
    ImGui::Text("GameObject Hierarchy options:");
    ImGui::SetCursorPos(ImVec2(15, 57));
    ImGui::Separator();

    // GameObject delete
    ImGui::SetCursorPos(ImVec2(15, 75));
    if (ImGui::Button("Delete", ImVec2(200, 20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SameLine(); 
        ImGui::Text(" GameObject will be deleted");
    }

    // GameObject reparent
    ImGui::SetCursorPos(ImVec2(15, 100));
    if (ImGui::Button("Reparent", ImVec2(200, 20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SameLine();
        ImGui::Text(" You will reparent GameObject");
    }

    // GameObject empty creation
    ImGui::SetCursorPos(ImVec2(15, 125));
    if (ImGui::Button("Create Empty", ImVec2(200, 20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SameLine();
        ImGui::Text(" You will create an empty GameObject");
    }

    // GameObject children creation
    ImGui::SetCursorPos(ImVec2(15, 150));
    if (ImGui::Button("Create Children", ImVec2(200,20)))
    {
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SameLine();
        ImGui::Text(" A children of GameObject will be created");
    }

	ImGui::End();
}