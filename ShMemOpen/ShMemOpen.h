// ShMemOpen.h
// Contains prepareSharedMemory function which opens a shared memory segment for reading

#ifdef SHMEMOPEN_EXPORTS
#define SHMEMOPEN_API __declspec(dllexport) 
#else
#define SHMEMOPEN_API __declspec(dllimport) 
#endif

extern "C" {
	SHMEMOPEN_API void prepareSharedMemory(_Out_ HANDLE _hMapFile, _Out_ LPCTSTR _pBuf);
}