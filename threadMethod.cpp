#include "dclrThread.h"

//method for health (leon)
void leonCurHealth(HANDLE hProcess, uintptr_t addr, bool* toggle) {
	uintptr_t pBuffer{ 0 }, temp{ 0 };
	while (*toggle) {
		temp = pBuffer;
		if (ReadProcessMemory(hProcess, (LPCVOID)addr, &pBuffer, sizeof(uintptr_t), NULL)) {
			if (pBuffer < temp) {
				if (WriteProcessMemory(hProcess, (LPVOID)addr, &temp, sizeof(uintptr_t), NULL)) {}
				else {
					std::cout << "wpm error get code : " << GetLastError();
					return;
				}
			}
		}
		else {
			std::cout << "rpm error get code : " << GetLastError();
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
			if ((usedAddr != lastAddr)) {
				lastAmmoVal = 0; curAmmoVal = 0;
				if (usedAddr != 0x0) {//not empty hand
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
		else {
			std::cout << "\nrpm get static pointer error get code : " << GetLastError();
			return;
		}
		Sleep(25);
	}
}