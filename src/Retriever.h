#include "Instruction.h"
#ifdef WIN32
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

class Retriever {
	vector<string> instructions;
	int memBanks;
	string instrPath, configPath;

	int setPaths(string cPath, string aPath);

	public:

	string rootPath;

	string getRootPath();

	bool loadInstructions(string cPath, string aPath);
	bool loadConfigParams();

	vector<string> getInstructions();
        int getMemBanks();
};