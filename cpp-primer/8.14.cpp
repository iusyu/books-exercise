#include <iostream>
#include <string>
#include <bitset>
#include <complex>


std::string s {"Hello"};

std::bitset<64> flags(7);

std::complex<double> c {5.12321, 3.14157334};


int main( int argv, char* argc[] )
{
	s += " WO NI NEN DIE";
	std::cout << s << std::endl;
	std::cout << flags << std::endl;
	std::cout << c << std::endl;
	return 0;
}
