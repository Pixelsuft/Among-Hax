#include <Windows.h>
#include <iostream>
#include <vector>
//Made by PixelSuft
BOOL writeMemory(uintptr_t const address, std::vector<uint8_t> const& bytes){
        return WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
}
DWORD base=(DWORD)GetModuleHandleA("GameAssembly.dll");
DWORD WINAPI main(LPVOID lpParam){
        AllocConsole();
        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
        SetConsoleTitleA("Pixelsuft Among Hax");
        if(writeMemory(base + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
                std::cout <<"Ok!" <<std::endl;
        FreeConsole();
        return TRUE;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved){
        if(reason==DLL_PROCESS_ATTACH)
                CreateThread(0, 4096, &main, 0,0, NULL); 
        return TRUE;
}