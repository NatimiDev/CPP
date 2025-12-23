#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string ft_replace(const std::string &content, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return content;

	std::string res;
	size_t pos = 0;
	size_t found;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		res += content.substr(pos, found - pos) + s2;
		pos = found + s1.length();
	}
	res += content.substr(pos);
	return res;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		std::cout << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream input(filename);
	if (!input.is_open())
	{
		std::cout << "Cannot open file " << filename << std::endl;
		return 1;
	}

	std::stringstream buffer;
	buffer << input.rdbuf();
	std::string content = buffer.str();
	input.close();

	std::string content_new = ft_replace(content, s1, s2);

	std::string outfile = filename + ".replace";
	std::ofstream output(outfile);
	if (!output.is_open())
	{
		std::cout << "Cannot create file " << outfile << std::endl;
		return 1;
	}
	output << content_new;
	output.close();

	return 0;
}