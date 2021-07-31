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
    vector<int> a {1,23,4,5,6,7,8, 2,23};
    vector<int> b {1,23,4,5,6,7,8};
    vector<int> vl {1,23,4,5,6,6,7,8};
    list<int> l {1,23,4,5,6,6,7,8};
    forward_list<int> fl {1,23,4,5,6,6,7,8};
    int arr[] = {1,23,4,5,6,6,7,8};

    std::cout << "a.capacity() => " << a.capacity() << std::endl;
    printContainer("vector<int> vl => ", vl);
    insertDiap(vl);
    printContainer("vector<int> vl => ", vl);

    printContainer("list<int> l => ",  l);
    insertDiap(l);
    printContainer("list<int>  l => ",  l);

//    printContainer("forward_list<int> fl => ", fl);
 //   insertDiap(fl);
  //  printContainer("forward_list<int> fl => ", fl);




}
