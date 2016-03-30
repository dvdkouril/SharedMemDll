// SharedMemDll.cpp : Defines the exported functions for the DLL application.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("MyFileMappingObject");

#include "SharedMemDll.h"


extern "C" {
	// void prepareSharedMemory(out hMapFile, out pBuf) <- something like this? how will it work with c#????
	//void prepareSharedMemory(_Out_ HANDLE _hMapFile, _Out_ LPCTSTR _pBuf)
	char * prepareSharedMemory(_Out_ HANDLE _hMapFile)
	{
		HANDLE hMapFile;	// I need to output this
		char* pBuf;		// and this

		//MessageBox(NULL, TEXT("Whatup"), TEXT("Process2"), MB_OK);

		hMapFile = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,   // read/write access
			FALSE,                 // do not inherit the name
			szName);               // name of mapping object

		if (hMapFile == NULL)
		{
			DWORD err = GetLastError();
			_tprintf(TEXT("Could not open file mapping object (%d).\n"),
				GetLastError());
			return NULL;
		}

		//pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
		pBuf = (char *)MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			BUF_SIZE);


		_hMapFile = hMapFile;

		return pBuf;
		//_pBuf = (LPCTSTR)pBuf;
	}

	void cleanupSharedMemory(HANDLE hMapFile, LPCTSTR pBuf)
	{
		UnmapViewOfFile(pBuf);

		CloseHandle(hMapFile);
	}

	void readSharedMemory(LPCTSTR pBuf)
	{
		MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
	}
}
