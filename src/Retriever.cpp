#include "Retriever.h"

int Retriever::setPaths(string cPath, string aPath)
{
	char cur_dir[FILENAME_MAX];

	if (!GetCurrentDir(cur_dir, sizeof(cur_dir)))
	{
		return -1;
	}
	cur_dir[sizeof(cur_dir) - 1] = '\0'; /* not really required */

	rootPath = cur_dir;
	//rootPath = rootPath + "\\..\\sample\\" + __argv[1]; // Comment out this line for running in unix
	
	int slash = rootPath.find_first_of("\\"), backslash = rootPath.find_first_of("/");
	if(slash != (int)string::npos)
		rootPath += "\\";
	else if(backslash != (int)string::npos)
		rootPath += "/";

    if(cPath != "")
		configPath = cPath;
	else
	    configPath = rootPath + "config.dat";
		
	instrPath = aPath;	
	
	return 0;
}

bool Retriever::loadInstructions(string cPath, string aPath)
{	
	setPaths(cPath, aPath);      

	ifstream fin(instrPath.c_str());    
	if(fin.fail())
		return false;

	int s = 0, e = 0;
	char c_line[256];
	while(fin.getline(c_line,255))
	{
		s = 0; e = 0;
		string line(c_line);
		istringstream ss(line.c_str());
		string token;

		if(line[0] == ' ')
			s++;

		if(ss >> token)
		{
			if(token[token.size() - 1] == ':') {
				s += token.size();
				if(line[s] == ' ')
					s++;
			}

			int comment_index = line.find_first_of(";");
			if(comment_index != (int)string::npos)
				e = comment_index - 1;
			else
				e = line.size() - 1;

			while(line[e] == ' ')
				e--;

			line = line.substr(s,e-s+1);
			instructions.push_back(line);
		}		
	}

	return true;
}

bool Retriever::loadConfigParams()
{    
	ifstream fin(configPath.c_str());
	if(fin.fail())
		return false;

	string c_line;

	if(getline(fin, c_line))
	{
		if(c_line == "#Memory Banks") { 
			if(getline(fin, c_line))
				memBanks = atoi(c_line.c_str());       
		}                
	}        
	
	return true;
}

vector<string> Retriever::getInstructions()
{
	return instructions;
}

int Retriever::getMemBanks()
{
    return memBanks;
}

string Retriever::getRootPath()
{
	return rootPath;
}
