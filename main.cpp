#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;
//Made by PixelSuft
BOOL writeMemory(uintptr_t const address, std::vector<uint8_t> const& bytes){
        return WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
}
DWORD base=(DWORD)GetModuleHandleA("GameAssembly.dll");
DWORD WINAPI main(LPVOID lpParam){
        AllocConsole();
        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
	setlocale(0,"");
        SetConsoleTitleA("Pixelsuft Among Hax");
	system("color 0a");
	cout <<"Pixelsuft Among Hax" <<endl <<"Created by Pixelsuft" <<endl <<endl;
	if(FileExists("no_cooldown.txt")){
		if(writeMemory(base + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
			cout <<"No cooldown [on]" <<endl;
		else cout <<"No cooldown [error]" <<endl;
	}
	else cout <<"No cooldown [off]" <<endl;
	cout <<endl <<"Now you can close window";
        FreeConsole();
        return TRUE;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved){
        if(reason==DLL_PROCESS_ATTACH)
                CreateThread(0, 4096, &main, 0,0, NULL); 
        return TRUE;
}
