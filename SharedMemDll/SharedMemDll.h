// SharedMemDll.h
/*
	This is just a testing class that I created when I was trying out DLL importing into Unity. it's based on this tutorial:
	http://ericeastwood.com/blog/17/unity-and-dlls-c-managed-and-c-unmanaged
*/

#ifdef SHAREDMEMDLL_EXPORTS
#define SHAREDMEMDLL_API __declspec(dllexport) 
#else
#define SHAREDMEMDLL_API __declspec(dllimport) 
#endif

extern "C" {
	SHAREDMEMDLL_API void load();
}