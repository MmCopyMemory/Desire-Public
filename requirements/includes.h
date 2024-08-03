#pragma once


#include <Windows.h>
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <d3d9.h>
#include <d3d11.h>
#include <dwmapi.h>
#include <TlHelp32.h>
#include <string>
#include "console.hpp"

#include "../requirements/ui/imgui.h"
#include "../requirements/ui/imgui_impl_dx11.h"
#include "../requirements/ui/imgui_impl_win32.h"
#include <d3d11.h>
#include <tchar.h>

#include <D3DX11tex.h>
#include "../requirements/ui/imgui_combo.hpp"
#pragma comment(lib, "D3DX11.lib")


#include "../protection/LI_FN.h"
#include "../protection/skc.h"

#include "../kernel/defs.h"
#include "../game/mouse_helper.h"
#include "../kernel/kernel.h"
#include "../game/defines.h"
#include "../game/sdk/offsets.h"
#include "../game/sdk/sdk.h"

#include "../game/mouse.h"

#include "../game/loop.h"
#include "../render/render.hpp"
#include "../game/utils.h"



