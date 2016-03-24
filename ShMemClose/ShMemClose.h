// ShMemClose.h
/*
	Contains function that closes the shared memory segment (when we are done with shared reading)
*/

#ifdef SHMEMCLOSE_EXPORTS
#define SHMEMCLOSE_API __declspec(dllexport) 
#else
#define SHMEMCLOSE_API __declspec(dllimport) 
#endif

extern "C" {
	SHMEMCLOSE_API void cleanupSharedMemory(HANDLE hMapFile, LPCTSTR pBuf);
}