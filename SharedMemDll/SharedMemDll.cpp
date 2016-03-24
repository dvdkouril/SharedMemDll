// SharedMemDll.cpp : Defines the exported functions for the DLL application.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

#include "SharedMemDll.h"


extern "C" {
	void load()
	{
		HANDLE hMapFile;
		LPCTSTR pBuf;

		MessageBox(NULL, TEXT("Whatup"), TEXT("Process2"), MB_OK);

		hMapFile = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,   // read/write access
			FALSE,                 // do not inherit the name
			szName);               // name of mapping object

		if (hMapFile == NULL)
		{
			DWORD err = GetLastError();
			_tprintf(TEXT("Could not open file mapping object (%d).\n"),
				GetLastError());
			return;
		}

		pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			BUF_SIZE);

		if (pBuf == NULL)
		{
			_tprintf(TEXT("Could not map view of file (%d).\n"),
				GetLastError());

			CloseHandle(hMapFile);

			return;
		}

		MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);

		UnmapViewOfFile(pBuf);

		CloseHandle(hMapFile);

	}
}

/*// SharedMemDll.cpp : Defines the exported functions for the DLL application.
//

#include "SharedMemDll.h"
#include <iostream>

extern "C" {
	void load() 
	{
		std::cout << "asdfasdfasdf";
		// dummy code for debugging
		int a = 0;
		int b = 1;
		int c = a + b;
	}
}*/