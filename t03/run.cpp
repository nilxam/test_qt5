#include <dlfcn.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void fnExit(void)
{
	cout << "Exit program." << endl;
}

int main(int argc, char *argv[])
{
	bool myUI = getenv("DISPLAY") != 0;
	int ret = 0;

	if (myUI) {
		void* handle = dlopen("./libt03.so", RTLD_LAZY);
		if (!handle) {
			cout << "dlopen failed:" << dlerror() << endl;
		}

		typedef int (*runGui_t)(int, char**);

		runGui_t runGui = (runGui_t)dlsym(handle, "runUI");

		const char* dlsym_error = dlerror();

		if (dlsym_error) {
			cout << "dlsym error:" << dlsym_error << endl;
		}

		ret = runGui(argc, argv);
		atexit(fnExit);
		dlclose(handle);
	}

	return ret;
}
