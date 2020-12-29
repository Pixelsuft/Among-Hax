#include <Windows.h>
#include <iostream>
#include <vector>

#include <WTypesbase.h>  //beta
#include <cstdint>  //beta

using namespace std;
//Made by PixelSuft
HANDLE handle;
void WPM(uintptr_t address, T buffer)    //short function for writing
{
    WriteProcessMemory(handle, (LPVOID)address, &buffer, sizeof(buffer), NULL);
}

BOOL writeMemory(uintptr_t const address, std::vector<uint8_t> const& bytes){
        return WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
}
DWORD game_a=(DWORD)GetModuleHandleA("GameAssembly.dll");
DWORD up=(DWORD)GetModuleHandleA("UnityPlayer.dll");
DWORD WINAPI main(LPVOID lpParam){
        AllocConsole();
        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
		setlocale(0,"");
        SetConsoleTitleA("Pixelsuft Among Hax");
		system("color 0a");
		cout <<"Pixelsuft Among Hax" <<endl <<"Created by Pixelsuft" <<endl <<endl;
		bool no_cooldown_on=false;
		bool noclip_on=false;
		while(true)
		{
		if(GetAsyncKeyState(VK_F1))
		{
		if(no_cooldown_on){
			if(writeMemory(game_a + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
				cout <<"No cooldown [on]" <<endl;
			else cout <<"No cooldown [error]" <<endl;
		}
		else cout <<"No cooldown [off]" <<endl;
		}
		if(GetAsyncKeyState(VK_F1))
		{
		if(noclip_on){
			if(writeMemory(up + 0x960ca6, { 0x85 }))
				cout <<"Noclip [on]" <<endl;
			else cout <<"Noclip [error]" <<endl;
		}
		else cout <<"Noclip [off]" <<endl;
		}
		}
		cout <<endl <<"Now you can close this window";
        FreeConsole();
        return TRUE;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved){
        if(reason==DLL_PROCESS_ATTACH)
                CreateThread(0, 4096, &main, 0,0, NULL); 
        return TRUE;
}
