#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <deque>
#include <algorithm>

template <typename T>
void printContainer(const std::string desc, const T& container)
{
    std::cout <<desc << " Container Have: " << std::endl;
    std::for_each(container.begin(), container.end(), [](auto& p) { std::cout << " "<<p << " "; } );
    std::cout << std::endl;
}


void insertForwardList( std::forward_list<int>& list, int a, int b)
{
	auto itrPre = list.before_begin();
	auto itr = list.begin();
	std::for_each(list.begin(), list.end(), [&](auto& p){ if( p == a ) { list.insert_after(itrPre, b); } itrPre++; });
}

template<typename T>
void insertDiap( T& container)
{
	auto begin = container.begin();
	while( begin != container.end() )
	{
		++begin;
		container.insert(begin, 42);
		++begin;
	}
}

int main()
{
    using namespace std;

    vector<char> vsrc {'a', 'b', 'c', 'd', 'e'};
    string dst ( vsrc.begin(), vsrc.end());
    string reading;
    reading.resize(1000);
    std::cout << " string capacity => " << reading.capacity() << std::endl;
    std::cout << dst << std::endl;

    reading  += "this is line of code to print out, there may be more word to input ";

    std::cout << " string capacity => " << reading.capacity() << std::endl;
    std::cout << " string size     => " << reading.size() << std::endl;
    reading.reserve(reading.size());
    std::cout << reading << std::endl;

    std::cout << " string capacity => " << reading.capacity() << std::endl;
    std::cout << " string size     => " << reading.size() << std::endl;



}
