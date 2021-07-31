#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
	double tmp;
	double sum = 0;
	while ( std::cin >> tmp ) {
		sum += tmp;	
	}
	std::cout<< "sum of all is : "<< sum <<std::endl;
	return 0;
}
