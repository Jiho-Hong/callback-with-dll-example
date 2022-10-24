#pragma once
#include <Windows.h>

#ifdef CALLBACK_WITH_DLL_EXAMPLE_EXPORTS
#define CALLBACK_WITH_DLL_EXAMPLE_API __declspec(dllexport)
#else
#define CALLBACK_WITH_DLL_EXAMPLE_API __declspec(dllimport)
#endif

namespace callbackwithdllexample {
	extern "C" CALLBACK_WITH_DLL_EXAMPLE_API void Start();
	extern "C" CALLBACK_WITH_DLL_EXAMPLE_API void Stop();
	extern "C" CALLBACK_WITH_DLL_EXAMPLE_API void RegistCallback(void(CALLBACK * cb)(int));
}
