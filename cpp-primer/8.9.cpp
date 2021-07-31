#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


int main( int argv, char *argc[] )
{
	using namespace std;

	string tmpLine;
	ifstream infile { argc[1] };
	vector<string> vline;
	while( getline(infile, tmpLine ) ) {
		vline.push_back(tmpLine);
		tmpLine.clear();
	}

	for( auto itr = vline.begin(); itr != vline.end(); itr++) {
		istringstream line { *itr };
		std::string tmpWord;
		while( line >> tmpWord ){
			std::cout <<"This is word:" << tmpWord << std::endl;
		}
	}
}
