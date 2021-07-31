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

int main()
{
    using namespace std;
    vector<int> a {1,23,4,5,6,7,8, 2,23};
    vector<int> b {1,23,4,5,6,7,8};
    list<int> l {1,23,4,5,6,6,7,8};
    int arr[] = {1,23,4,5,6,6,7,8};

    vector<int> vi (std::begin(arr), std::end(arr));
    list<int> li (std::begin(arr), std::end(arr));

    forward_list<int> fi (a.begin(), a.end());

    printContainer("Forward list is : ", fi);
    insertForwardList(fi, 5,111);

    printContainer("After inserting \n Forward list is : ", fi);
    fi.resize(17,17);
    printContainer("After inserting \n Forward list is : ", fi);
    fi.resize(7,17);
    printContainer("After inserting \n Forward list is : ", fi);
}
