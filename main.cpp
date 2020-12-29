#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>

//#include <WTypesbase.h>  //beta
//#include <cstdint>  //beta

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
		bool no_cooldown_on=false;
		bool noclip_on=false;
		bool was_changed=true; //true for first display options
		while(true)
		{
			if(GetAsyncKeyState(VK_F1))
			{
				if(no_cooldown_on==false){
					if(writeMemory(game_a + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
					{
						no_cooldown_on=true;
						was_changed=true;
					}
				}
				else
				{
					if(writeMemory(game_a + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
					{
						no_cooldown_on=false;
						was_changed=true;
					}
				}
			}
			if(GetAsyncKeyState(VK_F2))
			{
				if(noclip_on==false){
					if(writeMemory(up + 0x960ca6, { 0x85 }))
					{
						noclip_on=true;
						was_changed=true;
					}
				}
				else
				{
					if(writeMemory(up + 0x960ca6, { 0x84 }))
					{
						noclip_on=false;
						was_changed=true;
					}
				}
			}
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				break;
			}
			if(was_changed)
			{
				was_changed=false;
				system("cls");
				cout <<"Pixelsuft Among Hax" <<endl <<"Created by Pixelsuft" <<endl <<endl;
				cout <<"No Cooldown [F1] ";
				if(no_cooldown_on==true)cout <<"[ON]";
				else cout <<"[OFF]";
				cout <<";" <<endl;
				cout <<"NoClip [F2] ";
				if(noclip==true)cout <<"[ON]";
				else cout <<"[OFF]";
				cout <<";" <<endl;
				cout <<"Break [ESC]" <<";" <<endl;
			}
		}
		cout <<endl <<endl <<"Now you can close this window";
        FreeConsole();
        return TRUE;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved){
        if(reason==DLL_PROCESS_ATTACH)
                CreateThread(0, 4096, &main, 0,0, NULL); 
        return TRUE;
}
