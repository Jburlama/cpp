#include "sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: <file> s1 s2" << std::endl;
		return (0);
	}
	std::string		outfile_name;
	std::string		line;
	std::ofstream	outfile;
	std::ifstream	infile(argv[1]);

	if (infile.is_open())
	{
		outfile_name = argv[1];
		outfile_name.append(".replace");
		outfile.open(outfile_name.c_str());
		
		size_t poss;
		while (getline(infile, line))
		{
			while (42)
			{
				poss = line.find(argv[2]);
				if (poss == std::string::npos)
					break ;
				line.erase(poss, strlen(argv[2]));
				line.insert(poss, argv[3]);
			}
			outfile << line << std::endl;
		}
		infile.close();
		outfile.close();
	}
	else
		std::cout << "Could not open file!" << std::endl;
}
