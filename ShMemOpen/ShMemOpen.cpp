// ShMemOpen.cpp :
// 
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

#include "ShMemOpen.h"


extern "C" {
	// void prepareSharedMemory(out hMapFile, out pBuf) <- something like this? how will it work with c#????
	void prepareSharedMemory(_Out_ HANDLE _hMapFile, _Out_ LPCTSTR _pBuf)
	{
		HANDLE hMapFile;	// I need to output this
		LPCTSTR pBuf;		// and this

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


		_hMapFile = hMapFile;
		_pBuf = pBuf;
	}
}