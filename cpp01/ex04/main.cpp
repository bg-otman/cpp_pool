#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

void put_error(const char *msg)
{
	std::cerr << msg << std::endl;
	exit(1);
}

std::string replace_str(std::string& line, const std::string& searchWord, const std::string& replaceWord, int index)
{
	int i;
	std::string new_line;

	new_line = line.substr(0, index);
	new_line.append(replaceWord);
	i = index + searchWord.length();
	new_line.append(line.substr(i));

	return new_line;
}

int main(int ac, char *av[])
{
	if (ac != 4)
		put_error("Invalid args !");

	std::string file_name = av[1];
	file_name.append(".replace");

	std::ifstream in_file(av[1]);
	if (!in_file.is_open())
		put_error("Error opening input file");

	std::ofstream out_file(file_name.c_str());
	if (!out_file.is_open())
	{
		in_file.close();
		put_error("Error opening output file");
	}
	
	std::string buffer;
	size_t index;
	size_t start_pos;

	while (getline(in_file, buffer))
	{
		index = buffer.find(av[2]);
		if (index == std::string::npos)
		{
			out_file << buffer;
			if (!in_file.eof()) out_file << "\n";
		}
		else
        {
            while (index != std::string::npos)
            {
                buffer = replace_str(buffer, av[2], av[3], index);
                start_pos = index + strlen(av[3]);
				index = buffer.find(av[2], start_pos);
            }
            out_file << buffer;
            if (!in_file.eof()) out_file << "\n";
        }
	}
	out_file.close();
	in_file.close();
	return 0;
}
