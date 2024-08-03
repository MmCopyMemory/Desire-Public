#pragma once

#include "imgui.h"
#include <map>
#include <string>
#include "imgui_internal.h"
#include "colors_widgets.h"

namespace combo
{
   
    bool		    BeginCombo(const char* label, const char* preview_value, int val = 0, bool multi = false, ImGuiComboFlags flags = 0);
    void		    EndCombo();
    void		    MultiCombo(const char* label, bool variable[], const char* labels[], int count);
    bool		    Combo(const char* label,  int* current_item, const char* (*getter)(void* user_data, int idx), void* user_data, int items_count, int popup_max_height_in_items = -1);
    bool		    Combo(const char* label,  int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1);
    bool		    Combo(const char* label,  int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1);

}
