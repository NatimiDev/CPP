#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl h;

	if (argc <= 1)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}
	
	std::string lvl = argv[1];
	int logLvl = -1;
	if (lvl == "DEBUG")
		logLvl = 0;
	else if (lvl == "INFO")
		logLvl = 1;
	else if (lvl == "WARNING")
		logLvl = 2;
	else if (lvl == "ERROR")
		logLvl = 3;

	// IMPORTANT: fall-through behaviour
	switch (logLvl)
	{
		case 0:
			h.complain("DEBUG");
		case 1:
			h.complain("INFO");
		case 2:
			h.complain("WARNING");
		case 3:
			h.complain("ERROR");
			break;
		default:
			h.complain("");
	}
	return 0;
}