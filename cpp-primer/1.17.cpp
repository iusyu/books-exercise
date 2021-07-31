#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
	double tmp;
	double last;
	bool first = true;
	double sum = 0;
	while ( std::cin >> tmp ) {
		if( first ){
			last = tmp;
			sum +=  last;
			first = false;
		} else {
			if( last == tmp){
				continue;
			} else {
				last = tmp;
				sum += tmp;	
			}
		}
	}
	std::cout<< "sum of all is : "<< sum <<std::endl;
	return 0;
}
