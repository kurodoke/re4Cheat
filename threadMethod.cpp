#include "dclrThread.h"

//method for health (leon)
void leonCurHealth(HANDLE hProcess, uintptr_t addr, bool* toggle) {
	uintptr_t pBuffer{ 0 }, max{ 0 };
	while (*toggle) {
		if (max == NULL) {
			if (ReadProcessMemory(hProcess, (LPCVOID)(addr + 0x2), &max, sizeof(uintptr_t), NULL)) {}
			else {
				std::cout << "rpm error get max value.. get code : " << GetLastError();
				return;
			}
		}
		if (ReadProcessMemory(hProcess, (LPCVOID)addr, &pBuffer, sizeof(uintptr_t), NULL)) {
			if (pBuffer < max) {
				if (WriteProcessMemory(hProcess, (LPVOID)addr, &max, sizeof(uintptr_t), NULL)) {}
				else {
					std::cout << "wpm error get code : " << GetLastError();
					return;
				}
			}
		}
		else {
			std::cout << "rpm error get current value.. get code : " << GetLastError();
			return;
		}
		Sleep(500);
	}
	return;
}

void unlimitedAmmo(HANDLE hProcess, DWORD baseAddrAPP, pStatic pSt, bool* toggle) {
	uintptr_t usedAddr{ 0x0 }, lastAddr{ 0x0 };
	item_offsets item;
	int rawData, rawAmmo;
	uint16_t cvrtData, lastAmmoVal{ 0 }, curAmmoVal{ 0 };
	bool weapon = false;
	while (*toggle) {
		//gettingg the real addresses of weap used
		if (ReadProcessMemory(hProcess, (LPCVOID)(baseAddrAPP + pSt.EQUIPED_WEAPON_STATIC), &usedAddr, sizeof(usedAddr), NULL)) {
			//check if the address are the same as before
			if (usedAddr != 0x0) {
				if (usedAddr != lastAddr) {
					lastAmmoVal = 0; curAmmoVal = 0;
					if (ReadProcessMemory(hProcess, (LPCVOID)usedAddr, &rawData, sizeof(rawData), NULL)) {
						//convert from 4 byte data to 2 byte
						cvrtData = (uint16_t)rawData;
						if (cWeap.at(cvrtData) == 1) { //weapon
							item.BASE_ITEM = usedAddr;
						}
					}
					else {
						std::cout << "\nrpm error get code : " << GetLastError();
						return;
					}
				}
				//same address
				else {
					if (ReadProcessMemory(hProcess, (LPCVOID)(item.BASE_ITEM + item.WEAPON_AMMO), &rawAmmo, sizeof(rawAmmo), NULL)) {
						//convert from 4 byte data to 2 byte
						curAmmoVal = (uint16_t)rawAmmo;
						if (curAmmoVal < lastAmmoVal) {
							if (WriteProcessMemory(hProcess, (LPVOID)(item.BASE_ITEM + item.WEAPON_AMMO), &lastAmmoVal, sizeof(lastAmmoVal), NULL)) {}
							else {
								std::cout << "\nammo wpm error get code : " << GetLastError();
								return;
							}
						}
						lastAmmoVal = curAmmoVal;
					}
					else {
						std::cout << "\nammo rpm error get code : " << std::dec << GetLastError();
						return;
					}
				}
				lastAddr = usedAddr;
			}
		}
		else {
			std::cout << "\nrpm get static pointer error get code : " << GetLastError();
			return;
		}
		Sleep(25);
	}
}

void unlimitedThrowable(HANDLE hProcess, DWORD baseAddrAPP, pStatic pSt, bool* toggle) {
	uintptr_t usedAddr{ 0x0 }, lastAddr{ 0x0 };
	item_offsets item;
	int rawVal, rawData;
	uint16_t maxVal{ 1 }, cvrtData, cvrtVal;
	while (*toggle) {
		//gettingg the real addresses of weap used
		if (ReadProcessMemory(hProcess, (LPCVOID)(baseAddrAPP + pSt.EQUIPED_WEAPON_STATIC), &usedAddr, sizeof(usedAddr), NULL)) {
			//check if the address are the same as before
			if (usedAddr != 0x0) {//not empty hand
				if (ReadProcessMemory(hProcess, (LPCVOID)usedAddr, &rawData, sizeof(rawData), NULL)) {
					//convert from 4 byte data to 2 byte
					cvrtData = (uint16_t)rawData;
					if (cWeap.at(cvrtData) == 3) { //throwable
						item.BASE_ITEM = usedAddr;
					}
				}
				else {
					std::cout << "\nrpm error get code : " << GetLastError();
					return;
				}
			}
			else {
				if (item.BASE_ITEM != 0x0) {
					if (ReadProcessMemory(hProcess, (LPCVOID)(item.BASE_ITEM + item.VALUE_OF_ITEM), &rawVal, sizeof(rawVal), NULL)) {
						cvrtVal = (uint16_t)rawVal;
						if (rawVal < maxVal) {
							WriteProcessMemory(hProcess, (LPVOID)(item.BASE_ITEM + item.VALUE_OF_ITEM), &maxVal, sizeof(maxVal), NULL);
							WriteProcessMemory(hProcess, (LPVOID)(item.BASE_ITEM + item.VALUE_OF_ITEM + 0x2), &maxVal, sizeof(maxVal), NULL);
						}
					}
					else {
						std::cout << "\nrpm 2 error get code : " << GetLastError();
						return;
					}
				}
			}
		}
		else {
			std::cout << "\nrpm get static pointer error get code : " << GetLastError();
			return;
		}
		Sleep(25);
	}
}