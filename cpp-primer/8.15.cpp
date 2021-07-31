#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main( int argv, char* argc[]) 
{
	using namespace std;
	
	fstream f;
	f.exceptions(ios::eofbit | ios::failbit | ios::badbit);
	f.open(argc[1],ios::app | ios::in | ios::out);
	try{
		unsigned line = 0;
		while(true){
			std::string tmpLine;
			getline(f, tmpLine);
			cout << "this is line: "<< line <<std::endl<<tmpLine <<std::endl;
			line++;
		}
	} catch (ios::failure& iosf){
		std::cerr << iosf.what() << std::endl;
	}
}
