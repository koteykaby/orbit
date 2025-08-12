#include "Console.hpp"

namespace DebugConsole {
    void CreateConsole() {
    AllocConsole();
    SetConsoleTitleA("orbit");

    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONOUT$", "w", stderr);

    std::cout << "orbit log output" << std::endl;
}
}