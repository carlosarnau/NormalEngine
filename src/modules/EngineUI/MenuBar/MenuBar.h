#pragma once
#include "../ui_item.h"
#include "../ModuleEngineUI.h"
#include <src/Application.h>

struct SubMenu
{
    const char* name;
    std::vector<uint32_t> items;
    std::vector<uint32_t> sub_menus;
};

struct MenuItem
{
    bool* active_state;
    const char* name;
    std::vector<uint32_t> sub_items;
};

class MenuBar : public UI_Item
{
public:
    std::vector<MenuItem> items;
    std::vector<uint32_t> base_items;
    std::vector<MenuItem> variable_ui;

    bool registerable = false;
    bool activateAbout = false;
    MenuBar() : UI_Item("Mvsvdar") { active = true; };

    void Init() final;

    void UpdateMenuItem(MenuItem& item);
    
    void Update() final;

    void CleanUp() final {}

    //  These return empty string if cancelled
    static std::string SaveFile(const char* filter);
    static std::string OpenFile(const char* filter);

    void MenuBar::ImportFile();
    update_status MenuBar::CloseApp();

    uint32_t RegisterMenuItem(bool* item_active, const char* name, const char* submenu = "");
};