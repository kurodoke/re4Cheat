#ifndef DCLR_H_INCLUDED
#define DCLR_H_INCLUDED

#include <Windows.h>
#include "addressStruct.h"
#include <iostream>

void leonCurHealth(HANDLE hProcess, uintptr_t addr, bool* toggle);
void unlimitedAmmo(HANDLE hProcess, DWORD baseAddrAPP, pStatic pSt, bool* toggle);
void unlimitedThrowable(HANDLE hProcess, DWORD baseAddrAPP, pStatic pSt, bool* toggle);

#endif // !DCLR_H_INCLUDED

