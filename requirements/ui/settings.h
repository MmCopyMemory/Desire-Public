#pragma once
#include "colors_widgets.h"

namespace settings {
    inline ImVec2 size_menu = ImVec2(640, 520);
    inline ImVec2 size_watermark = ImVec2(479, 50);
    inline ImVec2 size_preview = ImVec2(300, 400);

}

namespace misc {

    inline int tab_count, active_tab_count = 0;

    inline float anim_tab = 0;

    inline int tab_width = 85;

    inline float child_add, alpha_child = 0;

}

namespace menu {

    inline ImVec4 general_child = ImColor(23, 23, 25);

}

namespace pictures {

    inline ID3D11ShaderResourceView* logo_img = nullptr;
    inline ID3D11ShaderResourceView* aim_img = nullptr;
    inline ID3D11ShaderResourceView* misc_img = nullptr;
    inline ID3D11ShaderResourceView* visual_img = nullptr;
    inline ID3D11ShaderResourceView* world_img = nullptr;
    inline ID3D11ShaderResourceView* settings_img = nullptr;
    inline ID3D11ShaderResourceView* pen_img = nullptr;
    inline ID3D11ShaderResourceView* keyboard_img = nullptr;
    inline ID3D11ShaderResourceView* input_img = nullptr;
    inline ID3D11ShaderResourceView* wat_logo_img = nullptr;
    inline ID3D11ShaderResourceView* fps_img = nullptr;
    inline ID3D11ShaderResourceView* player_img = nullptr;
    inline ID3D11ShaderResourceView* time_img = nullptr;

}

namespace fonts {

    inline ImFont* inter_font;

    inline ImFont* inter_bold_font;

    inline ImFont* inter_bold_font2;

    inline ImFont* inter_bold_font3;

    inline ImFont* inter_bold_font4;

    inline ImFont* inter_font_b;

    inline ImFont* combo_icon_font;

    inline ImFont* weapon_font;

}


//