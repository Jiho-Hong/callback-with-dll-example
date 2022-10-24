#include <time.h>

#include "dll.h"

namespace callbackwithdllexample {
	static bool g_isStart = false;

	void(CALLBACK* cbf)(int) = NULL;

	void Start() {
		g_isStart = true;
	}


	void Stop() {
		g_isStart = false;
	}


	static void timer() {
		clock_t start = clock();
		while (g_isStart) {
			if (((clock() - start) / CLOCKS_PER_SEC) % 5 == 0) {
				cbf(((clock() - start) / CLOCKS_PER_SEC));
			}
		}
	}


	void RegistCallback(void(CALLBACK* cb)(int))
	{
		cbf = cb;
		timer();
	}
}
