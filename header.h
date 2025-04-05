#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#ifdef _WIN32
	// Set the console to expect codepage 65001 = UTF-8.
    const int setting_utf8 = std::system("chcp 65001 >nul");
#endif