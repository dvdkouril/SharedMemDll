// SharedMemDll.cpp : Defines the exported functions for the DLL application.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256

#include "SharedMemDll.h"

extern "C" {

	void * getSharedMemoryPtr(HANDLE & _hShMem, LPCWSTR sharedMemoryName)
	{
		HANDLE hShMem;
		void * pBuf;

		hShMem = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, sharedMemoryName);

		if (hShMem == NULL)
		{
			DWORD err = GetLastError();
			_tprintf(TEXT("Could not open file mapping object (%d).\n"),
				GetLastError());
			return NULL;
		}

		pBuf = MapViewOfFile(hShMem, FILE_MAP_ALL_ACCESS, 0, 0, 0); 

		_hShMem = hShMem;
		return pBuf;
	}

	void cleanupSharedMemory(HANDLE hMapFile, LPCVOID pBuf)
	{
		UnmapViewOfFile(pBuf);
		CloseHandle(hMapFile);
	}

}
