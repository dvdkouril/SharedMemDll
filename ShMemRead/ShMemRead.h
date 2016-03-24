// ShMemRead.h
/*
	I think this is not even needed. Idea was that the function in this DLL will read the shared memory and return it to C# part for parsing.
*/

#ifdef SHMEMREAD_EXPORTS
#define SHMEMREAD_API __declspec(dllexport) 
#else
#define SHMEMREAD_API __declspec(dllimport) 
#endif

extern "C" {
	SHMEMREAD_API void readSharedMemory(LPCTSTR pBuf);
}