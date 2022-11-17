#include "MenuBar.h"

void MenuBar::Init()
{
}

void MenuBar::UpdateMenuItem(MenuItem& item)
{
    if (item.sub_items.size() == 0)
    {
        bool prev = *item.active_state;
        ImGui::MenuItem(item.name, "", item.active_state);
        App->engine_ui->EngineUI_RequireUpdate(!(*item.active_state != prev));
    }
    else if (ImGui::BeginMenu(item.name))
    {
        for (uint16_t i = 0; i < item.sub_items.size(); ++i)
            UpdateMenuItem(items[item.sub_items[i]]);

        ImGui::EndMenu();
    }

}

void MenuBar::Update()
{
    if (!active) return;
    ImGui::BeginMainMenuBar();

    // Should a main menu register and be a class/struct by itself or should it be standalone
    /*
    if (ImGui::BeginMenu("Menu1"))
    {
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Menu2"))
    {
        ImGui::EndMenu();
    }
    */

    if (ImGui::BeginMenu("Menu"))
    {
        if (ImGui::MenuItem("Save Scene", "CTRL+S")) 
        {
        }
        if (ImGui::MenuItem("Load Scene", "CTRL+L")) 
        {
        }
        if (ImGui::MenuItem("Import", "CTRL+I"))
        {
        }
        if (ImGui::MenuItem("Show/Hide Windows", "CTRL+V"))
        {
        }
        if (ImGui::MenuItem("Delete Scene", "CTRL+D")) 
        {
        }
        if (ImGui::MenuItem("Exit"))
        {
        }
        
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Tools"))
    {
        for (uint16_t i = 0; i < 5; ++i)
        {
            UpdateMenuItem(items[base_items[i]]);
        }

        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Help"))
    {
        if (ImGui::MenuItem("About..."))
        {
            activateAbout = !activateAbout;
        }
        if (ImGui::MenuItem("Go to GitHub"))
        {
            ShellExecute(NULL, "open", "https://github.com/carlosarnau/NormalEngine", NULL, NULL, SW_SHOWNORMAL);
        }
        if (ImGui::MenuItem("Download latest"))
        {
            ShellExecute(NULL, "open", "https://github.com/carlosarnau/NormalEngine/releases", NULL, NULL, SW_SHOWNORMAL);
        }
        if (ImGui::MenuItem("Documentation"))
        {
            ShellExecute(NULL, "open", "https://github.com/carlosarnau/NormalEngine#readme", NULL, NULL, SW_SHOWNORMAL);
        }
        if (ImGui::MenuItem("Report a Bug"))
        {
            ShellExecute(NULL, "open", "https://github.com/carlosarnau/NormalEngine/issues", NULL, NULL, SW_SHOWNORMAL);
        }
        ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();

    if (activateAbout == true)
    {
        ImGui::Begin("About", 0, ImGuiWindowFlags_MenuBar);
        {
            ImGui::TextColored(ImVec4(1, 0, 0, 1), "Normal Engine v0.1");
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("New tab will open");
            if (ImGui::IsItemClicked())
                ShellExecute(NULL, "open", "https://github.com/carlosarnau/NormalEngine", NULL, NULL, SW_SHOWNORMAL);
            ImGui::Text("The next generation Game Engine");
            ImGui::TextColored(ImVec4(1, 0, 0, 1), "Carlos Arnau");
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("New tab will open");
            if (ImGui::IsItemClicked())
                ShellExecute(NULL, "open", "https://github.com/carlosarnau", NULL, NULL, SW_SHOWNORMAL);
            ImGui::SameLine();
            ImGui::Text("and");
            ImGui::SameLine();
            ImGui::TextColored(ImVec4(1, 0, 0, 1), "Pol Farreras");
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("New tab will open");
            if (ImGui::IsItemClicked())
                ShellExecute(NULL, "open", "https://github.com/fakefarreraspol", NULL, NULL, SW_SHOWNORMAL);

            ImGui::Text("");
            ImGui::Separator();
            ImGui::Text("");

            ImGui::Text("3rd Party Libraries used:");
            ImGui::Text("- SDL 2.0.6");
            ImGui::Text("- SDL Mixer 2.0.0");
            ImGui::Text("- Glew 2.0.0");
            ImGui::Text("- ImGui 1.51");
            ImGui::Text("- MathGeoLib 1.5");
            ImGui::Text("- OpenGL 3.1");
            ImGui::Text("- Assimp 3.1.1");

            ImGui::Text("");
            ImGui::Separator();
            ImGui::Text("");

            ImGui::Text("License:");
            ImGui::Text("MIT License");
            ImGui::Text("Copyright (c) 2022 fakefarreraspol & carlosarnau");

            ImGui::Text("Permission is hereby granted, free of charge, to any person obtaining a copy");
            ImGui::Text("of this software and associated documentation files(the 'Software'), to deal");
            ImGui::Text("in the Software without restriction, including without limitation the rights");
            ImGui::Text("to use, copy, modify, merge, publish, distribute, sublicense, and /or sell");
            ImGui::Text("copies of the Software, and to permit persons to whom the Software is");
            ImGui::Text("furnished to do so, subject to the following conditions:");

            ImGui::Text("The above copyright notice and this permission notice shall be included in all");
            ImGui::Text("copies or substantial portions of the Software.");

            ImGui::Text("THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR");
            ImGui::Text("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,");
            ImGui::Text("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE");
            ImGui::Text("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER");
            ImGui::Text("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,");
            ImGui::Text("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE");
            ImGui::Text("SOFTWARE.");

        }
        ImGui::End();
    }
}

uint32_t MenuBar::RegisterMenuItem(bool* item_active, const char* name, const char* submenu)
{
    MenuItem mi;
    mi.active_state = item_active;
    mi.name = name;
    items.push_back(mi);
    uint32_t ret = items.size() - 1;
    if (strcmp(submenu, "") == 0) base_items.push_back(ret);
    else {} //items[sub_item].sub_items.push_back(ret);
    // TODO: Find submenu and plop it there, or create it
    return ret;
};

update_status MenuBar::Exit()
{
    return UPDATE_STOP;
}
