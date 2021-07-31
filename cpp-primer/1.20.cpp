#include <iostream>
#include <string>

class Sales_item{
public:
	std::string isb;
	unsigned long number;
	double price;
};


int main(int argc, char* argv[] )
{
	std::string tmpIsb;
	unsigned long tmpNumber;
	double tmpPrice;

	while( std::cin >> tmpIsb >> tmpNumber >> tmpPrice) {
		std::cout << "ISB:" << tmpIsb <<std::endl;
		std::cout << "Price per book:" << tmpPrice <<std::endl;
		std::cout << "Sales Counting:" << tmpNumber << std::endl;
	}
}

