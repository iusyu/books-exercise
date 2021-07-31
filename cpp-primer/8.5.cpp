#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

int main(int argv, char* argc[]) 
{
	std::vector<SaleItem> context;
	for( auto itr = argc + 1; itr != argv + argc; itr++) {
		std::ifstream file { std::string(*itr) };
		std::string word;
		unsigned long num;
		double price;
		while( file >> word >> num >> price ) {

			context.push_back( SaleItem(word, num, price));
		}
	}
	std::for_each(context.begin(), context.end(), [](auto p) { std::cout << p << std::endl; });
}


