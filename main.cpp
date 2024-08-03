#include "requirements/includes.h"
//#include "render/render.hpp"
//#include "kernel/kernel.h"


//memory_event(fvector(-target.y / 5, target.x / 5, 0));



int main()
{
	Console console;

	console.SetConsoleSize(85, 15);
	console.CenterConsole(85 * 8, 15 * 16);
	console.AdjustConsole(false); // adjust console so you can print color codes


	
	mouse_interface();
	SonyDriverHelper::api::Init();

	const char* username = std::getenv("USERNAME");


	std::string welcomeMessage = "welcome " + std::string(username) + " ! " + __DATE__ + "\n";


	console.PrintColoredText(welcomeMessage, "GREEN", false, true);

	console.PrintColoredText("waiting for fortnite...\n", "PINK", false, true);
	mem::find_driver();


	HWND fn_win = NULL;

	
	while (fn_win == NULL) {
		fn_win = FindWindowA_Spoofed(0, "Fortnite  ");
	}

	console.PrintColoredText("found fortnite !\n", "GREEN", false, true);

	Sleep(2000);

	console.PrintColoredText("loading...", "PURPLE", false, true);


	Sleep(2000);
	LPCTSTR processName = "EasyAntiCheat_EOS.exe";
	if (IsProcessRunning(processName)) {

		EAC = true;
		console.PrintColoredText("Running on EAC \n", "GREEN", true, true);
	}
	else {
		
		EAC = false;
		console.PrintColoredText("Running on BE \n", "GREEN", true, true);
	}

	proc_ud = mem::find_process(("FortniteClient-Win64-Shipping.exe"));

	if (!mem::CR3())
	{
		console.PrintColoredText("Error 0x02 \n", "RED", true, true); Sleep(2000); // cr3 not good
	}


	virtualaddy = mem::find_image();

	width = GetSystemMetrics(SM_CXSCREEN); height = GetSystemMetrics(SM_CYSCREEN);


	int64 va_text = 0;
	for (int i = 0; i < 25; i++)
		if ((read<int32>(virtualaddy + (i * 0x1000) + 0x250)) == 0x260E020B)
		{

			va_text = virtualaddy + ((i + 1) * 0x1000);
			dynamic_uworld = 0x11558538 + va_text;
		}


	if (Render->Setup() != true) ExitProcess(0);

	if (Hook->Setup() != true) ExitProcess(0);
	//Sleep(2000);

	Render->Render();
	//Sleep(2000);

}