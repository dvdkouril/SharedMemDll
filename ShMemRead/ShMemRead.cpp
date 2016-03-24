// ShMemRead.cpp : Defines the exported functions for the DLL application.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

#include "ShMemRead.h"

extern "C" {
	void readSharedMemory(LPCTSTR pBuf)
	{
		MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
	}
}