#include <iostream>
#include "SZAMAN.hpp"

int main(int argc, char** argv){
    std::string in = "";
	std::string out = "";
	std::string mem = "64k";
	std::string sPos = "0";
	bool showbadcode = false;
	bool beg0 = false;
	for (int i = 0; i < argc; i++)
	{
		if ((std::string(argv[i]) == "-i") && (i + 1 < argc))
		{
			in = argv[i + 1];
		}
		else if ((std::string(argv[i]) == "-o") && (i + 1 < argc))
		{
			out = argv[i + 1];
		}
		else if ((std::string(argv[i]) == "-m") && (i + 1 < argc))
		{
			mem = argv[i + 1];
		}
		else if ((std::string(argv[i]) == "-s") && (i + 1 < argc))
		{
			sPos = argv[i + 1];
		}
		else if (std::string(argv[i]) == "-showbadcode")
		{
			showbadcode = true;
		}
		else if (std::string(argv[i]) == "-alwaysbeginat0")
		{
			beg0 = true;
		}
	}
	if ((in != "") && (out != ""))
		szaman::run(in, out, mem, sPos, showbadcode, beg0);
}
