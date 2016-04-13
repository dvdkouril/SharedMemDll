// SharedMemDll.cpp : Defines the exported functions for the DLL application.
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("MyFileMappingObject");
TCHAR camShMemName[] = TEXT("MayaToUnityCameraInfoSharedMem");
TCHAR sceneInfoShMemName[] = TEXT("MayaToUnitySceneInfoSharedMem");

#include "SharedMemDll.h"

extern "C" {
	void * getSceneObjNumber(HANDLE & _hShMem)
	{
		HANDLE hShMem;
		void * pBuf;

		hShMem = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, sceneInfoShMemName);

		if (hShMem == NULL)
		{
			DWORD err = GetLastError();
			_tprintf(TEXT("Could not open file mapping object (%d).\n"),
				GetLastError());
			return NULL;
		}

		pBuf = MapViewOfFile(hShMem, FILE_MAP_ALL_ACCESS, 0, 0, 0); // this can be actually 0 and then I don't need to send BUF_SIZE from maya to Unity

		_hShMem = hShMem;
		return pBuf;
	}

	void * getCameraInfoFromShMem(HANDLE & _hShMem) // I think this is how you make output parameter in C++, right?
	{
		HANDLE hShMem;
		void * pBuf;

		hShMem = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, camShMemName);

		if (hShMem == NULL)
		{
			DWORD err = GetLastError();
			_tprintf(TEXT("Could not open file mapping object (%d).\n"),
				GetLastError());
			return NULL;
		}

		pBuf = MapViewOfFile(hShMem, FILE_MAP_ALL_ACCESS, 0, 0,	BUF_SIZE); // this can be actually 0 and then I don't need to send BUF_SIZE from maya to Unity
 
		_hShMem = hShMem;
		return pBuf;

	}

	void * prepareSharedMemory(_Out_ HANDLE & _hMapFile)
	{
		HANDLE hMapFile;	// I need to output this
		void* pBuf;		// and this

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
		pBuf = MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			BUF_SIZE); // this can be actually 0 and then I don't need to send BUF_SIZE from maya to Unity


		_hMapFile = hMapFile;
		return pBuf;
	}

	void cleanupSharedMemory(HANDLE hMapFile, LPCVOID pBuf)
	{
		UnmapViewOfFile(pBuf);
		CloseHandle(hMapFile);
	}
}
