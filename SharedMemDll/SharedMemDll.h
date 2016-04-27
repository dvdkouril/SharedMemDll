// SharedMemDll.h
/*
	This is DLL that is imported into Unity and implements shared memory reading.
	It's based on this tutorial:
	http://ericeastwood.com/blog/17/unity-and-dlls-c-managed-and-c-unmanaged
*/

#ifdef SHAREDMEMDLL_EXPORTS
#define SHAREDMEMDLL_API __declspec(dllexport) 
#else
#define SHAREDMEMDLL_API __declspec(dllimport) 
#endif

extern "C" {
	SHAREDMEMDLL_API void * getSharedMemoryPtr(_Out_ HANDLE & _hShMem, LPCWSTR sharedMemoryName);
	SHAREDMEMDLL_API void cleanupSharedMemory(HANDLE hMapFile, LPCVOID pBuf);
}