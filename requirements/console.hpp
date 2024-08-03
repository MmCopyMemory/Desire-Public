#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

namespace patch
{
    template < typename T > std::string to_string(const T& n)
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

class Console {
private:
    const std::string RESET = "\033[0m";
    std::unordered_map<std::string, std::pair<std::string, std::string>> colorMap = {
        {"PINK", {"\033[38;5;206m", "*"}},
        {"BLUE", {"\033[38;5;33m", "?"}},
        {"GREEN", {"\033[38;5;82m", "+"}},
        {"RED", {"\033[38;5;196m", "!"}},
        {"YELLOW", {"\033[38;5;226m", "~"}},
        {"CYAN", {"\033[38;5;45m", "#"}},
        {"MAGENTA", {"\033[38;5;201m", "%"}},
        {"ORANGE", {"\033[38;5;208m", "@"}},
        {"PURPLE", {"\033[38;5;93m", "^"}},
        {"LIME", {"\033[38;5;154m", "&"}},
        {"WHITE", {"\033[38;5;15m", "="}}
    };

public:
    void PrintColoredText(const std::string& text, const std::string& colorKey, bool same_line, bool center) {
        auto it = colorMap.find(colorKey);
        if (it != colorMap.end()) {
            const std::string& color = it->second.first;
            const std::string& indicator = it->second.second;

            if (center) {
                CONSOLE_SCREEN_BUFFER_INFO csbi;
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                GetConsoleScreenBufferInfo(hConsole, &csbi);
                int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
                int textLength = text.length();
                int x = (consoleWidth - textLength) / 2;
                for (int i = 0; i < x; ++i) {
                    std::cout << " ";
                }
            }


            std::cout << "[" << color << indicator << RESET << "] " << text;
            if (!same_line) {
                std::cout << std::endl;
            }
        }
    }

    void AdjustConsole(bool revert) {
        HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD consoleMode;
        GetConsoleMode(handleOut, &consoleMode);

        if (!revert)
            consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        else
            consoleMode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(handleOut, consoleMode);
    }

    void CenterConsole(int width, int height) {
        HWND console = GetConsoleWindow();
        RECT rConsole;
        GetWindowRect(console, &rConsole);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        MoveWindow(console, (screenWidth - width) / 2, (screenHeight - height) / 2, width, height, TRUE);
    }

    void SetConsoleSize(int cols, int lines) {
        std::string cmd = "mode con cols=" + patch::to_string(cols) + " lines=" + patch::to_string(lines);
        system(cmd.c_str());
    }



};