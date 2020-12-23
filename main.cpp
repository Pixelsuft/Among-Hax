#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;
//Made by PixelSuft
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
		if(FileExists("no_cooldown.txt")){
			if(writeMemory(game_a + 0xE4955A, { 0x90, 0x90, 0x90, 0x90, 0x90 }))
				cout <<"No cooldown [on]" <<endl;
			else cout <<"No cooldown [error]" <<endl;
		}
		else cout <<"No cooldown [off]" <<endl;
		if(FileExists("noclip.txt")){
			if(writeMemory(up + 0x960ca6, { 0x85 }))
				cout <<"Noclip [on]" <<endl;
			else cout <<"Noclip [error]" <<endl;
		}
		else cout <<"Noclip [off]" <<endl;
		//Importer is beta
		if(FileExists("imposter.txt")){
			uint64_t Imposter = RPM<uint64_t>(game_a + 0x144BB70);
			Imposter = RPM<uint64_t>(Imposter + 0x5C);
			Imposter = RPM<uint64_t>(Imposter + 0x0);
			Imposter = RPM<uint64_t>(Imposter + 0x34);
			WPM<int>(Imposter + 0x28, 1);
			cout <<"Imposter [on]" <<endl;
		}
		else cout <<"Imposter [off]" <<endl;
		
		cout <<endl <<"Now you can close window";
        FreeConsole();
        return TRUE;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved){
        if(reason==DLL_PROCESS_ATTACH)
                CreateThread(0, 4096, &main, 0,0, NULL); 
        return TRUE;
}
