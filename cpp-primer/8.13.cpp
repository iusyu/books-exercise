#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

struct PersionInfo{
	std::vector<std::string> phone;
	std::string name;
};

std::ostream& operator<<(std::ostream& out, const PersionInfo& pp)
{
	out << "Name:"<< pp.name << std::endl;
	out << "Phone:\n";
	std::for_each(pp.phone.begin(), pp.phone.end(), [&](auto p){ out<< p << std::endl;});
	return out;
}

int main(int argv, char* argc[] )
{
	using namespace std;
	std::vector<PersionInfo> vpeople;
	ifstream infile { argc[1] };

	std::string tmpLine;
	while( getline(infile, tmpLine) ) {
		istringstream line { tmpLine };
		std::string tmpPhone;
		vector<string> tmpPhones;
		std::string name;
		line >> name;
		while( line >> tmpPhone) {
			tmpPhones.push_back(tmpPhone);
			tmpPhone.clear();
		}

		PersionInfo p;
		p.name = name;
		p.phone = tmpPhones;
		tmpPhones.clear();
		name.clear();
		vpeople.push_back(p);
	}

	for_each(vpeople.begin(), vpeople.end(), [](auto p){ std::cout << p << std::endl; });
	
}
