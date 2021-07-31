#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argv, char* argc[]) 
{
	std::vector<std::string> context;
	for( auto itr = argc + 1; itr != argv + argc; itr++) {
		std::ifstream file { std::string(*itr) };
		while( !file.eof() ) {
			std::string tmpLine;
			std::getline(file,tmpLine);
			context.push_back(tmpLine);
		}
	}
	std::for_each(context.begin(), context.end(), [](auto p) { std::cout << p << std::endl; });
}
