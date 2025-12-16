#include <cstring>
#include <iostream>

void uppercase(char *str)
{
    size_t len = std::strlen(str);

	for (size_t i = 0; i < len; i++)
	{
		std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
    }
}

int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	for (int i = 1; i < argc; i++)
	{
		uppercase(argv[i]);
	}
	return 0;
}
