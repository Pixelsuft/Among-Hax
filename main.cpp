#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <vector>
bool no_cooldown_active=false;
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
        while(true){
                if(no_cooldown_active==false)cout <<"1)No cooldown (off)" <<endl;
                else cout <<"1)No cooldown (on)" <<endl;
                
                cout <<"Your choose: ";
                int choose=0;
                cin >> choose;
                
                if(choose==1){
                        if(no_cooldown_active==false){
                                if(writeMemory(base + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
                                        std::cout <<"Activated!" <<std::endl;
                        }
                        else{
                                if(writeMemory(base + 0xE4955A, { 0xF3, 0x0F, 0x11, 0x46, 0x44 }))
                                        std::cout <<"Deactivated!" <<std::endl;
                        }
                }
                else break;
        }
        FreeConsole();
        return TRUE;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved){
        if(reason==DLL_PROCESS_ATTACH)
                CreateThread(0, 4096, &main, 0,0, NULL); 
        return TRUE;
}
