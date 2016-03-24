// ShMemClose.cpp : Defines the exported functions for the DLL application.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

#include "ShMemClose.h"

extern "C" {
	void cleanupSharedMemory(HANDLE hMapFile, LPCTSTR pBuf)
	{
		UnmapViewOfFile(pBuf);

		CloseHandle(hMapFile);
	}
}