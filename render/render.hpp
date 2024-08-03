
#include "../requirements/includes.h"
#include "../requirements/ui/fonts.h"
#include "../requirements/ui/settings.h"
#include "../requirements/ui/images.h"


inline ID3D11Device* d3d_device;
inline ID3D11DeviceContext* d3d_device_ctx; 
inline IDXGISwapChain* d3d_swap_chain;
inline ID3D11RenderTargetView* d3d_render_target; 
inline HWND window_handle; 
inline bool show_menu = true; 



namespace render {
    class c_render {
    public:

        auto CreateShittyOverlay() -> bool
        {

            WNDCLASSEXA wcex = {
                sizeof(WNDCLASSEXA),
                0,
                DefWindowProcA,
                0,
                0,
                nullptr,
                LoadIcon(nullptr, IDI_APPLICATION),
                LoadCursor(nullptr, IDC_ARROW),
                nullptr,
                nullptr,
                ("Discord"),
                LoadIcon(nullptr, IDI_APPLICATION)
            };

            RECT Rect;
            GetWindowRect(GetDesktopWindow(), &Rect);

            RegisterClassExA(&wcex);

            window_handle = CreateWindowExA(NULL, ("Discord"), ("Bald Niggas Association - Server"), WS_POPUP, Rect.left, Rect.top, Rect.right, Rect.bottom, NULL, NULL, wcex.hInstance, NULL);


            SetWindowLong(window_handle, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
            MARGINS margin = { -1 };
            DwmExtendFrameIntoClientArea(window_handle, &margin);
            ShowWindow(window_handle, SW_SHOW);
            SetWindowPos(window_handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            SetLayeredWindowAttributes(window_handle, RGB(0, 0, 0), 255, LWA_ALPHA);
            UpdateWindow(window_handle);
            return true;
        }

        auto hijack() -> bool {
            SPOOF_FUNC;
            window_handle = FindWindowA_Spoofed(E("MedalOverlayClass"), E("MedalOverlay"));
            if (window_handle) {
                MARGINS margin = { -1 };
                DwmExtendFrameIntoClientArea(window_handle, &margin);
                SetWindowPos(window_handle, 0, 0, 0, width, height, 0);
                return true;
            };
            MessageBoxA(0, ("Make sure Medal is open"), ("Desire"), MB_ICONINFORMATION);
            return false;
        }
        auto Setup() -> bool {
            //running
            //CreateShittyOverlay();

            hijack();
           // MessageBoxA(0, ("hijack"), ("Desire"), MB_ICONINFORMATION);
            SetupImgui();


            return true;
        }

        auto SetupImgui() -> bool {
            DXGI_SWAP_CHAIN_DESC swap_chain_description = {};
            swap_chain_description.BufferCount = 2;
            swap_chain_description.BufferDesc.Width = 0; // Set the appropriate width based on your requirements
            swap_chain_description.BufferDesc.Height = 0; // Set the appropriate height based on your requirements
            swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            swap_chain_description.BufferDesc.RefreshRate.Numerator = idk::vsync ? 60 : 0; // Adjust based on Vsync state
            swap_chain_description.BufferDesc.RefreshRate.Denominator = idk::vsync ? 1 : 0; // Adjust based on Vsync state
            swap_chain_description.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
            swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            swap_chain_description.OutputWindow = window_handle;
            swap_chain_description.SampleDesc.Count = 1;
            swap_chain_description.SampleDesc.Quality = 0;
            swap_chain_description.Windowed = TRUE;
            swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

            D3D_FEATURE_LEVEL d3d_feature_lvl;

            const D3D_FEATURE_LEVEL d3d_feature_array[1] = { D3D_FEATURE_LEVEL_11_0 };

            D3D11CreateDeviceAndSwapChain(
                nullptr,
                D3D_DRIVER_TYPE_HARDWARE,
                nullptr,
                0,
                d3d_feature_array,
                1,
                D3D11_SDK_VERSION,
                &swap_chain_description,
                &d3d_swap_chain,
                &d3d_device,
                &d3d_feature_lvl,
                &d3d_device_ctx);

            ID3D11Texture2D* pBackBuffer;

            d3d_swap_chain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));

            d3d_device->CreateRenderTargetView(pBackBuffer, NULL, &d3d_render_target);

            pBackBuffer->Release();

            IMGUI_CHECKVERSION();

            ImGui::CreateContext();

            //add fonts etc here
            ImGuiIO& io = ImGui::GetIO(); (void)io;
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

            fonts::inter_font = io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 17, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::inter_font_b = io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 18.5f, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::inter_bold_font = io.Fonts->AddFontFromMemoryTTF(&inter_bold, sizeof inter_bold, 20, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::inter_bold_font2 = io.Fonts->AddFontFromMemoryTTF(&inter_bold, sizeof inter_bold, 17, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::inter_bold_font3 = io.Fonts->AddFontFromMemoryTTF(&inter_bold, sizeof inter_bold, 18, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::inter_bold_font4 = io.Fonts->AddFontFromMemoryTTF(&inter_bold, sizeof inter_bold, 16, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::combo_icon_font = io.Fonts->AddFontFromMemoryTTF(&combo_icon, sizeof combo_icon, 15, NULL, io.Fonts->GetGlyphRangesCyrillic());
            fonts::weapon_font = io.Fonts->AddFontFromMemoryTTF(&weapon, sizeof weapon, 15, NULL, io.Fonts->GetGlyphRangesCyrillic());

            GameFont = io.Fonts->AddFontFromFileTTF(E("C:\\burbank.otf"), 15.f);

            ImGui_ImplWin32_Init(window_handle);

            ImGui_ImplDX11_Init(d3d_device, d3d_device_ctx);

            d3d_device->Release();

            return true;
        }

        auto Render() -> bool {
            static RECT rect_og;
            MSG msg = { NULL };
            ZeroMemory(&msg, sizeof(MSG));

            while (msg.message != WM_QUIT)
            {
                UpdateWindow_Spoofed(window_handle);
                ShowWindow_Spoofed(window_handle, SW_SHOW);

                if ((PeekMessageA)(&msg, window_handle, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                //
                ImGuiIO& io = ImGui::GetIO();
                io.ImeWindowHandle = window_handle;
                io.DeltaTime = 1.0f / 60.0f;

                POINT p_cursor;
                GetCursorPos(&p_cursor);
                io.MousePos.x = p_cursor.x;
                io.MousePos.y = p_cursor.y;

                if (GetAsyncKeyState(VK_LBUTTON)) {
                    io.MouseDown[0] = true;
                    io.MouseClicked[0] = true;
                    io.MouseClickedPos[0].x = io.MousePos.x;
                    io.MouseClickedPos[0].x = io.MousePos.y;
                }
                else
                    io.MouseDown[0] = false;

                if (idk::vsync) {
                    d3d_swap_chain->Present(1, 0);
                }
                else {
                    d3d_swap_chain->Present(0, 0);
                }

                //d3d_swap_chain->Present(1, 0);


                DrawM();
            }
            ImGui_ImplDX11_Shutdown();
            ImGui_ImplWin32_Shutdown();
            ImGui::DestroyContext();

            (DestroyWindow)(window_handle);

            return true;
        }

        std::string GetCurrentTime() {
            time_t now = time(0);
            tm* ltm = localtime(&now);
            char timeStr[6];
            snprintf(timeStr, sizeof(timeStr), "%02d:%02d", ltm->tm_hour, ltm->tm_min);
            return std::string(timeStr);
        }

        auto Menu() -> void {
            D3DX11_IMAGE_LOAD_INFO image; ID3DX11ThreadPump* pump{ nullptr };

            if (pictures::logo_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, &logo, sizeof(logo), &image, pump, &pictures::logo_img, 0);
            if (pictures::aim_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, &aim, sizeof(aim), &image, pump, &pictures::aim_img, 0);
            if (pictures::misc_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, &other, sizeof(other), &image, pump, &pictures::misc_img, 0);
            if (pictures::visual_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, &visual, sizeof(visual), &image, pump, &pictures::visual_img, 0);
            if (pictures::pen_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, &pen, sizeof(pen), &image, pump, &pictures::pen_img, 0);
            if (pictures::world_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, &world, sizeof(world), &image, pump, &pictures::world_img, 0);
            if (pictures::settings_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, setting, sizeof(setting), &image, pump, &pictures::settings_img, 0);
            if (pictures::keyboard_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, keyboard, sizeof(keyboard), &image, pump, &pictures::keyboard_img, 0);
            if (pictures::input_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, inputimg, sizeof(inputimg), &image, pump, &pictures::input_img, 0);
            if (pictures::wat_logo_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, wat, sizeof(wat), &image, pump, &pictures::wat_logo_img, 0);
            if (pictures::fps_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, fps, sizeof(fps), &image, pump, &pictures::fps_img, 0);
            if (pictures::player_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, player, sizeof(player), &image, pump, &pictures::player_img, 0);
            if (pictures::time_img == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, time_shi, sizeof(time_shi), &image, pump, &pictures::time_img, 0);


            //watermark
            {
                ImVec2 display_size = ImGui::GetIO().DisplaySize;
                ImVec2 window_pos((display_size.x - settings::size_watermark.x) / 2, 10);
                ImGui::SetNextWindowPos(window_pos);
                ImGui::SetNextWindowSize(settings::size_watermark);

                ImGui::Begin("||", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);
                const auto& pos = ImGui::GetWindowPos();
                const auto& draw_list = ImGui::GetWindowDrawList();
                ImGuiStyle* style = &ImGui::GetStyle();

                {
                    style->Colors[ImGuiCol_WindowBg] = colors::menu::watermark_bg;
                    style->Colors[ImGuiCol_Border] = colors::menu::watermark_border;

                    style->ItemSpacing = ImVec2(0, 5);
                    style->WindowPadding = ImVec2(0, 0);
                    style->WindowRounding = 8.f;

                }

                float fps = ImGui::GetIO().Framerate;
                float ms = 1000.0f / fps;
                std::string time = GetCurrentTime();

                // name

                draw_list->AddRectFilled(ImVec2(pos.x + 2, pos.y + 2), ImVec2(pos.x + 477, pos.y + 48), ImGui::GetColorU32(colors::menu::watermark_bg), 4.f);
                draw_list->AddRectFilled(ImVec2(pos.x + 10, pos.y + 10), ImVec2(pos.x + 110, pos.y + 40), ImGui::GetColorU32(colors::menu::watermark_filled), 4.f);
                draw_list->AddImage(pictures::wat_logo_img, ImVec2(pos.x + 20, pos.y + 16), ImVec2(pos.x + 36, pos.y + 32), ImVec2(0, 0), ImVec2(1, 1), ImColor(colors::accent_color));
                draw_list->AddText(fonts::inter_bold_font4, 16.f, ImVec2(pos.x + 45, pos.y + 17), ImColor(80, 80, 80), "PUBLIC");

                // mc

                draw_list->AddRectFilled(ImVec2(pos.x + 120, pos.y + 10), ImVec2(pos.x + 230, pos.y + 40), ImGui::GetColorU32(colors::menu::watermark_filled), 4.f);
                draw_list->AddImage(pictures::fps_img, ImVec2(pos.x + 130, pos.y + 17), ImVec2(pos.x + 146, pos.y + 33), ImVec2(0, 0), ImVec2(1, 1), ImColor(colors::accent_color));
                draw_list->AddText(fonts::inter_bold_font4, 16.f, ImVec2(pos.x + 161, pos.y + 17), ImColor(80, 80, 80), (patch::to_string(static_cast<int>(ms)) + "ms").c_str());

                // fps

                draw_list->AddRectFilled(ImVec2(pos.x + 240, pos.y + 10), ImVec2(pos.x + 350, pos.y + 40), ImGui::GetColorU32(colors::menu::watermark_filled), 4.f);
                draw_list->AddImage(pictures::player_img, ImVec2(pos.x + 250, pos.y + 17), ImVec2(pos.x + 266, pos.y + 33), ImVec2(0, 0), ImVec2(1, 1), ImColor(colors::accent_color));
                draw_list->AddText(fonts::inter_bold_font4, 16.f, ImVec2(pos.x + 280, pos.y + 17), ImColor(80, 80, 80), (patch::to_string(static_cast<int>(fps)) + "fps").c_str());

                // time

                draw_list->AddRectFilled(ImVec2(pos.x + 360, pos.y + 10), ImVec2(pos.x + 470, pos.y + 40), ImGui::GetColorU32(colors::menu::watermark_filled), 4.f);
                draw_list->AddImage(pictures::time_img, ImVec2(pos.x + 370, pos.y + 17), ImVec2(pos.x + 386, pos.y + 33), ImVec2(0, 0), ImVec2(1, 1), ImColor(colors::accent_color));
                draw_list->AddText(fonts::inter_bold_font4, 16.f, ImVec2(pos.x + 404, pos.y + 17), ImColor(80, 80, 80), time.c_str());



                ImGui::End();
            }

            {
                RECT screen_rect;
                GetWindowRect(GetDesktopWindow(), &screen_rect);
                auto x = float(screen_rect.right - 640) / 2.f;
                auto y = float(screen_rect.bottom - 520) / 2.f;
                ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
                ImGui::SetNextWindowSize(settings::size_menu);
                ImGui::Begin("...", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDecoration);

                const auto& pos = ImGui::GetWindowPos();
                const auto& draw_list = ImGui::GetWindowDrawList();
                ImGuiStyle* style = &ImGui::GetStyle();

                {
                    style->Colors[ImGuiCol_WindowBg] = colors::menu::window_bg;
                    style->Colors[ImGuiCol_Border] = colors::menu::border;

                    style->ItemSpacing = ImVec2(0, 5);
                    style->WindowPadding = ImVec2(0, 0);
                    style->WindowRounding = 8.f;

                }

                {
                    ImGui::SetCursorPos(ImVec2(10, 10));
                    ImGui::BeginChild("General Tabs", ImVec2(620, 60), true, ImGuiWindowFlags_NoBackground);

                    const auto& pos = ImGui::GetWindowPos();
                    const auto& draw_list = ImGui::GetWindowDrawList();

                    draw_list->AddRectFilled(ImVec2(pos.x, pos.y), ImVec2(pos.x + 620, pos.y + 60), ImGui::GetColorU32(menu::general_child), 10.f);
                    draw_list->AddImage(pictures::logo_img, ImVec2(pos.x + 20, pos.y + 18), ImVec2(pos.x + 44, pos.y + 42), ImVec2(0, 0), ImVec2(1, 1), ImColor(colors::accent_color));
                    draw_list->AddText(fonts::inter_bold_font, 20.f, ImVec2(pos.x + 53, pos.y + 20), ImColor(255, 255, 255), "Desire");

                    draw_list->AddRectFilledMultiColor(ImVec2(pos.x + 140, pos.y + 15), ImVec2(pos.x + 141.5f, pos.y + 30), ImGui::GetColorU32(colors::accent_color, 0), ImGui::GetColorU32(colors::accent_color, 0), ImGui::GetColorU32(colors::accent_color), ImGui::GetColorU32(colors::accent_color));
                    draw_list->AddRectFilledMultiColor(ImVec2(pos.x + 140, pos.y + 30), ImVec2(pos.x + 141.5f, pos.y + 45), ImGui::GetColorU32(colors::accent_color), ImGui::GetColorU32(colors::accent_color), ImGui::GetColorU32(colors::accent_color, 0), ImGui::GetColorU32(colors::accent_color, 0));

                    {
                        {
                            if (misc::tab_count == 1) {
                                misc::tab_width = 92;
                            }
                            else if (misc::tab_count == 2) {
                                misc::tab_width = 90;
                            }
                            else if (misc::tab_count == 3) {
                                misc::tab_width = 89;
                            }
                            else if (misc::tab_count == 4) {
                                misc::tab_width = 90;
                            }
                            else if (misc::tab_count == 5) {
                                misc::tab_width = 92;
                            }
                        }
                        misc::anim_tab = ImLerp(misc::anim_tab, (float)(misc::tab_count * misc::tab_width), ImGui::GetIO().DeltaTime * 15.f);
                        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(pos.x + 160 + misc::anim_tab, pos.y + 12), ImVec2(pos.x + 250 + misc::anim_tab, pos.y + 48), ImColor(25, 25, 25), 6);
                        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(pos.x + 175 + misc::anim_tab, pos.y + 57), ImVec2(pos.x + 235 + misc::anim_tab, pos.y + 60), ImColor(colors::accent_color), 10, ImDrawCornerFlags_Top);
                        ImGui::GetWindowDrawList()->AddShadowRect(ImVec2(pos.x + 175 + misc::anim_tab, pos.y + 57), ImVec2(pos.x + 235 + misc::anim_tab, pos.y + 60), ImGui::GetColorU32(colors::accent_color), 10.f, ImVec2(0, 0), ImDrawCornerFlags_Top, 10.f);


                        ImGui::SetCursorPos(ImVec2(155, 12));
                        ImGui::BeginGroup(); {

                            if (ImGui::Tab("Aimbot", pictures::aim_img, ImVec2(95, 40), 0 == misc::tab_count))
                                misc::tab_count = 0;

                            ImGui::SameLine();

                            if (ImGui::Tab("Visuals", pictures::visual_img, ImVec2(95, 40), 1 == misc::tab_count))
                                misc::tab_count = 1;

                            ImGui::SameLine();

                            if (ImGui::Tab("Misc", pictures::misc_img, ImVec2(85, 40), 2 == misc::tab_count))
                                misc::tab_count = 2;


                        }ImGui::EndGroup();
                    }

                    ImGui::EndChild();
                }

                {
                    misc::alpha_child = ImLerp(misc::alpha_child, (misc::tab_count == misc::active_tab_count) ? 1.f : 0.f, 15.f * ImGui::GetIO().DeltaTime);
                    if (misc::alpha_child < 0.01f && misc::child_add < 0.01f) misc::active_tab_count = misc::tab_count;

                    ImGui::SetCursorPos(ImVec2(10, 80));
                    ImGui::BeginChild("Main", ImVec2(725, 440), true, ImGuiWindowFlags_NoBackground);


                    ImGui::SetCursorPos(ImVec2(0, 100 - (misc::alpha_child * 100)));

                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, misc::alpha_child * style->Alpha);

                    if (misc::active_tab_count == 0)
                    {
                        ImGui::BeginGroup();
                        {
                            ImGui::BeginChildCustom(pictures::aim_img, "Aimbot", ImVec2(304, 270), false, ImGuiWindowFlags_NoScrollWithMouse);
                            {

                                ImGui::Checkbox("Aimbot", &aimb::aimbot);

                                ImGui::Checkbox("Human Aim", &aimb::human_aim);

                                ImGui::Checkbox("Prediction", &aimb::prediction);

                                ImGui::Checkbox("Show FOV", &aimb::show_fov);

                                ImGui::Checkbox("Visible Check", &aimb::visible_check);

                                ImGui::Checkbox("Team Check", &aimb::team_check);




                            }
                            ImGui::EndChildCustom();

                        } ImGui::EndGroup();

                        ImGui::SameLine(0, 10.f);

                        ImGui::BeginGroup();
                        {
                            ImGui::BeginChildCustom(pictures::aim_img, "Settings", ImVec2(304, 220), false, ImGuiWindowFlags_NoScrollWithMouse);
                            {
                                /*ImGui::Checkbox("Enable Deadzone", &aimb::use_deadzone);
                                if (aimb::use_deadzone) {
                                    ImGui::SliderFloat("Value", &aimb::deadzone, 0.0f, 100.0f, "%.1f");
                                }*/
                                ImGui::Keybind(pictures::keyboard_img, "Aim Key", &aimb::key, &aimb::mind, true);
                                
                                const char* aim_items[]{ "Mouse", "Memory" };
                                combo::Combo("Aim Method", &aimb::aim_type, aim_items, IM_ARRAYSIZE(aim_items), 2);

                                ImGui::SliderInt("Smoothing", &aimb::smoothing, 1, 10);
                                ImGui::SliderInt("FOV Size", &aimb::fov_size, 50, 500);



                            }
                            ImGui::EndChildCustom();

                        } ImGui::EndGroup();

                    }

                    else if (misc::active_tab_count == 1)
                    {
                        ImGui::BeginGroup();
                        {
                            ImGui::BeginChildCustom(pictures::visual_img, "ESP", ImVec2(304, 420), false);
                            {
                                ImGui::Checkbox("Box", &esp::box);
                                ImGui::Checkbox("Filled ESP", &esp::filled_esp);
                                ImGui::Checkbox("Skeleton", &esp::skeleton);
                                ImGui::Checkbox("Head Circle", &esp::head_circle);
                                ImGui::Checkbox("Snapline", &esp::snapline); 
                                ImGui::Checkbox("Username", &esp::username);
                                ImGui::Checkbox("Platform", &esp::platform);
                                ImGui::Checkbox("Weapon", &esp::weapon);
                                ImGui::Checkbox("Distance", &esp::distance);
                                ImGui::Checkbox("Rank ESP", &esp::rank_esp);
                            }
                            ImGui::EndChildCustom();

                        } ImGui::EndGroup();

                        ImGui::SameLine(0, 10.f);

                        ImGui::BeginGroup();
                        {
                            ImGui::BeginChildCustom(pictures::visual_img, "Settings", ImVec2(304, 420), false, ImGuiWindowFlags_NoScrollWithMouse);
                            {
                                
                                ImGui::SliderInt("Max Visual Distance", &esp::max_visual_distance, 0, 1000);
                                ImGui::Checkbox("Outline", &esp::outline);

                                const char* box_items[]{ "Box", "Cornered", "Rounded" };
                                combo::Combo("Box type", &esp::box_type, box_items, IM_ARRAYSIZE(box_items), 3);

                                const char* snap_items[]{ "Top", "Center", "Bottom" };
                                combo::Combo("Snapline Pos", &esp::snapline_type, snap_items, IM_ARRAYSIZE(snap_items), 2);

                            }
                            ImGui::EndChildCustom();

                        } ImGui::EndGroup();

                    }

                    else if (misc::active_tab_count == 2)
                    {
                        ImGui::BeginGroup();
                        {
                            ImGui::BeginChildCustom(pictures::visual_img, "Misc", ImVec2(304, 420), false, ImGuiWindowFlags_NoScrollWithMouse);
                            {
                                ImGui::Checkbox("Enable V-sync", &idk::vsync);
                            }
                            ImGui::EndChildCustom();

                        } ImGui::EndGroup();
                    }

                    ImGui::PopStyleVar();

                    ImGui::Spacing();

                    ImGui::EndChild();
                }

                ImGui::End();
            }
        }

        auto DrawM() -> void {
            ImGui_ImplDX11_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();

            Game->ActorLoop();

            if (GetAsyncKeyState(VK_F8) & 1)
            {
                show_menu = !show_menu;
            }

            if (show_menu) {
                Menu();
            }

            ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.f);
            ImGui::Render();
            const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
            d3d_device_ctx->OMSetRenderTargets(1, &d3d_render_target, nullptr);
            d3d_device_ctx->ClearRenderTargetView(d3d_render_target, clear_color_with_alpha);
            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        }
    };

} inline render::c_render* Render = new render::c_render();