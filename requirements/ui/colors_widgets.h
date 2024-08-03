#pragma once

#include "imgui.h"

namespace colors {

    inline ImVec4 accent_color = ImColor(255, 127, 73);

    namespace menu {

        inline ImVec4 window_bg = ImColor(20, 20, 22);
        inline ImVec4 border = ImColor(17, 17, 17, 255);
        inline ImVec4 watermark_bg = ImColor(21, 19, 20, 255);
        inline ImVec4 watermark_border = ImColor(21, 19, 20, 255);
        inline ImVec4 watermark_filled = ImColor(27, 25, 28);

    }

    namespace tabs {

        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_hovered = ImColor(150, 150, 150);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);

    }

    namespace child {

        inline ImVec4 child_background = ImColor(23, 23, 25);
        inline ImVec4 child_top = ImColor(25, 25, 27);
        inline float child_rounding = 7.f;

    }

    namespace checkbox {

        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_hovered = ImColor(150, 150, 150);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);

        inline ImVec4 checkbox_bg_active = ImColor(37, 37, 39);
        inline ImVec4 checkbox_bg_inactive = ImColor(35, 35, 37);

        inline ImVec4 circle_inactive = ImColor(44, 44, 46);

    }

    namespace slider {

        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_hovered = ImColor(150, 150, 150);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);
        inline ImVec4 slider_inactive = ImColor(35, 35, 37);

    }

    namespace combo {


        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_hovered = ImColor(150, 150, 150);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);
        inline ImVec4 combo_bg = ImColor(27, 27, 29);

    }

    namespace color_picker {

        inline ImVec4 picker_bg = ImColor(27, 27, 29);

    }

    namespace binder {

        inline ImVec4 binder_bg = ImColor(27, 27, 29);
        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_hovered = ImColor(150, 150, 150);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);
        inline ImVec4 line = ImColor(40, 40, 42);
        inline ImVec4 image_active = ImColor(255, 255, 255);
        inline ImVec4 image_hovered = ImColor(150, 150, 150);
        inline ImVec4 image_inactive = ImColor(76, 76, 77);

    }

    namespace button {

        inline ImVec4 button_bg = ImColor(27, 27, 29);
        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);
    }

    namespace input {

        inline ImVec4 input_bg = ImColor(27, 27, 29);
        inline ImVec4 input_image = ImColor(47, 47, 49);
        inline ImVec4 text_active = ImColor(255, 255, 255);
        inline ImVec4 text_hovered = ImColor(150, 150, 150);
        inline ImVec4 text_inactive = ImColor(76, 76, 77);
    }

    namespace preview {

        inline ImVec4 rect = ImColor(40, 40, 42);
        inline ImVec4 name = ImColor(255, 255, 255);
        inline ImVec4 distance = ImColor(255, 255, 255);
        inline ImVec4 head = ImColor(255, 255, 255);
        inline ImVec4 dice = ImColor(255, 255, 255);

    }


}

namespace settings {
    inline float checkbox_rounding = 100.f;
}

