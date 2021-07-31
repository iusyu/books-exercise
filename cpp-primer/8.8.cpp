#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


class SaleItem{
public:
	SaleItem(std::string& nn, unsigned long nm, double pp):isb(nn), number(nm), price(pp) { }

	std::string isb;
	unsigned long number;
	double price;
};

std::ostream& operator<<(std::ostream& out, const SaleItem& book)
{
	out << "Book ISB : "<< book.isb << "  Sale Number : " << book.number << std::endl;
	return out << "Price : " << book.price << std::endl;
}

int main(int argv, char* argc[] )
{
	std::ifstream infile { argc[1] };
	std::ofstream outfile { argc[2], std::ofstream::app };

	std::string tmpLine;
	while( ! infile.eof() ){
		std::getline(infile, tmpLine);
		outfile << tmpLine;
		std::cout << "reading .... \n "<< tmpLine << std::endl;
		tmpLine.clear();
	}
		
}

