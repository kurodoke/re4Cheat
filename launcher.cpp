#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <thread>
#include "dclrThread.h"

HANDLE getHandle(HWND *handleWin, DWORD* PID) {
	//check WINDOW of re4
	do {
		*handleWin = FindWindow(NULL, L"Resident Evil 4");

	} while (*handleWin == NULL);

	GetWindowThreadProcessId(*handleWin, PID);
	return OpenProcess(PROCESS_ALL_ACCESS, false, *PID);
}

//get base address re4
HMODULE getModule(HWND Hwin,DWORD PID,std::wstring wstrTarget) {
	HMODULE hmod[1024];
	HANDLE handle = getHandle(&Hwin, &PID);
	DWORD cbNeeded;
	unsigned int i;

	if (EnumProcessModules(handle, hmod, sizeof(hmod), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameEx(handle, hmod[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				std::wstring wstrModName = szModName;
				if (wstrModName.find(wstrTarget) != std::string::npos)
				{
					CloseHandle(handle);
					return hmod[i];
				}
			}
		}
	}
	return nullptr;
}

int main() {
	HWND handleWin;
	DWORD PID;
	DWORD BASE;
	HANDLE handleProcess{NULL};
	//obj for offsets
	profile_offset pOffsets = profile_offset();
	pStatic pSt = pStatic();

	std::cout << "run the resident evil 4 now!";
	handleProcess = getHandle(&handleWin, &PID);
	if (handleProcess == NULL) {
		std::cout << "openProcess error get code : " << GetLastError();
		return EXIT_FAILURE;
	}
	
	std::cout << std::endl << "PID :" << PID << std::endl;

	BASE = (DWORD)getModule(handleWin, PID, L"bio4.exe");

	uintptr_t BaseAdrProfile = 0;
	
	ReadProcessMemory(handleProcess, (LPCVOID)(BASE + pSt.PROFILE_PSTATIC), &BaseAdrProfile, sizeof(uintptr_t), NULL) ? std::cout << "\nSuccess get Profile Pointer static\n" : std::cout << "rpm error get code : " << GetLastError();

	int choice = 5;
	bool healthToggle = false, ammoToggle = false;

	do {
		std::cout << std::endl << "select one option ? : \n1.unlimited health\n2.unlimited ammo\n10.exit\n choose: ";
		std::cin >> choice;

		std::cout << std::endl;

		if (choice == 1) {
			healthToggle = !healthToggle;
				
			if (healthToggle) {
				std::thread hp(leonCurHealth, handleProcess, (BaseAdrProfile + pOffsets.HEALTH), &healthToggle);
				hp.detach();
				std::cout << std::endl << "activated";
			}
			else {
				std::cout << std::endl << "deactived";
			}
		}
		if (choice == 2) {
			ammoToggle = !ammoToggle;
			if (ammoToggle){
				std::thread ammo(unlimitedAmmo, handleProcess, BASE, pSt, &ammoToggle);
				ammo.detach();
				std::cout << std::endl << "activated";
			}
			else {
				std::cout << std::endl << "deactived";
			}
		}

		if (choice == 10) {
			CloseHandle(handleProcess);

			return EXIT_SUCCESS;
		}
	} while (true);
}